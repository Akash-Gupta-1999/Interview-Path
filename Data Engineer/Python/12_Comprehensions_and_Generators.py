"""
=== COMPREHENSIONS AND GENERATORS ===
Topics Covered:
- List Comprehensions
- Set Comprehensions
- Dictionary Comprehensions
- Generator Expressions
- Generators with yield
"""

# ============ LIST COMPREHENSIONS ============

# Basic syntax: [expression for item in iterable]
squares = [x**2 for x in range(6)]
# [0, 1, 4, 9, 16, 25]

# With condition: [expression for item in iterable if condition]
evens = [x for x in range(10) if x % 2 == 0]
# [0, 2, 4, 6, 8]

# With transformation
words = ["hello", "world", "python"]
upper_words = [word.upper() for word in words]
# ["HELLO", "WORLD", "PYTHON"]

# Nested list comprehension
matrix = [[i*j for j in range(3)] for i in range(3)]
# [[0, 0, 0], [0, 1, 2], [0, 2, 4]]

# With if-else
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9]
result = ["even" if x % 2 == 0 else "odd" for x in numbers]
# ["odd", "even", "odd", "even", "odd", "even", "odd", "even", "odd"]

# Multiple conditions
result = [x for x in range(20) if x % 2 == 0 if x % 3 == 0]
# [0, 6, 12, 18]

# Flattening a list
nested = [[1, 2], [3, 4], [5, 6]]
flattened = [num for sublist in nested for num in sublist]
# [1, 2, 3, 4, 5, 6]

# ============ SET COMPREHENSIONS ============

# Basic syntax: {expression for item in iterable}
unique_squares = {x**2 for x in [1, 2, 2, 3, 3, 3]}
# {1, 4, 9}

# With condition
even_squares = {x**2 for x in range(10) if x % 2 == 0}
# {0, 4, 16, 36, 64}

# ============ DICTIONARY COMPREHENSIONS ============

# Basic syntax: {key: value for item in iterable}
squares_dict = {x: x**2 for x in range(5)}
# {0: 0, 1: 1, 2: 4, 3: 9, 4: 16}

# With condition
even_squares_dict = {x: x**2 for x in range(10) if x % 2 == 0}
# {0: 0, 2: 4, 4: 16, 6: 36, 8: 64}

# From list of tuples
pairs = [("a", 1), ("b", 2), ("c", 3)]
dict_from_pairs = {k: v for k, v in pairs}
# {"a": 1, "b": 2, "c": 3}

# Swapping keys and values
original = {"a": 1, "b": 2, "c": 3}
swapped = {v: k for k, v in original.items()}
# {1: "a", 2: "b", 3: "c"}

# Grouping by condition
numbers = range(10)
grouped = {
    "even": [x for x in numbers if x % 2 == 0],
    "odd": [x for x in numbers if x % 2 != 0]
}

# ============ GENERATOR EXPRESSIONS ============

# Syntax similar to list comprehension but with ()
# Returns generator object (lazy evaluation)

# List comprehension (creates full list in memory)
list_comp = [x**2 for x in range(1000000)]

# Generator expression (creates items on demand)
gen_exp = (x**2 for x in range(1000000))

# Iterate through generator
for value in gen_exp:
    if value > 100:
        break

# Convert generator to list
squares = list(x**2 for x in range(5))
# [0, 1, 4, 9, 16]

# Generator with condition
even_gen = (x for x in range(20) if x % 2 == 0)
for num in even_gen:
    print(num)

# ============ GENERATORS WITH YIELD ============

# Generator function: function with yield statement
def count_up_to(n):
    """Generator that yields numbers from 1 to n"""
    i = 1
    while i <= n:
        yield i
        i += 1

# Using generator function
for num in count_up_to(5):
    print(num)  # 1, 2, 3, 4, 5

# Generator object
gen = count_up_to(3)
next(gen)  # 1
next(gen)  # 2
next(gen)  # 3
# next(gen)  # Raises StopIteration

# Generator with multiple yields
def fibonacci(n):
    """Generator for Fibonacci sequence"""
    a, b = 0, 1
    count = 0
    while count < n:
        yield a
        a, b = b, a + b
        count += 1

# Using Fibonacci generator
for num in fibonacci(6):
    print(num)  # 0, 1, 1, 2, 3, 5

# Generator with initialization and cleanup
def file_reader(filename):
    """Generator that reads file line by line"""
    file = open(filename)
    try:
        for line in file:
            yield line.strip()
    finally:
        file.close()

# Using file generator
# for line in file_reader("data.txt"):
#     process(line)

# ============ GENERATOR METHODS ============

def interactive_generator():
    """Generator that can receive values"""
    value = None
    while True:
        value = (yield value)
        if value is not None:
            value = value * 2

# Using send() method
gen = interactive_generator()
next(gen)  # Start generator
print(gen.send(5))  # 10
print(gen.send(7))  # 14

# ============ PRACTICAL EXAMPLES ============

# Example 1: Process large files
def read_large_file(file_path):
    """Memory-efficient file reading"""
    with open(file_path) as f:
        for line in f:
            yield line.strip()

# Usage: processes one line at a time
# for line in read_large_file("huge_file.txt"):
#     process(line)

# Example 2: Generate infinite sequence
def infinite_counter():
    """Generate infinite sequence"""
    count = 0
    while True:
        yield count
        count += 1

# Usage: take first n items
counter = infinite_counter()
first_5 = [next(counter) for _ in range(5)]

# Example 3: Lazy evaluation
def get_data():
    """Simulates expensive data fetching"""
    data = []
    for i in range(1000000):
        # Expensive operation
        data.append(i ** 2)
    return data

def get_data_lazy():
    """Same as above but lazy"""
    for i in range(1000000):
        yield i ** 2

# get_data() loads everything into memory
# get_data_lazy() generates on demand