#ifndef TEACHER_H
#define TEACHER_H

#include "Vuz.h"
#include <vector>

class Teacher : public Base {
    std::string name;
    std::vector<std::string> groups;
    std::vector<std::string> subjects;

public:
    Teacher();
    Teacher(const std::string& name, const std::vector<std::string>& groups, const std::vector<std::string>& subjects);
    Teacher(const Teacher& other);
    ~Teacher();

    void input() override;
    void display() const override;
    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;
};

#endif // TEACHER_H