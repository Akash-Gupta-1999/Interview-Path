"""
=== LISTS AND LIST OPERATIONS ===
Topics Covered:
- List Creation and Indexing
- List Slicing
- List Methods (add, remove, modify)
- List Comprehensions
- Iterating through Lists
"""

# ============ LIST CREATION ============
empty_list = []
numbers = [1, 2, 3, 4, 5]
mixed = [1, "hello", 3.14, True, None]
nested = [1, [2, 3], [4, 5, 6]]

# Using list() constructor
from_string = list("ABC")  # ['A', 'B', 'C']
from_range = list(range(5))  # [0, 1, 2, 3, 4]

# ============ LIST INDEXING AND SLICING ============
fruits = ["apple", "banana", "cherry", "date", "elderberry"]

# Positive indexing
fruits[0]    # "apple"
fruits[2]    # "cherry"

# Negative indexing
fruits[-1]   # "elderberry"
fruits[-2]   # "date"

# Slicing
fruits[1:3]      # ["banana", "cherry"]
fruits[:3]       # ["apple", "banana", "cherry"]
fruits[2:]       # ["cherry", "date", "elderberry"]
fruits[::2]      # ["apple", "cherry", "elderberry"]
fruits[::-1]     # Reversed list

# ============ LIST METHODS ============

# append() - Add single element
numbers = [1, 2, 3]
numbers.append(4)  # [1, 2, 3, 4]

# extend() - Add multiple elements
numbers.extend([5, 6, 7])  # [1, 2, 3, 4, 5, 6, 7]

# insert() - Add at specific position
numbers.insert(0, 0)  # [0, 1, 2, 3, 4, 5, 6, 7]

# remove() - Remove first occurrence
numbers.remove(3)  # [0, 1, 2, 4, 5, 6, 7]

# pop() - Remove and return element
last = numbers.pop()     # Returns 7
at_index = numbers.pop(0)  # Returns 0

# clear() - Remove all elements
copy_list = [1, 2, 3]
copy_list.clear()  # []

# index() - Find first occurrence
fruits = ["apple", "banana", "cherry"]
fruits.index("banana")  # 1

# count() - Count occurrences
numbers = [1, 2, 2, 3, 2, 4]
numbers.count(2)  # 3

# sort() - Sort in place
numbers = [3, 1, 4, 1, 5]
numbers.sort()  # [1, 1, 3, 4, 5]
numbers.sort(reverse=True)  # [5, 4, 3, 1, 1]

# sorted() - Return sorted list (doesn't modify original)
original = [3, 1, 4, 1, 5]
sorted_list = sorted(original)

# reverse() - Reverse in place
numbers = [1, 2, 3, 4, 5]
numbers.reverse()  # [5, 4, 3, 2, 1]

# copy() - Create shallow copy
original = [1, 2, 3]
copied = original.copy()
copied.append(4)
# original is still [1, 2, 3]

# ============ LIST COMPREHENSIONS ============

# Basic syntax: [expression for item in iterable]
squares = [x**2 for x in range(6)]  # [0, 1, 4, 9, 16, 25]

# With condition
evens = [x for x in range(10) if x % 2 == 0]  # [0, 2, 4, 6, 8]

# With transformation
words = ["apple", "banana", "cherry"]
upper_words = [word.upper() for word in words]

# Nested comprehension
matrix = [[i*j for j in range(3)] for i in range(3)] # [[0, 0, 0], [0, 1, 2], [0, 2, 4]]

# ============ ITERATING THROUGH LISTS ============

fruits = ["apple", "banana", "cherry"]

# Basic for loop
for fruit in fruits:
    print(fruit)

# With index
for i, fruit in enumerate(fruits):
    print(f"{i}: {fruit}")

# While loop
i = 0
while i < len(fruits):
    print(fruits[i])
    i += 1

# List unpacking
first, second, third = fruits