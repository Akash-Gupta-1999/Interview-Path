"""
=== DECORATORS ===
Topics Covered:
- Function Decorators
- Decorating Functions with Parameters
- Decorating Classes
- Built-in Decorators (@property, @staticmethod, @classmethod)
- Multiple Decorators
"""

# ============ BASIC DECORATORS ============

# A decorator is a function that modifies another function or class

def simple_decorator(func):
    """A simple decorator"""
    def wrapper():
        print("Before function call")
        func()
        print("After function call")
    return wrapper

@simple_decorator
def say_hello():
    print("Hello!")

say_hello()
# Output:
# Before function call
# Hello!
# After function call

# Equivalent to:
# say_hello = simple_decorator(say_hello)

# ============ DECORATORS WITH PARAMETERS ============

def decorator_with_args(func):
    """Decorator that preserves function arguments"""
    def wrapper(*args, **kwargs):
        print(f"Calling {func.__name__} with args={args}, kwargs={kwargs}")
        result = func(*args, **kwargs)
        print(f"Result: {result}")
        return result
    return wrapper

@decorator_with_args
def add(a, b):
    return a + b

add(5, 3)

# ============ PRESERVING FUNCTION METADATA ============

from functools import wraps

def better_decorator(func):
    """Decorator that preserves function metadata"""
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Calling {func.__name__}")
        return func(*args, **kwargs)
    return wrapper

@better_decorator
def multiply(a, b):
    """Multiply two numbers"""
    return a * b

print(multiply.__name__)      # multiply (preserved)
print(multiply.__doc__)       # Multiply two numbers

# ============ DECORATOR WITH PARAMETERS ============

def repeat(times):
    """Decorator that repeats function execution"""
    def decorator(func):
        @wraps(func)
        def wrapper(*args, **kwargs):
            results = []
            for _ in range(times):
                results.append(func(*args, **kwargs))
            return results
        return wrapper
    return decorator

@repeat(3)
def greet(name):
    return f"Hello, {name}!"

print(greet("Alice"))
# ['Hello, Alice!', 'Hello, Alice!', 'Hello, Alice!']

# ============ TIMING DECORATOR ============

import time

def timer(func):
    """Decorator to measure execution time"""
    @wraps(func)
    def wrapper(*args, **kwargs):
        start = time.time()
        result = func(*args, **kwargs)
        end = time.time()
        print(f"{func.__name__} took {end - start:.4f} seconds")
        return result
    return wrapper

@timer
def slow_function():
    time.sleep(0.5)
    return "Done"

slow_function()

# ============ LOGGING DECORATOR ============

def logger(func):
    """Decorator to log function calls"""
    @wraps(func)
    def wrapper(*args, **kwargs):
        print(f"Calling {func.__name__}")
        print(f"  Arguments: {args}")
        print(f"  Keyword arguments: {kwargs}")
        result = func(*args, **kwargs)
        print(f"  Returned: {result}")
        return result
    return wrapper

@logger
def greet(name, age):
    return f"{name} is {age} years old"

greet("Alice", 30)

# ============ VALIDATION DECORATOR ============

def validate_positive(func):
    """Decorator to validate positive numbers"""
    @wraps(func)
    def wrapper(a, b):
        if a < 0 or b < 0:
            raise ValueError("Arguments must be positive")
        return func(a, b)
    return wrapper

@validate_positive
def divide(a, b):
    if b == 0:
        raise ValueError("Cannot divide by zero")
    return a / b

print(divide(10, 2))  # 5.0
# divide(-10, 2)  # Raises ValueError

# ============ CLASS DECORATORS ============

def class_decorator(cls):
    """Decorator for classes"""
    cls.decorated = True
    return cls

@class_decorator
class MyClass:
    pass

print(MyClass.decorated)  # True

# Adding methods to class
def add_repr(cls):
    """Decorator to add __repr__ to class"""
    def __repr__(self):
        attrs = ", ".join(f"{k}={v}" for k, v in self.__dict__.items())
        return f"{cls.__name__}({attrs})"
    cls.__repr__ = __repr__
    return cls

@add_repr
class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

person = Person("Alice", 30)
print(person)  # Person(name=Alice, age=30)

# ============ MULTIPLE DECORATORS ============

@timer
@logger
def multi_decorated_function(x):
    return x ** 2

# Decorators are applied bottom-to-top
# Equivalent to: timer(logger(multi_decorated_function))

# ============ STACKING DECORATORS ============

@repeat(2)
@logger
def stacked_function():
    return "Result"

# Executes: repeat(logger(stacked_function))

# ============ PROPERTY DECORATOR ============

class Circle:
    def __init__(self, radius):
        self._radius = radius
    
    @property
    def radius(self):
        """Get radius"""
        return self._radius
    
    @radius.setter
    def radius(self, value):
        """Set radius with validation"""
        if value < 0:
            raise ValueError("Radius must be positive")
        self._radius = value
    
    @property
    def area(self):
        """Calculate area"""
        return 3.14159 * self._radius ** 2

# Using property decorator
circle = Circle(5)
print(circle.radius)     # 5
print(circle.area)       # 78.53975
circle.radius = 10       # Uses setter
print(circle.area)       # 314.159

# ============ STATICMETHOD AND CLASSMETHOD ============

class Math:
    PI = 3.14159
    
    @staticmethod
    def add(a, b):
        """Static method doesn't need instance"""
        return a + b
    
    @classmethod
    def from_string(cls, num_string):
        """Class method receives class as first argument"""
        return float(num_string)

# Using static method
print(Math.add(5, 3))  # 8

# Using class method
value = Math.from_string("3.14")
print(value)  # 3.14

# ============ PRACTICAL EXAMPLE: CACHE DECORATOR ============

def cache(func):
    """Decorator to cache function results"""
    results = {}
    
    @wraps(func)
    def wrapper(n):
        if n not in results:
            results[n] = func(n)
        return results[n]
    
    return wrapper

@cache
def fibonacci(n):
    """Calculate fibonacci number (cached)"""
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

print(fibonacci(10))  # Much faster with caching