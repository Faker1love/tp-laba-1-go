#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

class Base {
public:
    virtual ~Base() = default;
    virtual void input() = 0; // ���� ������
    virtual void display() const = 0; // ����� ������
    virtual void saveToFile(std::ostream& out) const = 0; // ���������� � ����
    virtual void loadFromFile(std::istream& in) = 0; // �������� �� �����
};

#endif // BASE_H