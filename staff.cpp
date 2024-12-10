#include "staff.h"
#include <iostream>

Admin::Admin() : name(""), position(""), phone(""), responsibility("") {
    std::cout << "Admin: Default constructor called\n";
}

Admin::Admin(const std::string& name, const std::string& position, const std::string& phone, const std::string& responsibility)
    : name(name), position(position), phone(phone), responsibility(responsibility) {
    std::cout << "Admin: Parameterized constructor called\n";
}

Admin::Admin(const Admin& other)
    : name(other.name), position(other.position), phone(other.phone), responsibility(other.responsibility) {
    std::cout << "Admin: Copy constructor called\n";
}

Admin::~Admin() {
    std::cout << "Admin: Destructor called\n";
}

void Admin::input() {
    std::cout << "Enter admin name: ";
    std::getline(std::cin, name);
    std::cout << "Enter position: ";
    std::getline(std::cin, position);
    std::cout << "Enter phone: ";
    std::getline(std::cin, phone);
    std::cout << "Enter responsibility: ";
    std::getline(std::cin, responsibility);
}

void Admin::display() const {
    std::cout << "Admin Name: " << name << "\nPosition: " << position
        << "\nPhone: " << phone << "\nResponsibility: " << responsibility << "\n";
}

void Admin::saveToFile(std::ostream& out) const {
    out << "Admin\n" << name << "\n" << position << "\n" << phone << "\n" << responsibility << "\n";
}

void Admin::loadFromFile(std::istream& in) {
    std::getline(in, name);
    std::getline(in, position);
    std::getline(in, phone);
    std::getline(in, responsibility);
}