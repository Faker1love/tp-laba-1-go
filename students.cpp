#include "Students.h"
#include <iostream>
#include <stdexcept>

Student::Student() : name(""), group(""), specialty(""), course(1), averageGrade(0.0) {
    std::cout << "Student: Default constructor called\n";
}

Student::Student(const std::string& name, const std::string& group, const std::string& specialty, int course, double averageGrade)
    : name(name), group(group), specialty(specialty), course(course), averageGrade(averageGrade) {
    std::cout << "Student: Parameterized constructor called\n";
}

Student::Student(const Student& other)
    : name(other.name), group(other.group), specialty(other.specialty), course(other.course), averageGrade(other.averageGrade) {
    std::cout << "Student: Copy constructor called\n";
}

Student::~Student() {
    std::cout << "Student: Destructor called\n";
}

void Student::input() {
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter group: ";
    std::getline(std::cin, group);
    std::cout << "Enter specialty: ";
    std::getline(std::cin, specialty);
    std::cout << "Enter course: ";
    std::cin >> course;
    if (course < 1) throw std::runtime_error("Invalid course number");
    std::cout << "Enter average grade: ";
    std::cin >> averageGrade;
    if (averageGrade < 0 || averageGrade > 5) throw std::runtime_error("Invalid grade value");
    std::cin.ignore();
}

void Student::display() const {
    std::cout << "Student Name: " << name << "\nGroup: " << group << "\nSpecialty: " << specialty
        << "\nCourse: " << course << "\nAverage Grade: " << averageGrade << "\n";
}

void Student::saveToFile(std::ostream& out) const {
    out << "Student\n" << name << "\n" << group << "\n" << specialty << "\n" << course << "\n" << averageGrade << "\n";
}

void Student::loadFromFile(std::istream& in) {
    std::getline(in, name);
    std::getline(in, group);
    std::getline(in, specialty);
    in >> course >> averageGrade;
    in.ignore();
}
