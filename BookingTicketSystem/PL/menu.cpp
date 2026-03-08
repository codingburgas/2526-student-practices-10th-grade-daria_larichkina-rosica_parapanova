// menu.cpp
#include <iostream>
#include "menu.h"    // the function declarations
//#include "BookingRepository.h"     // if you need to access DAL functions

void showMenu() {
    int choice;
    do {
        std::cout << "\n--- Main Menu ---\n";
        std::cout << "1. Option 1\n";
        std::cout << "2. Option 2\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Option 1 selected\n";
            break;
        case 2:
            std::cout << "Option 2 selected\n";
            break;
        case 3:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }

    } while (choice != 3);
}