"""
=== FILE HANDLING ===
Topics Covered:
- Opening and Closing Files
- Reading Files
- Writing to Files
- Appending to Files
- Working with Different File Modes
- Using Context Managers (with statement)
- File Methods
"""

# ============ BASIC FILE OPERATIONS ============

# Opening a file
file = open("example.txt", "r")  # r = read mode
content = file.read()
file.close()

# Reading specific amount of characters
file = open("example.txt", "r")
first_100_chars = file.read(100)
file.close()

# Reading line by line
file = open("example.txt", "r")
first_line = file.readline()
second_line = file.readline()
file.close()

# Reading all lines as list
file = open("example.txt", "r")
lines = file.readlines()
file.close()

# ============ FILE MODES ============
# 'r'  - Read (default)
# 'w'  - Write (overwrites existing)
# 'a'  - Append (adds to end)
# 'x'  - Create (fails if exists)
# 'b'  - Binary mode (e.g., 'rb', 'wb')
# '+'  - Read and Write (e.g., 'r+', 'w+')

# ============ WRITING TO FILES ============

# Write mode (overwrites existing content)
file = open("output.txt", "w")
file.write("Hello, World!\n")
file.write("This is line 2\n")
file.close()

# Write multiple lines
file = open("output.txt", "w")
lines = ["Line 1\n", "Line 2\n", "Line 3\n"]
file.writelines(lines)
file.close()

# ============ APPENDING TO FILES ============

# Append mode (adds to end)
file = open("output.txt", "a")
file.write("Added line\n")
file.close()

# ============ CONTEXT MANAGER (WITH STATEMENT) ============
# Automatically closes file - RECOMMENDED

# Reading with context manager
with open("example.txt", "r") as file:
    content = file.read()
    print(content)
# File is automatically closed

# Writing with context manager
with open("output.txt", "w") as file:
    file.write("Hello!\n")
    file.write("World!\n")

# Appending with context manager
with open("output.txt", "a") as file:
    file.write("New line\n")

# ============ ITERATING THROUGH FILES ============

# Method 1: Using readlines()
with open("example.txt", "r") as file:
    lines = file.readlines()
    for line in lines:
        print(line.strip())

# Method 2: Direct iteration (more efficient)
with open("example.txt", "r") as file:
    for line in file:
        print(line.strip())

# Method 3: Using enumerate for line numbers
with open("example.txt", "r") as file:
    for line_num, line in enumerate(file, start=1):
        print(f"{line_num}: {line.strip()}")

# ============ FILE METHODS ============

with open("example.txt", "r") as file:
    # Read entire file
    content = file.read()
    
    # Get current position
    position = file.tell()
    
    # Reset to beginning
    file.seek(0)
    
    # Get file name
    filename = file.name
    
    # Check if closed
    is_closed = file.closed

# ============ WORKING WITH DIFFERENT FILE TYPES ============

# Text file (already covered above)
with open("text.txt", "r") as file:
    content = file.read()

# Binary file
with open("image.png", "rb") as file:
    binary_content = file.read()

# CSV files (using csv module)
import csv

# Writing CSV
data = [
    ["Name", "Age", "City"],
    ["Alice", "30", "NYC"],
    ["Bob", "25", "LA"]
]

with open("data.csv", "w", newline="") as file:
    writer = csv.writer(file)
    writer.writerows(data)

# Reading CSV
with open("data.csv", "r") as file:
    reader = csv.reader(file)
    for row in reader:
        print(row)

# Reading CSV as dictionaries
with open("data.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        print(row)

# JSON files
import json

# Writing JSON
data = {
    "name": "Alice",
    "age": 30,
    "city": "NYC"
}

with open("data.json", "w") as file:
    json.dump(data, file, indent=2)

# Reading JSON
with open("data.json", "r") as file:
    data = json.load(file)
    print(data)

# ============ FILE AND DIRECTORY OPERATIONS ============

import os

# Check if file exists
if os.path.exists("example.txt"):
    print("File exists")

# Check if it's a file
if os.path.isfile("example.txt"):
    print("It's a file")

# Check if it's a directory
if os.path.isdir("./data"):
    print("It's a directory")

# Get file size
size = os.path.getsize("example.txt")

# Rename file
os.rename("old_name.txt", "new_name.txt")

# Delete file
os.remove("file_to_delete.txt")

# Create directory
os.mkdir("new_folder")

# Create directories recursively
os.makedirs("path/to/nested/folder")

# List directory contents
files = os.listdir(".")

# Get current working directory
cwd = os.getcwd()

# ============ PRACTICAL EXAMPLES ============

# Example 1: Read and process file
def process_file(filename):
    """Read file and count lines and words."""
    try:
        with open(filename, "r") as file:
            lines = file.readlines()
            word_count = sum(len(line.split()) for line in lines)
            return len(lines), word_count
    except FileNotFoundError:
        print(f"File {filename} not found")
        return None, None

# Example 2: Copy file
def copy_file(source, destination):
    """Copy file from source to destination."""
    try:
        with open(source, "r") as source_file:
            content = source_file.read()
        with open(destination, "w") as dest_file:
            dest_file.write(content)
        print(f"File copied from {source} to {destination}")
    except FileNotFoundError as e:
        print(f"Error: {e}")

# Example 3: Find lines containing keyword
def grep(filename, keyword):
    """Find lines containing keyword in file."""
    matching_lines = []
    try:
        with open(filename, "r") as file:
            for line_num, line in enumerate(file, start=1):
                if keyword.lower() in line.lower():
                    matching_lines.append((line_num, line.strip()))
        return matching_lines
    except FileNotFoundError:
        print(f"File {filename} not found")
        return []