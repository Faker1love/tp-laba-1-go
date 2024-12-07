#ifndef KEEPER_H
#define KEEPER_H

#include "Vuz.h"
#include <vector>
#include <fstream>

class Keeper {
    Base** objects;
    size_t size;

public:
    Keeper();
    ~Keeper();
    void add(Base* obj);
    void remove(size_t index);
    void display() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // KEEPER_H