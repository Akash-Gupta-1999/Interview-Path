"""
=== REGULAR EXPRESSIONS ===
Topics Covered:
- Pattern Matching with re module
- Basic Patterns and Metacharacters
- match(), search(), findall()
- sub() for String Replacement
- compile() for Reusable Patterns
- Named Groups
"""

import re

# ============ BASIC PATTERN MATCHING ============

# re.search() - finds first match
text = "Hello World"
if re.search(r"World", text):
    print("Found 'World'")

# re.match() - checks if pattern is at beginning
if re.match(r"Hello", text):
    print("Text starts with 'Hello'")

# re.findall() - finds all matches
text = "apple, banana, cherry"
fruits = re.findall(r"\w+", text)
print(fruits)  # ['apple', 'banana', 'cherry']

# ============ METACHARACTERS ============

# .  - Any character except newline
pattern = r"c.t"
text = "cat, cot, cut, c9t"
matches = re.findall(pattern, text)
print(matches)  # ['cat', 'cot', 'cut', 'c9t']

# ^  - Start of string
pattern = r"^Hello"
texts = ["Hello World", "Say Hello"]
for text in texts:
    if re.match(pattern, text):
        print(f"'{text}' starts with Hello")

# $  - End of string
pattern = r"world$"
texts = ["Hello world", "Hello World"]
for text in texts:
    if re.search(pattern, text, re.IGNORECASE):
        print(f"'{text}' ends with world")

# *  - 0 or more occurrences
pattern = r"lo*p"
text = "lop, loop, loooop, lp"
matches = re.findall(pattern, text)
print(matches)  # ['lop', 'loop', 'loooop', 'lp']

# +  - 1 or more occurrences
pattern = r"lo+p"
text = "lop, loop, loooop, lp"
matches = re.findall(pattern, text)
print(matches)  # ['lop', 'loop', 'loooop']

# ?  - 0 or 1 occurrence
pattern = r"colou?r"
texts = ["color", "colour"]
for text in texts:
    if re.match(pattern, text):
        print(f"Matched: {text}")

# {n}  - Exactly n occurrences
pattern = r"a{3}"
text = "aaa, aaaa, aa"
matches = re.findall(pattern, text)
print(matches)  # ['aaa', 'aaa']

# {n,m}  - Between n and m occurrences
pattern = r"a{2,3}"
text = "a, aa, aaa, aaaa"
matches = re.findall(pattern, text)
print(matches)  # ['aa', 'aaa', 'aaa']

# ============ CHARACTER CLASSES ============

# [abc]  - Any of a, b, or c
pattern = r"[aeiou]"
text = "Hello"
vowels = re.findall(pattern, text)
print(vowels)  # ['e', 'o']

# [^abc]  - Not a, b, or c
pattern = r"[^aeiou]"
text = "Hello"
consonants = re.findall(pattern, text)
print(consonants)  # ['H', 'l', 'l']

# [a-z]  - Range a to z
pattern = r"[a-z]+"
text = "Hello World 123"
matches = re.findall(pattern, text)
print(matches)  # ['ello', 'orld']

# [0-9]  - Digits
pattern = r"[0-9]+"
text = "Phone: 123-456-7890"
matches = re.findall(pattern, text)
print(matches)  # ['123', '456', '7890']

# ============ SPECIAL SEQUENCES ============

# \d  - Digit [0-9]
pattern = r"\d+"
text = "My number is 12345"
matches = re.findall(pattern, text)
print(matches)  # ['12345']

# \D  - Non-digit
pattern = r"\D+"
text = "abc123def456"
matches = re.findall(pattern, text)
print(matches)  # ['abc', 'def']

# \w  - Word character [a-zA-Z0-9_]
pattern = r"\w+"
text = "Hello, World! 123"
matches = re.findall(pattern, text)
print(matches)  # ['Hello', 'World', '123']

# \W  - Non-word character
pattern = r"\W+"
text = "Hello, World!"
matches = re.findall(pattern, text)
print(matches)  # [', ', '!']

# \s  - Whitespace
pattern = r"\s+"
text = "Hello   World"
matches = re.findall(pattern, text)
print(matches)  # ['   ']

# \S  - Non-whitespace
pattern = r"\S+"
text = "Hello World Python"
matches = re.findall(pattern, text)
print(matches)  # ['Hello', 'World', 'Python']

# ============ GROUPING ============

# ()  - Grouping
pattern = r"(\w+)@(\w+\.\w+)"
email = "alice@example.com"
match = re.search(pattern, email)
if match:
    print(match.group(0))  # Full match: alice@example.com
    print(match.group(1))  # Group 1: alice
    print(match.group(2))  # Group 2: example.com

# ============ NAMED GROUPS ============

# (?P<name>...)  - Named group
pattern = r"(?P<name>\w+)@(?P<domain>\w+\.\w+)"
email = "bob@company.com"
match = re.search(pattern, email)
if match:
    print(match.group("name"))      # bob
    print(match.group("domain"))    # company.com

# ============ SUBSTITUTION ============

# re.sub() - Replace matches
text = "Hello World"
new_text = re.sub(r"World", "Python", text)
print(new_text)  # Hello Python

# Replace with pattern
text = "I have 123 apples and 456 oranges"
new_text = re.sub(r"\d+", "X", text)
print(new_text)  # I have X apples and X oranges

# Replace with count limit
text = "aaa"
new_text = re.sub(r"a", "b", text, count=2)
print(new_text)  # bba

# Using groups in replacement
text = "John Smith, Jane Doe"
new_text = re.sub(r"(\w+) (\w+)", r"\2, \1", text)
print(new_text)  # Smith, John, Doe, Jane

# Using function for replacement
def replace_with_asterisk(match):
    return "*" * len(match.group(0))

text = "Secret password123"
new_text = re.sub(r"\w+", replace_with_asterisk, text)
print(new_text)  # ****** ********

# ============ COMPILING PATTERNS ============

# Compile for reusable patterns
pattern = re.compile(r"\b\d{3}-\d{3}-\d{4}\b")

phones = [
    "123-456-7890",
    "999-888-7777",
    "12-34-5678"
]

for phone in phones:
    if pattern.search(phone):
        print(f"Valid phone: {phone}")

# ============ PRACTICAL EXAMPLES ============

# Example 1: Email validation
def is_valid_email(email):
    pattern = r"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$"
    return re.match(pattern, email) is not None

print(is_valid_email("alice@example.com"))    # True
print(is_valid_email("invalid.email@"))       # False

# Example 2: Extract URLs from text
text = "Visit https://example.com and http://google.com"
urls = re.findall(r"https?://\S+", text)
print(urls)

# Example 3: Phone number normalization
def format_phone(phone):
    pattern = r"(\d{3})(\d{3})(\d{4})"
    return re.sub(pattern, r"(\1) \2-\3", phone)

print(format_phone("1234567890"))  # (123) 456-7890

# Example 4: Extract data from structured text
log = "2025-01-26 10:30:45 ERROR User login failed"
match = re.search(r"(\d{4}-\d{2}-\d{2}) (\d{2}:\d{2}:\d{2}) (\w+) (.*)", log)
if match:
    date, time, level, message = match.groups()
    print(f"Date: {date}, Time: {time}, Level: {level}, Message: {message}")