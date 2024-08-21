# Student Grade Management CLI

## Overview

This is a simple command-line interface (CLI) application for managing student grades, built in C++. The application allows users to add students, view all students, search for specific students, edit student grades, calculate the average grade for each student, and save data to a file.

## Features

Add Student: Add a new student with their grades.
View All Students: Display all students and their grades.
Search for a Student: Search for a student by name and view their grades.
Edit a Student's Grades: Modify the grades of an existing student.
Calculate Average Grade: Calculate and display the average grade for each student.
Save and Exit: Save all student data to a file and exit the application.

## Getting Started

### Prerequisites

To compile and run this program, you'll need:

- A C++ compiler (e.g., `clang++`, `g++`)
- A terminal or command prompt

### Compilation

1. Clone or download the repository to your local machine.
2. Open your terminal or command prompt and navigate to the directory containing `main.cpp`.
3. Compile the code using a C++ compiler. For example, using `clang++`:

```bash
# With clang++ compiler
clang++ -std=c++20 main.cpp -o main
# or with g++ compiler
g++ main.cpp -o main
```

## Usage

After running the application, a menu will appear with several options:

1. Add Student: Enter the student's name and grades. Type -1 to finish entering grades.
2. View All Students: Displays all students' names and their respective grades.
3. Search for a Student: Enter the student's name to view their grades.
4. Edit a Student's Grades: Modify the grades of a student by entering their name.
5. Calculate Average for Student's Grade: Calculate and display the average grade for each student.
6. Save and Exit: Save the students' data to students.txt and exit the application.

### Example

```bash
Menu
1. Add student
2. View all students
3. Search for a student
4. Edit a student's grades
5. Calculate average for student's grade
6. Save and Exit

Enter your choice: 1

Enter student's name: Alice
Enter grades (type -1 to finish): 85 90 78 -1
```
