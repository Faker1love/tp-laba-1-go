#include "Keeper.h"
#include "Students.h"

int main() {
    Keeper keeper;

    try {
        int choice;
        do {
            std::cout << "1. Add Student\n2. Remove Object\n3. Display All\n4. Save to File\n5. Load from File\n0. Exit\n";
            std::cin >> choice;
            std::cin.ignore();

            if (choice == 1) {
                Base* student = new Student();
                student->input();
                keeper.add(student);
            }
            else if (choice == 2) {
                size_t index;
                std::cout << "Enter index to remove: ";
                std::cin >> index;
                keeper.remove(index - 1);
            }
            else if (choice == 3) {
                keeper.display();
            }
            else if (choice == 4) {
                keeper.saveToFile("data.txt");
            }
            else if (choice == 5) {
                keeper.loadFromFile("data.txt");
            }
        } while (choice != 0);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
