"""
=== ERROR HANDLING AND EXCEPTIONS ===
Topics Covered:
- Try-Except Blocks
- Exception Types
- Multiple Except Blocks
- Finally Clause
- Raising Exceptions
- Custom Exceptions
"""

# ============ BASIC TRY-EXCEPT ============

try:
    result = 10 / 2
    print(result)  # 5.0
except ZeroDivisionError:
    print("Cannot divide by zero!")

try:
    result = 10 / 0
except ZeroDivisionError:
    print("Cannot divide by zero!")

# ============ MULTIPLE EXCEPT BLOCKS ============

try:
    # Risky operations
    numbers = [1, 2, 3]
    value = numbers[10]  # IndexError
    result = 10 / 0  # ZeroDivisionError
except IndexError:
    print("Index out of range")
except ZeroDivisionError:
    print("Cannot divide by zero")

# Order matters: catch specific exceptions before general ones
try:
    value = int("abc")  # ValueError
except ValueError as e:
    print(f"Invalid value: {e}")
except Exception as e:
    print(f"Some error occurred: {e}")

# ============ EXCEPTION VARIABLE ============

try:
    file = open("nonexistent.txt", "r")
except FileNotFoundError as e:
    print(f"Error: {e}")
    print(f"Filename: {e.filename}")

# ============ CATCHING MULTIPLE EXCEPTIONS ============

try:
    data = {"key": "value"}
    value = data[10]  # KeyError
except (KeyError, IndexError) as e:
    print(f"Key or Index not found: {e}")

# ============ GENERIC EXCEPTION ============
# Catch any exception (not recommended for production)

try:
    value = 10 / 0
except Exception as e:
    print(f"An error occurred: {type(e).__name__} - {e}")

# ============ FINALLY CLAUSE ============
# Executes regardless of whether exception occurred

try:
    file = open("data.txt", "r")
    content = file.read()
except FileNotFoundError:
    print("File not found")
finally:
    file.close()  # Always closes file

# Better approach: using context manager (with statement)
try:
    with open("data.txt", "r") as file:
        content = file.read()
except FileNotFoundError:
    print("File not found")
# File automatically closed

# ============ RAISING EXCEPTIONS ============

def validate_age(age):
    if age < 0:
        raise ValueError("Age cannot be negative")
    if age > 150:
        raise ValueError("Age seems unrealistic")
    return True

try:
    validate_age(-5)
except ValueError as e:
    print(f"Invalid age: {e}")

# ============ CUSTOM EXCEPTIONS ============

class InsufficientFundsError(Exception):
    """Raised when account balance is insufficient"""
    pass

class InvalidAccountError(Exception):
    """Raised when account is invalid"""
    pass

# Using custom exceptions
class BankAccount:
    def __init__(self, balance):
        self.balance = balance
    
    def withdraw(self, amount):
        if self.balance < amount:
            raise InsufficientFundsError(f"Need ${amount}, have ${self.balance}")
        self.balance -= amount
    
    def validate(self):
        if self.balance < 0:
            raise InvalidAccountError("Balance cannot be negative")

# Using it
try:
    account = BankAccount(100)
    account.withdraw(150)
except InsufficientFundsError as e:
    print(f"Withdrawal failed: {e}")

# ============ ELSE CLAUSE WITH TRY-EXCEPT ============
# Executes if no exception occurred

try:
    number = int("10")
except ValueError:
    print("Invalid input")
else:
    print(f"Successfully converted: {number}")

# Practical example
try:
    with open("data.txt", "r") as file:
        data = file.read()
except FileNotFoundError:
    print("File not found")
else:
    print(f"File read successfully, length: {len(data)}")

# ============ COMMON EXCEPTIONS ============

# ValueError: Invalid value
try:
    int("not a number")
except ValueError:
    print("Invalid value")

# TypeError: Wrong type
try:
    result = "5" + 3  # Can't add string and int
except TypeError:
    print("Type mismatch")

# KeyError: Dictionary key not found
try:
    data = {"name": "Alice"}
    age = data["age"]
except KeyError:
    print("Key not found")

# IndexError: List index out of range
try:
    items = [1, 2, 3]
    value = items[10]
except IndexError:
    print("Index out of range")

# FileNotFoundError: File doesn't exist
try:
    with open("missing.txt", "r") as f:
        content = f.read()
except FileNotFoundError:
    print("File not found")

# AttributeError: Object has no attribute
try:
    text = "hello"
    text.invalid_method()
except AttributeError:
    print("Attribute not found")

# ============ PRACTICAL EXAMPLE ============

def safe_divide(a, b):
    """Safely divide two numbers with error handling."""
    try:
        result = a / b
        return result
    except ZeroDivisionError:
        print("Cannot divide by zero. Returning 0.")
        return 0
    except TypeError:
        print("Both inputs must be numbers")
        return None
    finally:
        print("Division attempt completed")

# Test
print(safe_divide(10, 2))    # 5.0
print(safe_divide(10, 0))    # 0
print(safe_divide("10", 2))  # None