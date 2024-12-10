#ifndef ADMIN_H
#define ADMIN_H

#include "Vuz.h"

class Admin : public Base {
    std::string name;
    std::string position;
    std::string phone;
    std::string responsibility;

public:
    Admin();
    Admin(const std::string& name, const std::string& position, const std::string& phone, const std::string& responsibility);
    Admin(const Admin& other);
    ~Admin();

    void input() override;
    void display() const override;
    void saveToFile(std::ostream& out) const override;
    void loadFromFile(std::istream& in) override;
};

#endif // ADMIN_H