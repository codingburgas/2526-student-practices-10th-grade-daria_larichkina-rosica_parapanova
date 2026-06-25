#pragma once

struct Seat {
    int number;
    bool booked = false;
    bool vip = false;   // NEW
};