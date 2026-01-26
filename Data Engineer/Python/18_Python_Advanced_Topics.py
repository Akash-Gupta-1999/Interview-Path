"""
=== ADVANCED PYTHON TOPICS ===
Topics Covered:
- Context Managers (with statement)
- Type Hints and Type Checking
- Collections Module
- Iterators and Iterables
- Magic Methods
- Slots
"""

# ============ CONTEXT MANAGERS ============

# Context managers help manage resources (file, database, etc.)

# Using built-in context manager (file)
with open("example.txt", "r") as file:
    content = file.read()
# File is automatically closed

# Creating custom context manager
class DatabaseConnection:
    def __init__(self, db_name):
        self.db_name = db_name
    
    def __enter__(self):
        print(f"Connecting to {self.db_name}")
        return self
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        print(f"Disconnecting from {self.db_name}")
    
    def execute(self, query):
        print(f"Executing: {query}")
        return []

# Using custom context manager
with DatabaseConnection("mydb") as db:
    db.execute("SELECT * FROM users")
# Connection automatically closed

# Context manager with decorator
from contextlib import contextmanager

@contextmanager
def my_context():
    print("Entering context")
    try:
        yield  # Code between with statement runs here
    finally:
        print("Exiting context")

with my_context():
    print("Inside context")

# ============ TYPE HINTS ============

# Basic type hints
def add(x: int, y: int) -> int:
    return x + y

# Multiple types
def process(value: int | str) -> None:
    print(value)

# Collections with type hints
from typing import List, Dict, Tuple, Set, Optional

def process_list(items: List[int]) -> int:
    return sum(items)

def create_mapping(keys: List[str], values: List[int]) -> Dict[str, int]:
    return dict(zip(keys, values))

def get_pair() -> Tuple[int, str]:
    return (1, "hello")

# Optional type (can be None)
def get_user(user_id: int) -> Optional[Dict[str, str]]:
    if user_id > 0:
        return {"id": str(user_id), "name": "Alice"}
    return None

# Union types
from typing import Union

def process_value(value: Union[int, str, float]) -> str:
    return str(value)

# Generic types
from typing import TypeVar, Generic

T = TypeVar('T')

class Box(Generic[T]):
    def __init__(self, item: T):
        self.item = item
    
    def get(self) -> T:
        return self.item

# Using generic class
int_box: Box[int] = Box(42)
str_box: Box[str] = Box("hello")

# ============ COLLECTIONS MODULE ============

from collections import Counter, defaultdict, OrderedDict, namedtuple

# Counter - Count occurrences
words = "apple banana apple cherry banana apple"
word_count = Counter(words.split())
print(word_count)  # Counter({'apple': 3, 'banana': 2, 'cherry': 1})
print(word_count.most_common(2))  # [('apple', 3), ('banana', 2)]

# defaultdict - Default values
from collections import defaultdict
dd = defaultdict(list)
dd["key1"].append("value1")
print(dd)  # defaultdict(<class 'list'>, {'key1': ['value1']})

# Named tuples
Point = namedtuple('Point', ['x', 'y'])
p = Point(10, 20)
print(p.x, p.y)  # 10 20

Person = namedtuple('Person', ['name', 'age', 'city'])
alice = Person("Alice", 30, "NYC")
print(alice)  # Person(name='Alice', age=30, city='NYC')

# ============ ITERATORS AND ITERABLES ============

# Iterable - object that has __iter__()
# Iterator - object that has __iter__() and __next__()

class CountUp:
    def __init__(self, max):
        self.max = max
        self.current = 0
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.current < self.max:
            self.current += 1
            return self.current
        else:
            raise StopIteration

# Using iterator
counter = CountUp(3)
for num in counter:
    print(num)  # 1, 2, 3

# iter() and next()
numbers = [1, 2, 3]
iterator = iter(numbers)
print(next(iterator))  # 1
print(next(iterator))  # 2
print(next(iterator))  # 3
# next(iterator)  # StopIteration

# ============ MAGIC METHODS ============

class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height
    
    # String representation
    def __str__(self):
        return f"Rectangle({self.width}x{self.height})"
    
    def __repr__(self):
        return f"Rectangle(width={self.width}, height={self.height})"
    
    # Comparison
    def __eq__(self, other):
        return self.width == other.width and self.height == other.height
    
    def __lt__(self, other):
        return self.area() < other.area()
    
    # Arithmetic
    def __add__(self, other):
        return Rectangle(self.width + other.width, self.height + other.height)
    
    def __sub__(self, other):
        return Rectangle(self.width - other.width, self.height - other.height)
    
    def __mul__(self, scalar):
        return Rectangle(self.width * scalar, self.height * scalar)
    
    # Length and item access
    def __len__(self):
        return 2
    
    def __getitem__(self, index):
        return [self.width, self.height][index]
    
    # Callable
    def __call__(self):
        return self.area()
    
    # Iteration
    def __iter__(self):
        return iter([self.width, self.height])
    
    # Integer conversion
    def __int__(self):
        return int(self.area())
    
    def area(self):
        return self.width * self.height

# Using magic methods
rect1 = Rectangle(5, 4)
rect2 = Rectangle(3, 2)

print(str(rect1))        # Rectangle(5x4)
print(rect1 == rect2)    # False
print(rect1 + rect2)     # Rectangle(8x6)
print(rect1 * 2)         # Rectangle(10x8)
print(rect1[0], rect1[1]) # 5 4
print(rect1())           # 20 (area)

# ============ SLOTS ============

# __slots__ restricts attributes and saves memory

class PersonWithSlots:
    __slots__ = ['name', 'age']
    
    def __init__(self, name, age):
        self.name = name
        self.age = age

person = PersonWithSlots("Alice", 30)
print(person.name)       # Alice
# person.city = "NYC"  # AttributeError - not in slots

# Without slots (allows any attribute)
class PersonNoSlots:
    def __init__(self, name, age):
        self.name = name
        self.age = age

person2 = PersonNoSlots("Bob", 25)
person2.city = "NYC"  # Works fine

# ============ METACLASSES ============

# Metaclass - class of a class

class Meta(type):
    def __new__(mcs, name, bases, dct):
        print(f"Creating class {name}")
        return super().__new__(mcs, name, bases, dct)

class MyClass(metaclass=Meta):
    pass  # Creating class MyClass

# ============ DESCRIPTORS ============

class Descriptor:
    def __get__(self, obj, objtype=None):
        print(f"Getting value")
        return getattr(obj, '_value', None)
    
    def __set__(self, obj, value):
        print(f"Setting value to {value}")
        obj._value = value

class MyData:
    value = Descriptor()

data = MyData()
data.value = 10  # Setting value to 10
print(data.value)  # Getting value