"""
=== FUNCTIONS AND SCOPE ===
Topics Covered:
- Function Definition and Calling
- Parameters and Arguments
- Return Values
- Default and Keyword Arguments
- *args and **kwargs
- Scope and Global/Local Variables
- Docstrings
"""

# ============ BASIC FUNCTIONS ============

def greet():
    print("Hello!")

greet()  # Call function

# Function with parameters
def greet_person(name):
    print(f"Hello, {name}!")

greet_person("Alice")

# Function with multiple parameters
def add(a, b):
    result = a + b
    return result

sum_result = add(5, 3)
print(sum_result)  # 8

# ============ RETURN STATEMENTS ============

def get_absolute(num):
    if num < 0:
        return -num
    else:
        return num

# Multiple return values (returns tuple)
def get_min_max(numbers):
    return min(numbers), max(numbers)

minimum, maximum = get_min_max([1, 5, 3, 9, 2])

# Early return
def is_valid_email(email):
    if not email:
        return False
    if "@" not in email:
        return False
    return True

# ============ DEFAULT PARAMETERS ============

def greet_default(name, greeting="Hello"):
    return f"{greeting}, {name}!"

print(greet_default("Alice"))           # "Hello, Alice!"
print(greet_default("Bob", "Hi"))       # "Hi, Bob!"

# Multiple defaults
def create_user(name, age=18, country="USA"):
    return f"{name}, {age}, {country}"

# ============ KEYWORD ARGUMENTS ============

def create_profile(name, age, city):
    return f"{name} is {age} and lives in {city}"

# Positional arguments
create_profile("Alice", 30, "NYC")

# Keyword arguments
create_profile(age=30, name="Alice", city="NYC")

# Mix positional and keyword
create_profile("Alice", city="NYC", age=30)

# ============ *ARGS (VARIABLE POSITIONAL ARGUMENTS) ============
# Allows variable number of positional arguments

def sum_all(*args):
    total = 0
    for num in args:
        total += num
    return total

print(sum_all(1, 2, 3, 4, 5))  # 15

def print_items(*items):
    for item in items:
        print(item)

print_items("a", "b", "c")

# ============ **KWARGS (VARIABLE KEYWORD ARGUMENTS) ============
# Allows variable number of keyword arguments

def print_info(**kwargs):
    for key, value in kwargs.items():
        print(f"{key}: {value}")

print_info(name="Alice", age=30, city="NYC")

# ============ COMBINING *ARGS AND **KWARGS ============

def flexible_function(name, *args, **kwargs):
    print(f"Name: {name}")
    print(f"Args: {args}")
    print(f"Kwargs: {kwargs}")

flexible_function("Alice", 1, 2, 3, city="NYC", age=30)

# ============ SCOPE ============

# Global scope
global_var = "I'm global"

def function1():
    print(global_var)  # Can access global

function1()

# Local scope
def function2():
    local_var = "I'm local"
    print(local_var)

function2()
# print(local_var)  # Error: local_var is not defined

# Modifying global variable
counter = 0

def increment():
    global counter  # Declare using global
    counter += 1

increment()
print(counter)  # 1

# Nonlocal for nested functions
def outer():
    value = 10
    
    def inner():
        nonlocal value  # Access outer's variable
        value += 5
    
    inner()
    print(value)  # 15

outer()

# ============ DOCSTRINGS ============

def calculate_area(length, width):
    """
    Calculate the area of a rectangle.
    
    Args:
        length (float): Length of the rectangle
        width (float): Width of the rectangle
    
    Returns:
        float: The area of the rectangle
    
    Example:
        >>> calculate_area(5, 3)
        15
    """
    return length * width

# Access docstring
print(calculate_area.__doc__)

# ============ TYPE HINTS (ANNOTATIONS) ============

def add_typed(a: int, b: int) -> int:
    """Add two integers and return the sum."""
    return a + b

def greet_typed(name: str) -> str:
    """Greet a person by name."""
    return f"Hello, {name}!"

def process_items(items: list) -> dict:
    """Process a list of items."""
    return {"count": len(items), "items": items}

# ============ PRACTICAL EXAMPLES ============

# Example 1: Validation function
def validate_username(username: str) -> tuple[bool, str]:
    """Validate username and return (is_valid, message)."""
    if len(username) < 3:
        return False, "Username must be at least 3 characters"
    if not username.isalnum():
        return False, "Username must be alphanumeric"
    return True, "Valid username"

# Example 2: Processing function
def process_numbers(*numbers: int, operation: str = "sum") -> int:
    """Process numbers with specified operation."""
    if operation == "sum":
        return sum(numbers)
    elif operation == "product":
        result = 1
        for num in numbers:
            result *= num
        return result