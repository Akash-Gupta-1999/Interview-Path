"""
=== VARIABLES AND DATA TYPES ===
Topics Covered:
- Variables and Naming Conventions
- Data Types: int, float, str, bool, NoneType
- Type Checking and Type Conversion
- Multiple Assignment
- Constants
"""

# ============ VARIABLE BASICS ============
# Variables: containers for storing data values
# No need to declare type - Python infers it

# Integer
age = 25
count = -100
big_number = 1_000_000  # Underscores improve readability in large numbers (Python 3.6+). They're ignored by Python's parser, so 1_000_000 equals 1000000. Useful for currency, IDs, and other large numeric values.

# Float
price = 19.99
pi = 3.14159
scientific = 2.5e-3

# String
name = "Alice"
message = 'Hello World'
multiline = """This is a
multiline string"""

# Boolean
is_active = True
is_deleted = False

# None Type
empty_value = None

print(f"Age: {age}, Type: {type(age)}")
print(f"Price: {price}, Type: {type(price)}")
print(f"Name: {name}, Type: {type(name)}")
print(f"Active: {is_active}, Type: {type(is_active)}")

# ============ NAMING CONVENTIONS ============
# snake_case for variables and functions
user_name = "John"
student_age = 20

# UPPER_CASE for constants
MAX_ATTEMPTS = 3
PI = 3.14159

# ============ TYPE CONVERSION ============
# Convert int to float
num_int = 42
num_float = float(num_int)

# Convert float to int (truncates decimal)
num_float = 3.9
num_int = int(num_float)

# Convert to string
value = 100
string_value = str(value)

# Convert to boolean
bool(0)      # False
bool(1)      # True
bool("")     # False
bool("text") # True
bool([])     # False
bool([1])    # True

# Complex numbers
complex_num = 3 + 4j
print(f"Complex: {complex_num}, Type: {type(complex_num)}")
print(f"Real part: {complex_num.real}, Imaginary part: {complex_num.imag}")

# ============ MULTIPLE ASSIGNMENT ============
a, b, c = 1, 2, 3
x = y = z = 0  # Same value to multiple variables

# Unpacking
first, second, third = "ABC"
print(first, second, third)

# ============ TYPE CHECKING ============
print(type(42))
print(type(3.14))
print(isinstance(age, int))
isinstance("hello", str)