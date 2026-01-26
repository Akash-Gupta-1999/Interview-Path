"""
=== MODULES AND PACKAGES ===
Topics Covered:
- Importing Modules
- Creating Custom Modules
- Packages
- __name__ == '__main__'
- Standard Library Overview
- Third-Party Libraries
"""

# ============ IMPORTING MODULES ============

# Import entire module
import math
print(math.pi)
print(math.sqrt(16))

# Import specific items
from math import pi, sqrt
print(pi)
print(sqrt(25))

# Import with alias
import numpy as np
from datetime import datetime as dt

# Import all items (not recommended)
# from math import *

# ============ BUILT-IN MODULES ============

# sys module
import sys
print(sys.version)
print(sys.platform)

# os module
import os
print(os.getcwd())
print(os.listdir("."))

# datetime module
from datetime import datetime, timedelta
now = datetime.now()
print(now)

yesterday = now - timedelta(days=1)
print(yesterday)

# random module
import random
print(random.randint(1, 100))
print(random.choice(["apple", "banana", "cherry"]))
print(random.shuffle([1, 2, 3, 4, 5]))

# collections module
from collections import Counter, defaultdict
word_count = Counter(['a', 'b', 'a', 'c', 'a', 'b'])
print(word_count)  # Counter({'a': 3, 'b': 2, 'c': 1})

# itertools module
from itertools import combinations, permutations
items = [1, 2, 3]
print(list(combinations(items, 2)))

# ============ CREATING CUSTOM MODULE ============

# File: calculator.py
# def add(a, b):
#     return a + b
# 
# def subtract(a, b):
#     return a - b
# 
# def multiply(a, b):
#     return a * b

# Using the custom module
# import calculator
# print(calculator.add(5, 3))
# print(calculator.multiply(4, 7))

# Alternative: from calculator import add, subtract
# print(add(10, 5))

# ============ __NAME__ == '__MAIN__' ============

# In calculator.py:
# def add(a, b):
#     return a + b
# 
# if __name__ == "__main__":
#     # This runs only when script is run directly
#     print(add(5, 3))
#     # Won't run if imported as module

# ============ PACKAGES ============

# Directory structure:
# mypackage/
#   __init__.py
#   module1.py
#   module2.py
#   subpackage/
#     __init__.py
#     module3.py

# File: mypackage/__init__.py (can be empty)
# Indicates directory is a package

# Importing from package
# from mypackage import module1
# from mypackage.module1 import function1
# from mypackage.subpackage import module3

# ============ COMMON STANDARD LIBRARY MODULES ============

# string - String operations
import string
print(string.ascii_letters)
print(string.digits)

# json - JSON handling
import json
data = {"name": "Alice", "age": 30}
json_string = json.dumps(data)
parsed = json.loads(json_string)

# csv - CSV file handling
import csv
# with open("file.csv") as f:
#     reader = csv.reader(f)
#     for row in reader:
#         print(row)

# re - Regular expressions
import re
pattern = r"\d+"
text = "Phone: 123-456-7890"
numbers = re.findall(pattern, text)
print(numbers)  # ['123', '456', '7890']

# pathlib - Path operations
from pathlib import Path
p = Path("./data/file.txt")
print(p.name)      # file.txt
print(p.parent)    # data

# functools - Functional programming
from functools import reduce
numbers = [1, 2, 3, 4, 5]
product = reduce(lambda x, y: x * y, numbers)
print(product)  # 120

# defaultdict - Default values for dictionary
from collections import defaultdict
dd = defaultdict(list)
dd["key1"].append("value1")
print(dd)

# ============ THIRD-PARTY LIBRARIES ============

# Installing packages: pip install package_name

# Popular third-party libraries:

# requests - HTTP library
# import requests
# response = requests.get("https://api.example.com/data")
# data = response.json()

# pandas - Data analysis
# import pandas as pd
# df = pd.read_csv("file.csv")
# print(df.head())

# numpy - Numerical computing
# import numpy as np
# arr = np.array([1, 2, 3, 4, 5])
# print(np.mean(arr))

# matplotlib - Plotting
# import matplotlib.pyplot as plt
# plt.plot([1, 2, 3], [1, 4, 9])
# plt.show()

# ============ PRACTICAL EXAMPLE ============

# File: math_operations.py
class Calculator:
    @staticmethod
    def add(a, b):
        return a + b
    
    @staticmethod
    def subtract(a, b):
        return a - b
    
    @staticmethod
    def multiply(a, b):
        return a * b
    
    @staticmethod
    def divide(a, b):
        if b == 0:
            raise ValueError("Cannot divide by zero")
        return a / b

if __name__ == "__main__":
    # Test when run directly
    calc = Calculator()
    print(calc.add(10, 5))
    print(calc.divide(20, 4))