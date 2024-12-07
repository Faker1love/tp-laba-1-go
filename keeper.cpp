#include "Keeper.h"
#include "Students.h" // Подключить другие классы
#include <iostream>

Keeper::Keeper() : objects(nullptr), size(0) {}

Keeper::~Keeper() {
    for (size_t i = 0; i < size; ++i) {
        delete objects[i];
    }
    delete[] objects;
}

void Keeper::add(Base* obj) {
    Base** temp = new Base * [size + 1];
    for (size_t i = 0; i < size; ++i) {
        temp[i] = objects[i];
    }
    temp[size] = obj;
    delete[] objects;
    objects = temp;
    size++;
}

void Keeper::remove(size_t index) {
    if (index >= size) throw std::runtime_error("Invalid index");
    Base** temp = new Base * [size - 1];
    for (size_t i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            temp[j++] = objects[i];
        }
        else {
            delete objects[i];
        }
    }
    delete[] objects;
    objects = temp;
    size--;
}

void Keeper::display() const {
    for (size_t i = 0; i < size; ++i) {
        std::cout << "Object " << i + 1 << ":\n";
        objects[i]->display();
    }
}

void Keeper::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    if (!out) throw std::runtime_error("File open error");
    out << size << "\n";
    for (size_t i = 0; i < size; ++i) {
        objects[i]->saveToFile(out);
    }
}

void Keeper::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    if (!in) throw std::runtime_error("File open error");
    size_t newSize;
    in >> newSize;
    in.ignore();
    Base** temp = new Base * [newSize];
    for (size_t i = 0; i < newSize; ++i) {
        std::string type;
        std::getline(in, type);
        if (type == "Student") {
            temp[i] = new Student();
        } // Добавить условия для других типов
        temp[i]->loadFromFile(in);
    }
    for (size_t i = 0; i < size; ++i) {
        delete objects[i];
    }
    delete[] objects;
    objects = temp;
    size = newSize;
}
