#pragma once
#include <vector>
#include <string>
#include "../models/Seat.h"

class FileManager {
public:
    static std::vector<Seat> loadSeats(const std::string& filename, int count);
    static void saveSeats(const std::string& filename, const std::vector<Seat>& seats);
};