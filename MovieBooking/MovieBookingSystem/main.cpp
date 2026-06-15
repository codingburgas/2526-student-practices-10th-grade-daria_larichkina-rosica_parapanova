//#include <iostream>
//#include <vector>
//
//#include "models/Movie.h"
//#include "models/Seat.h"
//
//using namespace std;
//
//int main() {
//
//    // Movies
//    vector<Movie> movies = {
//        {"Avengers"},
//        {"Frozen"},
//        {"Batman"}
//    };
//
//    cout << "=== Movies ===\n";
//    for (int i = 0; i < movies.size(); i++) {
//        cout << i + 1 << ". " << movies[i].title << endl;
//    }
//
//    int movieChoice;
//    cout << "\nSelect movie (1-3): ";
//    cin >> movieChoice;
//
//    if (movieChoice < 1 || movieChoice > movies.size()) {
//        cout << "Invalid choice!\n";
//        return 0;
//    }
//
//    // Seats
//    vector<Seat> seats(5);
//    for (int i = 0; i < seats.size(); i++) {
//        seats[i].number = i + 1;
//    }
//
//    cout << "\n=== Seats ===\n";
//    for (auto& s : seats) {
//        cout << "Seat " << s.number
//            << (s.booked ? " (Booked)" : " (Available)") << endl;
//    }
//
//    int seatChoice;
//    cout << "\nPick seat (1-5): ";
//    cin >> seatChoice;
//
//    if (seatChoice < 1 || seatChoice > seats.size()) {
//        cout << "Invalid seat!\n";
//        return 0;
//    }
//

//    // Booking logic
//    if (seats[seatChoice - 1].booked) {
//        cout << "Seat already booked!\n";
//    }
//    else {
//        seats[seatChoice - 1].booked = true;
//        cout << "Booking successful for "
//            << movies[movieChoice - 1].title
//            << " at seat " << seatChoice << endl;
//    }
//
//    return 0;
//}
#include <iostream>
#include <vector>

#include "models/Movie.h"
#include "models/Seat.h"

using namespace std;

int main() {

    // MOVIES
    vector<Movie> movies = {
     {"Avengers", 12.50},
     {"Frozen", 10.00},
     {"Batman", 11.50}
    };

    double totalPrice = 0;
    vector<Seat> seats(5);
    for (int i = 0; i < seats.size(); i++) {
        seats[i].number = i + 1;
    }

    while (true) {

        // MAIN MENU
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Book seat\n";
        cout << "2. Exit\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (choice == 2) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice != 1) {
            cout << "Invalid choice!\n";
            continue;
        }

        // MOVIES
        cout << "\n=== Movies ===\n";
        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". " << movies[i].title << endl;
        }

        int movieChoice;
        cout << "\nSelect movie: ";
        cin >> movieChoice;

        if (movieChoice < 1 || movieChoice > movies.size()) {
            cout << "Invalid movie!\n";
            continue;
        }

        // SEATS
        cout << "\n=== Seats ===\n";
        for (auto& s : seats) {
            cout << "Seat " << s.number
                << (s.booked ? " (Booked)" : " (Available)") << endl;
        }

        int seatChoice;
        cout << "\nPick seat: ";
        cin >> seatChoice;

        if (seatChoice < 1 || seatChoice > seats.size()) {
            cout << "Invalid seat!\n";
            continue;
        }

        // BOOKING LOGIC
       /* if (seats[seatChoice - 1].booked) {
            cout << "Seat already booked!\n";
        }
        else {
            seats[seatChoice - 1].booked = true;

            cout << "Booking successful for "
                << movies[movieChoice - 1].title
                << " at seat " << seatChoice << endl;
        }*/
        // BOOKING LOGIC
        if (seats[seatChoice - 1].booked) {
            cout << "Seat already booked!\n";
        }
        else {
            seats[seatChoice - 1].booked = true;
            totalPrice += movies[movieChoice - 1].price;
            cout << "Booking successful for "
                << movies[movieChoice - 1].title
                << " at seat " << seatChoice << endl;

            cout << "Ticket price: $"
                << movies[movieChoice - 1].price << endl;

            cout << "Current total: $"
                << totalPrice << endl;
            while (true) {
                cout << "\n=== NEXT ACTION ===\n";
                cout << "1. Book another seat\n";
                cout << "2. Pay\n";
                cout << "3. Exit\n";
                cout << "Choice: ";

                int nextChoice;
                cin >> nextChoice;

                if (nextChoice == 1) {
                    break;
                }
                else if (nextChoice == 2) {

                    // PAYMENT OPTIONS
                    cout << "\nPayment method:\n";
                    cout << "1. Cash\n";
                    cout << "2. Card\n";
                    cout << "Choice: ";

                    int paymentChoice;
                    cin >> paymentChoice;

                    if (paymentChoice == 1) {
                        cout << "You chose to pay with cash.\n";
                        cout << "\n===== RECEIPT =====\n";
                        cout << "Total amount: $" << totalPrice << endl;
                    }
                    else if (paymentChoice == 2) {
                        cout << "You chose to pay with card.\n";
                        cout << "\n===== RECEIPT =====\n";
                        cout << "Total amount: $" << totalPrice << endl;
                    }
                    else {
                        cout << "Invalid payment option.\n";
                        continue;
                    }

                    cout << "Payment successful!\n";
                }
                else if (nextChoice == 3) {
                    cout << "Goodbye!\n";
                    return 0; 
                }
                else {
                    cout << "Invalid choice!\n";
                }
            }
        }
    }

    return 0;
}