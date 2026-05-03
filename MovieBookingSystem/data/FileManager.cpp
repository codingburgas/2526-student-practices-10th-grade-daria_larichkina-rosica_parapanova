#include "FileManager.h"
#include <fstream>

std::vector<Seat> FileManager::loadSeats(const std::string& filename, int count) {
    std::vector<Seat> seats(count);

    for (int i = 0; i < count; i++) {
        seats[i].number = i + 1;
    }

    std::ifstream inFile(filename);

    if (inFile.is_open()) {
        for (int i = 0; i < count; i++) {
            inFile >> seats[i].booked;
        }
        inFile.close();
    }

    return seats;
}

void FileManager::saveSeats(const std::string& filename, const std::vector<Seat>& seats) {
    std::ofstream outFile(filename);

    for (const auto& s : seats) {
        outFile << s.booked << std::endl;
    }

    outFile.close();
}