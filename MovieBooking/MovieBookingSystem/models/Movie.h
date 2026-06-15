#pragma once
#include <string>
#include <vector>
#include "Seat.h"
using namespace std;

struct Movie {
    string title;
    double price;
    vector<Seat> seats;
};