"""
=== OBJECT-ORIENTED PROGRAMMING (OOP) ===
Topics Covered:
- Classes and Objects
- Attributes and Methods
- __init__ Constructor
- Instance vs Class Variables
- Inheritance
- Polymorphism
- Encapsulation
- Special Methods (__str__, __repr__, etc.)
"""

# ============ BASIC CLASS AND OBJECT ============

class Person:
    """A class to represent a person"""
    
    def __init__(self, name, age):
        """Constructor"""
        self.name = name
        self.age = age
    
    def greet(self):
        """Instance method"""
        return f"Hello, I'm {self.name}"
    
    def have_birthday(self):
        """Instance method to increment age"""
        self.age += 1

# Creating objects (instances)
person1 = Person("Alice", 30)
person2 = Person("Bob", 25)

# Accessing attributes
print(person1.name)      # Alice
print(person2.age)       # 25

# Calling methods
print(person1.greet())   # Hello, I'm Alice

# Modifying attributes
person1.age = 31
person1.have_birthday()
print(person1.age)       # 32

# ============ CONSTRUCTOR (__init__) ============

class Car:
    def __init__(self, brand, model, year):
        self.brand = brand
        self.model = model
        self.year = year
        self.speed = 0  # Default value

# Create car
car = Car("Toyota", "Camry", 2020)
print(f"{car.year} {car.brand} {car.model}")

# ============ INSTANCE VS CLASS VARIABLES ============

class Student:
    # Class variable (shared by all instances)
    school = "Lincoln High"
    total_students = 0
    
    def __init__(self, name, grade):
        # Instance variables (unique to each instance)
        self.name = name
        self.grade = grade
        Student.total_students += 1
    
    def display_info(self):
        # Can access both instance and class variables
        return f"{self.name} in grade {self.grade} at {self.school}"

# Create instances
student1 = Student("Alice", 10)
student2 = Student("Bob", 11)

# Accessing class variable
print(Student.school)          # Lincoln High
print(Student.total_students)  # 2

# Accessing instance variables
print(student1.name)           # Alice

# Modifying class variable
Student.school = "Washington High"

# ============ METHODS ============

class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.balance = balance
    
    # Instance method
    def deposit(self, amount):
        """Add money to account"""
        self.balance += amount
        return f"Deposited ${amount}"
    
    def withdraw(self, amount):
        """Remove money from account"""
        if amount > self.balance:
            return "Insufficient funds"
        self.balance -= amount
        return f"Withdrew ${amount}"
    
    # Class method
    # @classmethod operates on the class itself using cls, and is commonly used for alternative constructors and managing class-level data.
    @classmethod
    def from_string(cls, account_string):
        """Create account from string format"""
        owner, balance = account_string.split(",")
        return cls(owner, float(balance))
    
    # Static method
    @staticmethod
    def is_valid_amount(amount):
        """Check if amount is valid"""
        return amount > 0

# Using instance methods
account = BankAccount("Alice", 1000)
print(account.deposit(500))     # Deposited $500
print(account.withdraw(200))    # Withdrew $200

# Using class method
account2 = BankAccount.from_string("Bob,2000")

# Using static method
print(BankAccount.is_valid_amount(100))  # True
print(BankAccount.is_valid_amount(-50))  # False

# ============ SPECIAL METHODS ============

class Book:
    def __init__(self, title, author, pages):
        self.title = title
        self.author = author
        self.pages = pages
    
    # String representation for developers
    def __repr__(self):
        return f"Book('{self.title}', '{self.author}', {self.pages})"
    
    # String representation for users
    def __str__(self):
        return f"'{self.title}' by {self.author}"
    
    # Less than comparison
    def __lt__(self, other):
        return self.pages < other.pages
    
    # Equality comparison
    def __eq__(self, other):
        return self.title == other.title and self.author == other.author
    
    # Length
    def __len__(self):
        return self.pages
    
    # Item access
    def __getitem__(self, index):
        if index == 0:
            return self.title
        elif index == 1:
            return self.author
        elif index == 2:
            return self.pages
    
    # String representation
    def __add__(self, other):
        return f"{self.title} and {other.title}"

# Using special methods
book1 = Book("1984", "George Orwell", 328)
book2 = Book("Python", "John Doe", 450)

print(str(book1))              # '1984' by George Orwell
print(repr(book1))             # Book('1984', 'George Orwell', 328)
print(len(book1))              # 328
print(book1[0])                # 1984
print(book1 < book2)           # True (328 < 450)
print(book1 + book2)           # 1984 and Python

# ============ INHERITANCE ============

# Base class
class Animal:
    def __init__(self, name):
        self.name = name
    
    def speak(self):
        return f"{self.name} makes a sound"

# Derived class
class Dog(Animal):
    def speak(self):
        return f"{self.name} barks"

class Cat(Animal):
    def speak(self):
        return f"{self.name} meows"

# Using inheritance
dog = Dog("Buddy")
cat = Cat("Whiskers")

print(dog.speak())  # Buddy barks
print(cat.speak())  # Whiskers meows

# ============ SUPER() ============

class Vehicle:
    def __init__(self, brand):
        self.brand = brand
    
    def display_info(self):
        return f"Brand: {self.brand}"

class Motorcycle(Vehicle):
    def __init__(self, brand, wheels=2):
        super().__init__(brand)  # Call parent constructor
        self.wheels = wheels
    
    def display_info(self):
        parent_info = super().display_info()
        return f"{parent_info}, Wheels: {self.wheels}"

# Using super()
bike = Motorcycle("Harley")
print(bike.display_info())

# ============ MULTIPLE INHERITANCE ============

class Flyer:
    def fly(self):
        return "Flying..."

class Swimmer:
    def swim(self):
        return "Swimming..."

class Duck(Flyer, Swimmer):
    def quack(self):
        return "Quack!"

# Using multiple inheritance
duck = Duck()
print(duck.fly())      # Flying...
print(duck.swim())     # Swimming...
print(duck.quack())    # Quack!

# Method Resolution Order (MRO)
print(Duck.__mro__)

# ============ ENCAPSULATION ============

class BankAccountPrivate:
    def __init__(self, owner, balance):
        self.owner = owner
        self.__balance = balance  # Private attribute (name mangling)
    
    def deposit(self, amount):
        if amount > 0:
            self.__balance += amount
    
    def get_balance(self):
        return self.__balance

# Using encapsulation
account = BankAccountPrivate("Alice", 1000)
print(account.get_balance())  # 1000
account.deposit(500)
print(account.get_balance())  # 1500

# Private attribute (name mangling)
# account.__balance  # AttributeError
print(account._BankAccountPrivate__balance)  # 1500 (but not recommended)

# ============ ABSTRACT CLASSES ============
# object can't be created of base class and whoever inherits the base must implement all abstract functions
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass
    
    @abstractmethod
    def perimeter(self):
        pass

class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def perimeter(self):
        return 2 * (self.width + self.height)

# Using abstract class
rect = Rectangle(5, 4)
print(rect.area())       # 20
print(rect.perimeter())  # 18

# ============ PRACTICAL EXAMPLE ============

class Employee:
    """Employee management system"""
    company = "TechCorp"
    employee_count = 0
    
    def __init__(self, name, position, salary):
        self.name = name
        self.position = position
        self.salary = salary
        Employee.employee_count += 1
    
    def give_raise(self, amount):
        self.salary += amount
    
    def __str__(self):
        return f"{self.name} - {self.position} (${self.salary})"
    
    @classmethod
    def get_company_name(cls):
        return cls.company

# Create employees
emp1 = Employee("Alice", "Engineer", 100000)
emp2 = Employee("Bob", "Manager", 120000)

print(emp1)  # Alice - Engineer ($100000)
print(Employee.get_company_name())  # TechCorp
print(Employee.employee_count)  # 2