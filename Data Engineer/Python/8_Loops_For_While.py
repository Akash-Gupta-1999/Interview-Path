"""
=== LOOPS: FOR AND WHILE ===
Topics Covered:
- For Loops with Ranges
- Iterating through Collections
- While Loops
- Break, Continue, and Else
- Nested Loops
"""

# ============ FOR LOOPS ============

# Basic for loop with range
for i in range(5):
    print(i)  # 0, 1, 2, 3, 4

# Range with start and stop
for i in range(1, 5):
    print(i)  # 1, 2, 3, 4

# Range with step
for i in range(0, 10, 2):
    print(i)  # 0, 2, 4, 6, 8

# Reverse range
for i in range(5, 0, -1):
    print(i)  # 5, 4, 3, 2, 1

# ============ ITERATING THROUGH COLLECTIONS ============

# Iterating through strings
text = "Python"
for char in text:
    print(char)

# Iterating through lists
fruits = ["apple", "banana", "cherry"]
for fruit in fruits:
    print(fruit)

# With index using enumerate
for index, fruit in enumerate(fruits):
    print(f"{index}: {fruit}")

# Starting enumeration from 1
for index, fruit in enumerate(fruits, start=1):
    print(f"{index}: {fruit}")

# Iterating through dictionaries
person = {"name": "Alice", "age": 30, "city": "NYC"}

for key in person:
    print(f"{key}: {person[key]}")

for key, value in person.items():
    print(f"{key}: {value}")

for value in person.values():
    print(value)

# ============ WHILE LOOPS ============

# Basic while loop
count = 0
while count < 5:
    print(count)
    count += 1

# While with condition
user_input = ""
while user_input != "quit":
    user_input = input("Enter 'quit' to exit: ")
    print(f"You entered: {user_input}")

# ============ BREAK STATEMENT ============
# Exit loop immediately

for i in range(10):
    if i == 5:
        break  # Exit at 5
    print(i)  # 0, 1, 2, 3, 4

# Searching in a list
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
target = 5
for num in numbers:
    if num == target:
        print(f"Found {target}")
        break

# ============ CONTINUE STATEMENT ============
# Skip current iteration

for i in range(10):
    if i % 2 == 0:
        continue  # Skip even numbers
    print(i)  # 1, 3, 5, 7, 9

# ============ PASS STATEMENT ============
# Does nothing, used as a placeholder

for i in range(5):
    pass  # Placeholder, loop does nothing

# ============ ELSE CLAUSE WITH LOOPS ============
# Executes if loop completes normally (without break)

# For-else
for i in range(5):
    if i == 10:
        break
else:
    print("Loop completed without break")  # This prints

# For-else with break
for i in range(10):
    if i == 5:
        break
else:
    print("This won't print")  # Doesn't print because of break

# While-else
count = 0
while count < 5:
    if count == 10:
        break
    count += 1
else:
    print("While loop completed")

# ============ NESTED LOOPS ============

# Nested for loops
for i in range(3):
    for j in range(3):
        print(f"({i}, {j})", end=" ")
    print()

# Printing multiplication table
for i in range(1, 4):
    for j in range(1, 4):
        print(f"{i}*{j}={i*j}", end="  ")
    print()

# Creating a matrix
matrix = []
for i in range(3):
    row = []
    for j in range(3):
        row.append(i * j)
    matrix.append(row)

# Better with list comprehension
matrix = [[i*j for j in range(3)] for i in range(3)]

# ============ LOOP CONTROL PATTERNS ============

# Early exit pattern
def find_value(items, target):
    for item in items:
        if item == target:
            return True
    return False

# Accumulation pattern
total = 0
for num in [1, 2, 3, 4, 5]:
    total += num

# Filtering pattern
evens = []
for num in range(10):
    if num % 2 == 0:
        evens.append(num)

# Better with list comprehension
evens = [num for num in range(10) if num % 2 == 0]