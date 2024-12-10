#include "Keeper.h"
#include "Students.h"
#include "Teachers.h"
#include "staff.h"
#include <iostream>

int main() {
    Keeper keeper;

    try {
        int choice;
        do {
            std::cout << "1. Add Student\n2. Add Teacher\n3. Add Admin\n"
                << "4. Remove Object\n5. Display All\n6. Save to File\n7. Load from File\n0. Exit\n";
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 1) {
                Base* student = new Student();
                student->input();
                keeper.add(student);
            }
            else if (choice == 2) {
                Base* teacher = new Teacher();
                teacher->input();
                keeper.add(teacher);
            }
            else if (choice == 3) {
                Base* admin = new Admin();
                admin->input();
                keeper.add(admin);
            }
            else if (choice == 4) {
                size_t index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                keeper.remove(index - 1);
            }
            else if (choice == 5) {
                keeper.display();
            }
            else if (choice == 6) {
                keeper.saveToFile("data.txt");
            }
            else if (choice == 7) {
                keeper.loadFromFile("data.txt");
            }
        } while (choice != 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}