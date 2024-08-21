#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

struct Student
{
    std::string name;
    std::vector<int> grades;
};

void saveToFile(const std::vector<Student> &students, const std::string &filename)
{
    std::ofstream file(filename);
    for (const auto &student : students)
    {
        file << student.name << std::endl;
        for (const auto &grade : student.grades)
        {
            file << grade << ' ';
        }
        file << std::endl;
    }
}

void loadFromFile(std::vector<Student> &students, const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        students.clear();
        std::string name;
        while (std::getline(file, name))
        {
            Student student;
            student.name = name;
            std::string line;
            std::getline(file, line);
            std::istringstream iss(line);
            int grade;
            while (iss >> grade)
            {
                student.grades.push_back(grade);
            }
            students.push_back(student);
        }
    }
}

void addStudent(std::vector<Student> &students)
{
    Student newStudent;
    std::cout << "Enter student's name: ";
    std::getline(std::cin, newStudent.name);

    int grade;
    std::cout << "Enter grades (type -1 to finish): ";
    while (std::cin >> grade && grade != -1)
    {
        newStudent.grades.push_back(grade);
    }
    std::cin.ignore();
    students.push_back(newStudent);
}

void viewAllStudents(const std::vector<Student> &students)
{
    for (const auto &student : students)
    {
        std::cout << "Name: " << student.name << std::endl;
        std::cout << "Grades: ";
        for (const auto &i : student.grades)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}

void editStudentGrade(std::vector<Student> &students)
{
    std::string name;
    std::cout << "Enter student's name to edit: ";
    std::getline(std::cin, name);

    for (auto &student : students)
    {
        if (student.name == name)
        {
            std::cout << "Enter grades (type -1 to finish): ";
            student.grades.clear();
            int grade;
            while (std::cin >> grade && grade != -1)
            {
                student.grades.push_back(grade);
            }
            std::cin.ignore();
            return;
        }
    }
    std::cout << "Student not found" << std::endl;
}

void searchStudent(const std::vector<Student> &students)
{
    std::string name;
    std::cout << "Enter student's name to search: ";
    std::getline(std::cin, name);

    for (const auto &student : students)
    {
        if (student.name == name)
        {
            std::cout << "Found: " << student.name << std::endl;
            std::cout << "Grades: ";
            for (const auto &i : student.grades)
            {
                std::cout << i << " ";
            }
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "Student not found" << std::endl;
}

void calculateAverageGrade(const std::vector<Student> &students)
{
    for (const auto &student : students)
    {
        double total = 0;
        for (const auto &grade : student.grades)
        {
            total += grade;
        }
        double average = total / student.grades.size();
        std::cout << "Average grade for " << student.name << " : " << average << std::endl;
    }
}

int main()
{
    std::vector<Student> students;
    const std::string filename = "students.txt";

    loadFromFile(students, filename);

    int choice;
    do
    {
        std::cout << std::endl;
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add student" << std::endl;
        std::cout << "2. View all students" << std::endl;
        std::cout << "3. Search for a student" << std::endl;
        std::cout << "4. Edit a student's grades" << std::endl;
        std::cout << "5. Calculate average for student's grade" << std::endl;
        std::cout << "6. Save and Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        std::cout << std::endl;
        switch (choice)
        {
        case 1:
            addStudent(students);
            break;
        case 2:
            viewAllStudents(students);
            break;
        case 3:
            searchStudent(students);
            break;
        case 4:
            editStudentGrade(students);
            break;
        case 5:
            calculateAverageGrade(students);
            break;
        case 6:
            saveToFile(students, filename);
            break;
        default:
            std::cout << "Invalid choice! Try again" << std::endl;
        }

    } while (choice != 6);
    return 0;
}