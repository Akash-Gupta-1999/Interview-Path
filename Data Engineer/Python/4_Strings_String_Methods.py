"""
=== STRINGS AND STRING METHODS ===
Topics Covered:
- String Creation and Indexing
- String Slicing
- String Methods
- String Formatting
- Escape Sequences
"""

# ============ STRING CREATION ============
single_quote = 'Hello'
double_quote = "World"
triple_quote = '''Multi-line
string using
triple quotes'''

# ============ STRING INDEXING ============
text = "Python"
print(text[0])   # P
print(text[-1])  # n
print(text[-2])  # o

# ============ STRING SLICING ============
text = "Hello World"
print(text[0:5])      # "Hello"
print(text[6:])       # "World"
print(text[:5])       # "Hello"
print(text[::2])      # "HloWrd" (every 2nd character)
print(text[::-1])     # "dlroW olleH" (reverse)

# ============ STRING PROPERTIES ============
text = "Python"
print(len(text))      # 6
print(text.upper())   # PYTHON
print(text.lower())   # python
print(text.capitalize())  # Python

# ============ STRING METHODS ============
text = "  Hello World  "

# Whitespace operations
text.strip()     # "Hello World"
text.lstrip()    # "Hello World  "
text.rstrip()    # "  Hello World"

# Search and replace
text = "Hello World"
text.find("World")       # 6
text.index("World")      # 6
text.count("l")          # 3
text.replace("World", "Python")  # "Hello Python"

# Split and join
text = "apple,banana,cherry"
fruits = text.split(",")  # ['apple', 'banana', 'cherry']
"-".join(fruits)  # 'apple-banana-cherry'

# Case checking
text = "hello"
text.islower()    # True
text.isupper()    # False
text.isdigit()    # False
text.isalpha()    # True
text.isalnum()    # True

# Starts and ends with
text = "Hello World"
text.startswith("Hello")  # True
text.endswith("World")    # True

# ============ STRING FORMATTING ============

# f-strings (modern approach)
name = "Alice"
age = 30
formatted = f"My name is {name} and I am {age} years old"

# Using expressions in f-strings
price = 19.99
quantity = 3
print(f"Total: ${price * quantity:.2f}")

# .format() method
formatted = "Hello {} and {}".format("Alice", "Bob")
formatted = "Hello {0} and {1}".format("Alice", "Bob")
formatted = "Hello {name}".format(name="Alice")

# % formatting (older)
formatted = "Hello %s, you are %d years old" % ("Alice", 30)

# ============ ESCAPE SEQUENCES ============
print("Hello\nWorld")    # Newline
print("Hello\tWorld")    # Tab
print("Hello\\World")    # Backslash
print("He said \"Hi\"")  # Double quote
print("C:\\path\\to\\file")  # Raw string: r"C:\path\to\file"