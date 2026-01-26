"""
=== LAMBDA AND FUNCTIONAL PROGRAMMING ===
Topics Covered:
- Lambda Functions
- map(), filter(), reduce()
- Functional Programming Concepts
- Higher-Order Functions
"""

# ============ LAMBDA FUNCTIONS ============

# Basic lambda: lambda arguments: expression

# Simple lambda
square = lambda x: x ** 2
print(square(5))  # 25

# Lambda with multiple arguments
add = lambda x, y: x + y
print(add(3, 5))  # 8

# Lambda with condition
is_even = lambda x: x % 2 == 0
print(is_even(4))  # True

# Lambda with multiple conditions
is_valid = lambda x: 0 <= x <= 100
print(is_valid(50))  # True

# ============ MAP() ============

# map(function, iterable) - applies function to each item

numbers = [1, 2, 3, 4, 5]

# Using lambda with map
squared = list(map(lambda x: x ** 2, numbers))
print(squared)  # [1, 4, 9, 16, 25]

# Equivalent to list comprehension
squared = [x ** 2 for x in numbers]

# map with multiple iterables
a = [1, 2, 3]
b = [4, 5, 6]
sums = list(map(lambda x, y: x + y, a, b))
print(sums)  # [5, 7, 9]

# map with function
def celsius_to_fahrenheit(celsius):
    return (celsius * 9/5) + 32

temps_c = [0, 10, 20, 30]
temps_f = list(map(celsius_to_fahrenheit, temps_c))
print(temps_f)  # [32.0, 50.0, 68.0, 86.0]

# ============ FILTER() ============

# filter(function, iterable) - keeps items where function returns True

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# Using lambda with filter
evens = list(filter(lambda x: x % 2 == 0, numbers))
print(evens)  # [2, 4, 6, 8, 10]

# Equivalent to list comprehension
evens = [x for x in numbers if x % 2 == 0]

# filter with function
def is_positive(x):
    return x > 0

numbers = [-5, -2, 0, 3, 7]
positive = list(filter(is_positive, numbers))
print(positive)  # [3, 7]

# Chaining filter and map
numbers = [1, 2, 3, 4, 5, 6]
result = list(map(lambda x: x ** 2, filter(lambda x: x % 2 == 0, numbers)))
print(result)  # [4, 16, 36]

# ============ REDUCE() ============

from functools import reduce

# reduce(function, iterable) - accumulates result

numbers = [1, 2, 3, 4, 5]

# Calculate sum
total = reduce(lambda x, y: x + y, numbers)
print(total)  # 15

# Calculate product
product = reduce(lambda x, y: x * y, numbers)
print(product)  # 120

# Find maximum
maximum = reduce(lambda x, y: x if x > y else y, numbers)
print(maximum)  # 5

# With initial value
total = reduce(lambda x, y: x + y, numbers, 10)
print(total)  # 25 (10 + sum of numbers)

# ============ HIGHER-ORDER FUNCTIONS ============

def apply_operation(func, a, b):
    """Function that takes another function as argument"""
    return func(a, b)

# Using higher-order function
print(apply_operation(lambda x, y: x + y, 5, 3))      # 8
print(apply_operation(lambda x, y: x * y, 5, 3))      # 15
print(apply_operation(lambda x, y: x ** y, 2, 3))     # 8

# Function that returns a function
def create_multiplier(factor):
    """Returns a function"""
    return lambda x: x * factor

double = create_multiplier(2)
triple = create_multiplier(3)

print(double(5))  # 10
print(triple(5))  # 15

# ============ SORTED WITH KEY ============

# Sort using lambda

students = [
    {"name": "Alice", "score": 85},
    {"name": "Bob", "score": 92},
    {"name": "Charlie", "score": 78}
]

# Sort by score
sorted_students = sorted(students, key=lambda x: x["score"], reverse=True)
print(sorted_students)

# Sort strings by length
words = ["apple", "pie", "banana", "cat"]
sorted_words = sorted(words, key=lambda x: len(x))
print(sorted_words)  # ['pie', 'cat', 'apple', 'banana']

# ============ FUNCTIONAL PROGRAMMING PATTERNS ============

# Composition: combining functions
def compose(f, g):
    """Compose two functions: (f ∘ g)(x) = f(g(x))"""
    return lambda x: f(g(x))

add_one = lambda x: x + 1
double = lambda x: x * 2

# (x + 1) * 2
add_then_double = compose(double, add_one)
print(add_then_double(5))  # 12 = (5 + 1) * 2

# Pipeline: applying multiple functions in sequence
def pipeline(*functions):
    """Apply functions in sequence"""
    def apply(value):
        for func in functions:
            value = func(value)
        return value
    return apply

square = lambda x: x ** 2
add_ten = lambda x: x + 10
multiply_two = lambda x: x * 2

process = pipeline(square, add_ten, multiply_two)
print(process(3))  # ((3**2) + 10) * 2 = 38

# ============ PRACTICAL EXAMPLES ============

# Example 1: Data transformation
data = [
    {"name": "Alice", "salary": 50000, "dept": "IT"},
    {"name": "Bob", "salary": 60000, "dept": "HR"},
    {"name": "Charlie", "salary": 55000, "dept": "IT"}
]

# Get names of IT department employees with salary > 52000
result = list(map(
    lambda x: x["name"],
    filter(lambda x: x["dept"] == "IT" and x["salary"] > 52000, data)
))
print(result)  # ['Alice', 'Charlie']

# Example 2: Nested data processing
grades = [[85, 90, 88], [92, 95, 89], [78, 82, 81]]

# Calculate average for each student
averages = list(map(lambda grades: sum(grades) / len(grades), grades))
print(averages)  # [87.66..., 92.0, 80.33...]

# Example 3: Chaining operations
numbers = range(1, 11)
result = reduce(
    lambda x, y: x + y,
    filter(lambda x: x % 2 == 0, map(lambda x: x ** 2, numbers))
)
print(result)  # Sum of squares of even numbers