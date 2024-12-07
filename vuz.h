#ifndef BASE_H
#define BASE_H

#include <string>
#include <iostream>

class Base {
public:
    virtual ~Base() = default;
    virtual void input() = 0; // Ввод данных
    virtual void display() const = 0; // Вывод данных
    virtual void saveToFile(std::ostream& out) const = 0; // Сохранение в файл
    virtual void loadFromFile(std::istream& in) = 0; // Загрузка из файла
};

#endif // BASE_H