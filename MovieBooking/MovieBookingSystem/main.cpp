#include <iostream>
#include <vector>

#include "models/Movie.h"
#include "models/Seat.h"

using namespace std;

int main() {

    // Movies
    vector<Movie> movies = {
        {"Avengers"},
        {"Frozen"},
        {"Batman"}
    };

    cout << "=== Movies ===\n";
    for (int i = 0; i < movies.size(); i++) {
        cout << i + 1 << ". " << movies[i].title << endl;
    }

    int movieChoice;
    cout << "\nSelect movie (1-3): ";
    cin >> movieChoice;

    if (movieChoice < 1 || movieChoice > movies.size()) {
        cout << "Invalid choice!\n";
        return 0;
    }

    // Seats
    vector<Seat> seats(5);
    for (int i = 0; i < seats.size(); i++) {
        seats[i].number = i + 1;
    }

    cout << "\n=== Seats ===\n";
    for (auto& s : seats) {
        cout << "Seat " << s.number
            << (s.booked ? " (Booked)" : " (Available)") << endl;
    }

    int seatChoice;
    cout << "\nPick seat (1-5): ";
    cin >> seatChoice;

    if (seatChoice < 1 || seatChoice > seats.size()) {
        cout << "Invalid seat!\n";
        return 0;
    }

    // Booking logic
    if (seats[seatChoice - 1].booked) {
        cout << "Seat already booked!\n";
    }
    else {
        seats[seatChoice - 1].booked = true;
        cout << "Booking successful for "
            << movies[movieChoice - 1].title
            << " at seat " << seatChoice << endl;
    }

    return 0;
}