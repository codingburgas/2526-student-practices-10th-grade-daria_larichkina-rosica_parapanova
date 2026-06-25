#pragma once
#include <string>
#include <vector>
#include "Seat.h"
using namespace std;

struct Movie {
    string title;
    string language;
    string genre;
    string releaseDate;

    double price;
    vector<Seat> seats;
};