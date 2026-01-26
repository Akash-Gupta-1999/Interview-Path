"""
=== TUPLES, SETS, AND DICTIONARIES ===
Topics Covered:
- Tuples (immutable sequences) - O(1) for access, O(n) for search
- Sets (unique unordered collections) - O(1) for add, remove, and check membership
- Dictionaries (key-value pairs) - O(1) for access, add, and remove
- Operations and Methods
"""
"""
# ===== OVERVIEW =====
List
Underlying DS: Dynamic Array
Ordered: Yes
Mutable: Yes
Duplicates: Allowed
Access: O(1)
Insert/Delete (middle): O(n)
👉 Use when order matters and data changes

🔒 Tuple
Underlying DS: Array (immutable)
Ordered: Yes
Mutable: No
Hashable: Yes
👉 Use for fixed data, safe keys, return values

🧺 Set
Underlying DS: Hash Table
Ordered: No
Unique values only
Lookup: O(1) avg
👉 Use for uniqueness & fast membership checks

🗺️ Dictionary
Underlying DS: Hash Table
Key–Value mapping
Keys must be immutable
Lookup/Insert: O(1) avg
Insertion order preserved (Py 3.7+)
👉 Use for fast lookups & mappings
"""
# ============ TUPLES ============
# Immutable ordered sequences

# Creation

empty_tuple = ()
single_element = (1,)  # Comma is required
multi_element = (1, 2, 3)
mixed = (1, "hello", 3.14, True)
nested = (1, (2, 3), (4, 5))

# Without parentheses
tuple_implicit = 1, 2, 3  # (1, 2, 3)

# Indexing and slicing (same as lists)
numbers = (10, 20, 30, 40, 50)
numbers[0]    # 10
numbers[1:3]  # (20, 30)

# Tuple methods
numbers = (1, 2, 2, 3, 2, 4)
numbers.count(2)   # 3
numbers.index(3)   # 3

# Unpacking
a, b, c = (1, 2, 3)
first, *middle, last = (1, 2, 3, 4, 5)  # first=1, middle=[2,3,4], last=5

# Advantages: immutable, hashable, faster than lists
coordinates = (10, 20)
location = {coordinates: "office"}  # Can use as dictionary key

# ============ SETS ============
# Unordered collections of unique elements

# Creation
empty_set = set()  # Note: {} creates empty dict, not set
numbers = {1, 2, 3, 4, 5}
fruits = {"apple", "banana", "cherry"}
from_list = set([1, 2, 2, 3, 3, 4])  # {1, 2, 3, 4}

# Add and remove
numbers = {1, 2, 3}
numbers.add(4)          # {1, 2, 3, 4}
numbers.remove(2)       # {1, 3, 4} - Raises error if not found
numbers.discard(10)     # No error if not found

# Pop and clear
numbers = {1, 2, 3}
removed = numbers.pop()  # Removes arbitrary element
numbers.clear()          # Empty set

# Set operations
set1 = {1, 2, 3, 4}
set2 = {3, 4, 5, 6}

union = set1 | set2           # {1, 2, 3, 4, 5, 6}
intersection = set1 & set2    # {3, 4}
difference = set1 - set2      # {1, 2}
symmetric_diff = set1 ^ set2  # {1, 2, 5, 6}

# Alternative methods
union = set1.union(set2)
intersection = set1.intersection(set2)

# Membership
1 in set1    # True
10 in set1   # False

# ============ DICTIONARIES ============
# Mutable unordered key-value pairs

# Creation
empty_dict = {}
person = {
    "name": "Alice",
    "age": 30,
    "city": "New York"
}

# Using dict() constructor
person = dict(name="Alice", age=30, city="New York")

# Accessing values
person["name"]           # "Alice"
person.get("age")        # 30
person.get("email", "N/A")  # "N/A" (default if key not found)

# Adding and updating
person["email"] = "alice@example.com"  # Add new key-value
person["age"] = 31                      # Update existing

# Removing items
del person["email"]
removed = person.pop("age")
person.popitem()  # Remove last inserted

# Dictionary methods
person = {"name": "Alice", "age": 30, "city": "New York"}

person.keys()      # dict_keys(['name', 'age', 'city'])
person.values()    # dict_values(['Alice', 30, 'New York'])
person.items()     # dict_items([('name', 'Alice'), ('age', 30), ...])

# Iteration
for key in person:
    print(f"{key}: {person[key]}")

for key, value in person.items():
    print(f"{key}: {value}")

# Checking existence
"name" in person      # True
"email" in person     # False

# Copy
person_copy = person.copy()
deep_copy = person.copy()  # Shallow copy for simple values

# Merge dictionaries (Python 3.9+)
dict1 = {"a": 1, "b": 2}
dict2 = {"c": 3, "d": 4}
merged = {**dict1, **dict2}  # {"a": 1, "b": 2, "c": 3, "d": 4}
merged = dict1 | dict2  # Python 3.9+

# Nested dictionaries
company = {
    "name": "TechCorp",
    "employees": {
        "alice": {"age": 30, "dept": "Engineering"},
        "bob": {"age": 28, "dept": "Sales"}
    }
}
company["employees"]["alice"]["age"]  # 30