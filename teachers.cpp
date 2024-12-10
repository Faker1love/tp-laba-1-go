#include "Teachers.h"
#include <iostream>

Teacher::Teacher() : name("") {
    std::cout << "Teacher: Default constructor called\n";
}

Teacher::Teacher(const std::string& name, const std::vector<std::string>& groups, const std::vector<std::string>& subjects)
    : name(name), groups(groups), subjects(subjects) {
    std::cout << "Teacher: Parameterized constructor called\n";
}

Teacher::Teacher(const Teacher& other) : name(other.name), groups(other.groups), subjects(other.subjects) {
    std::cout << "Teacher: Copy constructor called\n";
}

Teacher::~Teacher() {
    std::cout << "Teacher: Destructor called\n";
}

void Teacher::input() {
    std::cout << "Enter teacher name: ";
    std::getline(std::cin, name);
    int count;
    std::cout << "Enter number of groups: ";
    std::cin >> count;
    std::cin.ignore();
    groups.clear();
    for (int i = 0; i < count; ++i) {
        std::string group;
        std::cout << "Enter group " << i + 1 << ": ";
        std::getline(std::cin, group);
        groups.push_back(group);
    }
    std::cout << "Enter number of subjects: ";
    std::cin >> count;
    std::cin.ignore();
    subjects.clear();
    for (int i = 0; i < count; ++i) {
        std::string subject;
        std::cout << "Enter subject " << i + 1 << ": ";
        std::getline(std::cin, subject);
        subjects.push_back(subject);
    }
}

void Teacher::display() const {
    std::cout << "Teacher Name: " << name << "\nGroups: ";
    for (const auto& group : groups) {
        std::cout << group << " ";
    }
    std::cout << "\nSubjects: ";
    for (const auto& subject : subjects) {
        std::cout << subject << " ";
    }
    std::cout << "\n";
}

void Teacher::saveToFile(std::ostream& out) const {
    out << "Teacher\n" << name << "\n" << groups.size() << "\n";
    for (const auto& group : groups) {
        out << group << "\n";
    }
    out << subjects.size() << "\n";
    for (const auto& subject : subjects) {
        out << subject << "\n";
    }
}

void Teacher::loadFromFile(std::istream& in) {
    std::getline(in, name);
    size_t count;
    in >> count;
    in.ignore();
    groups.clear();
    for (size_t i = 0; i < count; ++i) {
        std::string group;
        std::getline(in, group);
        groups.push_back(group);
    }
    in >> count;
    in.ignore();
    subjects.clear();
    for (size_t i = 0; i < count; ++i) {
        std::string subject;
        std::getline(in, subject);
        subjects.push_back(subject);
    }
}