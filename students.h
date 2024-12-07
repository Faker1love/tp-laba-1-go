#ifndef STUDENT_H
#define STUDENT_H

#include "Vuz.h"

class Student : public Base {
    std::string name;
    std::string group;
    std::string specialty;
    int course;
    double averageGrade;

public:
    Student();
    Student(const std::string& name, const std::string& group, const std::string& specialty, int course, double averageGrade);
    Student(const Student& other);
    ~Student();

    void input() override;
    void display() const override;
    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;
};

#endif // STUDENT_H
