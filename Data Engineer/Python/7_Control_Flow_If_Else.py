"""
=== CONTROL FLOW: IF, ELIF, ELSE ===
Topics Covered:
- Boolean Logic and Conditions
- If Statements
- If-Elif-Else Chains
- Nested Conditions
- Ternary Operator
"""

# ============ BOOLEAN LOGIC ============
# Truthy and Falsy values

# Falsy values
bool(0)           # False
bool(0.0)         # False
bool("")          # False
bool([])          # False
bool({})          # False
bool(())          # False
bool(None)        # False

# Truthy values
bool(1)           # True
bool(-1)          # True
bool("text")      # True
bool([1])         # True
bool([None])      # True (list with element is truthy)

# ============ IF STATEMENTS ============

age = 18

if age >= 18:
    print("You are an adult")

# if-else
if age < 18:
    print("You are a minor")
else:
    print("You are an adult")

# if-elif-else
score = 85

if score >= 90:
    grade = "A"
elif score >= 80:
    grade = "B"
elif score >= 70:
    grade = "C"
elif score >= 60:
    grade = "D"
else:
    grade = "F"

print(f"Grade: {grade}")

# ============ NESTED CONDITIONS ============

age = 25
income = 50000
credit_score = 720

if age >= 18:
    if income >= 40000:
        if credit_score >= 700:
            print("Eligible for loan")
        else:
            print("Credit score too low")
    else:
        print("Income too low")
else:
    print("Too young")

# Better approach: Use 'and' operator
if age >= 18 and income >= 40000 and credit_score >= 700:
    print("Eligible for loan")

# ============ TERNARY OPERATOR ============
# Syntax: value_if_true if condition else value_if_false

age = 20
status = "adult" if age >= 18 else "minor"

a=2,b=4
# With expressions
max_value = a if a > b else b

# Nested ternary (less readable)
category = "child" if age < 13 else "teen" if age < 18 else "adult"

# ============ MULTIPLE CONDITIONS ============

# Using 'in' with lists
day = "Saturday"
if day in ["Saturday", "Sunday"]:
    print("It's the weekend!")

# Using 'not'
user = None
if not user:
    print("No user logged in")

attendance = 0.85
extra_credit = 10
# Combining conditions
if (score >= 90 and attendance >= 0.8) or extra_credit >= 5:
    print("Pass the course")

# ============ PRACTICAL EXAMPLES ============

# Example 1: Grade with feedback
def get_grade_feedback(score):
    if score >= 90:
        return "Excellent!"
    elif score >= 80:
        return "Good!"
    elif score >= 70:
        return "Satisfactory"
    elif score >= 60:
        return "Needs improvement"
    else:
        return "Fail"

# Example 2: Validation
def validate_password(password):
    if len(password) < 8:
        return False, "Password too short"
    elif not any(c.isupper() for c in password):
        return False, "Must contain uppercase"
    elif not any(c.isdigit() for c in password):
        return False, "Must contain digit"
    else:
        return True, "Valid password"