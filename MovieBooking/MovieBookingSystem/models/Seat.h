#pragma once

enum SeatType {
    SILVER,
    GOLD,
    PLATINUM
};

struct Seat {
    int number;
    bool booked = false;
    SeatType type;
};