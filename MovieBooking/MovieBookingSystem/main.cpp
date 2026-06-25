
#include <iostream>
#include <vector>

#include "models/Movie.h"
#include "models/Seat.h"

using namespace std;

int main() {

    // MOVIES
    vector<Movie> movies = {
    {"Avengers", 12.50, vector<Seat>(5)},
    {"Frozen", 10.00, vector<Seat>(5)},
    {"Batman", 11.50, vector<Seat>(5)},
    {"Fight Club", 14.50, vector<Seat>(5)},
    {"Minions", 9.50, vector<Seat>(5)},
    {"Barbie", 15.50, vector<Seat>(5)},
    {"Star Wars", 13.50, vector<Seat>(5)},
    {"Titanic", 10.50, vector<Seat>(5)},
    {"Spiderman", 12.50, vector<Seat>(5)},
    {"Interstellar", 16.50, vector<Seat>(5)},
    {"Forrest Gump", 11.50, vector<Seat>(5)},
    {"Moana", 9.50, vector<Seat>(5)},
    {"The Matrix", 9.50, vector<Seat>(5)},
    {"Jurassic Park", 9.50, vector<Seat>(5)},
    {"The Lord of the Rings", 13.50, vector<Seat>(5)},
    };
    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies[i].seats.size(); j++) {
            movies[i].seats[j].number = j + 1;
        }
    }
    double totalPrice = 0;
    vector<Seat> seats(5);

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
        for (int i = 0; i < movies[movieChoice - 1].seats.size(); i++) {
            cout << "Seat "
                << movies[movieChoice - 1].seats[i].number
                << (movies[movieChoice - 1].seats[i].booked
                    ? " (Booked)"
                    : " (Available)")
                << endl;
        }

        int seatChoice;
        cout << "\nPick seat: ";
        cin >> seatChoice;

        if (seatChoice < 1 ||
            seatChoice > movies[movieChoice - 1].seats.size()) {
                    cout << "Invalid seat!\n";
                    continue;
                }

                if (movies[movieChoice - 1].seats[seatChoice - 1].booked) {
                    cout << "Seat already booked!\n";
                }
                else {
                    movies[movieChoice - 1].seats[seatChoice - 1].booked = true; 
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
