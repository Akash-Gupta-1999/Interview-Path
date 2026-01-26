"""
=== INTRODUCTION TO PYTHON ===
Topics Covered:
- What is Python
- Python Features and Use Cases
- Setting up Python Environment
- First Program and Print Statements
- Comments and Docstrings
"""

# ============ COMMENTS AND DOCSTRINGS ============
# This is a single-line comment

"""
This is a multi-line comment or docstring.
Used for explaining functions, classes, and modules
"""

# ============ BASIC PRINT STATEMENTS ============
print("Hello, World!")
print("Welcome to Python Learning")
print()  # Empty line

# Using multiple arguments
print("Python", "is", "awesome")

# Using sep and end parameters
# here instead of new line at end it will print "!" at end
print("2024", "2025", sep="-", end="!")

# ============ PYTHON BASICS ============
# Python is dynamically typed - no need to declare types
# Python uses indentation for code blocks
# Python is case-sensitive

# ============ TAKING INPUT IN PYTHON ============
# Using input() function to read from user
user_name = input("Enter your name: ")
user_age = input("Enter your age: ")

# input() returns a string, convert if needed
print(f"Hello {user_name}, you are {user_age} years old")

# Converting input to specific types
age = int(input("Enter your age as number: "))
height = float(input("Enter your height in meters: "))
print(f"Age: {age}, Height: {height}")

# Basic output
name = "Python"
version = 3.12
print(f"Learning {name} version {version}")