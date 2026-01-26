"""
=== OPERATORS AND EXPRESSIONS ===
Topics Covered:
- Arithmetic Operators
- Comparison Operators
- Logical Operators
- Assignment Operators
- Identity and Membership Operators
- Operator Precedence
"""

# ============ ARITHMETIC OPERATORS ============
a = 10
b = 3

print(f"Addition: {a + b}")        # 13
print(f"Subtraction: {a - b}")     # 7
print(f"Multiplication: {a * b}")  # 30
print(f"Division: {a / b}")        # 3.333...
print(f"Floor Division: {a // b}") # 3
print(f"Modulus: {a % b}")         # 1
print(f"Exponentiation: {a ** b}") # 1000

# ============ COMPARISON OPERATORS ============
x = 5
y = 10

x == y  # False (equal)
x != y  # True (not equal)
x < y   # True (less than)
x <= y  # True (less than or equal)
x > y   # False (greater than)
x >= y  # False (greater than or equal)

# ============ LOGICAL OPERATORS ============
condition1 = True
condition2 = False

condition1 and condition2  # False, && not used in Python
condition1 or condition2   # True, || not used in Python
not condition1             # False, ! not used in Python

# Real-world example
age = 25
income = 50000
is_eligible = age >= 18 and income >= 40000
print(f"Eligible: {is_eligible}")

# ============ ASSIGNMENT OPERATORS ============
num = 10
num += 5   # num = num + 5 → 15
num -= 3   # num = num - 3 → 12
num *= 2   # num = num * 2 → 24
num /= 4   # num = num / 4 → 6.0
num **= 2  # num = num ** 2 → 36.0
num %= 5   # num = num % 5 → 1.0

# ============ IDENTITY OPERATORS ============
list1 = [1, 2, 3]
list2 = [1, 2, 3]
list3 = list1

# In Python, "identity" refers to whether two variables point to the same object in memory.
# The expression list1 is list2 is False because they are two different objects, even though they have the same content.
# The expression list1 is list3 is True because list3 is a reference to the same object as list1.
list1 == list2   # True (same content)
list1 is list2   # False (different objects)
list1 is list3   # True (same object)

# If you change a value in list1, list3 will still reference the original list1 object.
# However, list2 will remain unchanged since it is a different object.
list1 = [1,2,3]
list2 = list1
print(list2)
list1[0] = 100
print(list2)  # list2 reflects the change since it references the same object as list1

list2 = list1.copy()  # Now list2 is a separate copy of list1

# ============ MEMBERSHIP OPERATORS ============
fruits = ["apple", "banana", "cherry"]
"apple" in fruits      # True
"orange" not in fruits # True

# ============ OPERATOR PRECEDENCE ============
# 1. () Parentheses
# 2. ** Exponentiation
# 3. +x, -x Unary plus/minus
# 4. *, /, //, % Multiplication, Division, Floor Division, Modulus
# 5. +, - Addition, Subtraction
# 6. ==, !=, <, <=, >, >=, is, is not, in, not in
# 7. not
# 8. and
# 9. or

result = 2 + 3 * 4  # 14 (not 20)
result = (2 + 3) * 4  # 20