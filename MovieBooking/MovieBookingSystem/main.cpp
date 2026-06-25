
#include <iostream>
#include <vector>

#include "models/Movie.h"
#include "models/Seat.h"

using namespace std;

int main() {

    // MOVIES
    vector<Movie> movies = {
    {"Avengers", "English", "Action", "2019", 12.50, vector<Seat>(5)},
    {"Frozen", "Bulgarian", "Animation", "2013", 10.00, vector<Seat>(5)},
    {"Batman", "Russian", "Action", "2022", 11.50, vector<Seat>(5)},
    {"Fight Club", "German", "Drama", "1999", 14.50, vector<Seat>(5)},
    {"Minions", "Spanish", "Animation", "2015", 9.50, vector<Seat>(5)},
    {"Barbie", "English", "Comedy", "2023", 15.50, vector<Seat>(5)},
    {"Star Wars", "English", "Sci-Fi", "1977", 13.50, vector<Seat>(5)},
    {"Titanic", "Spanish", "Romance", "1997", 10.50, vector<Seat>(5)},
    {"Spiderman", "English", "Action", "2021", 12.50, vector<Seat>(5)},
    {"Interstellar", "English", "Sci-Fi", "2014", 16.50, vector<Seat>(5)},
    {"Forrest Gump", "Russian", "Drama", "1994", 11.50, vector<Seat>(5)},
    {"Moana", "Bulgarian", "Animation", "2016", 9.50, vector<Seat>(5)},
    {"The Matrix", "English", "Sci-Fi", "1999", 9.50, vector<Seat>(5)},
    {"Jurassic Park", "English", "Adventure", "1993", 9.50, vector<Seat>(5)},
    {"The Lord of the Rings", "English", "Fantasy", "2001", 13.50, vector<Seat>(5)}
    };
    for (int i = 0; i < movies.size(); i++) {
        for (int j = 0; j < movies[i].seats.size(); j++) {

            movies[i].seats[j].number = j + 1;

            if (j < 2)
                movies[i].seats[j].type = SILVER;

            else if (j < 4)
                movies[i].seats[j].type = GOLD;

            else
                movies[i].seats[j].type = PLATINUM;
        }
    }
    double totalPrice = 0;
    vector<Seat> seats(5);

    while (true) {

        // MAIN MENU
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Book seat\n";
        cout << "2. Search movies\n";
        cout << "3. Admin\n";
        cout << "4. Exit\n";
        cout << "Choice: ";
        int choice;
        cin >> choice;

        if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }

        
        if (choice == 2) {

            cout << "\nSearch by:\n";
            cout << "1. Title\n";
            cout << "2. Language\n";
            cout << "3. Genre\n";
            cout << "4. Release Date\n";
            cout << "Choice: ";

            int searchChoice;
            cin >> searchChoice;

            string searchText;

            cout << "Enter search value: ";
            cin.ignore();
            getline(cin, searchText);

            cout << "\n=== Results ===\n";

            bool found = false;

            for (int i = 0; i < movies.size(); i++) {

                if (searchChoice == 1 &&
                    movies[i].title == searchText) {

                    cout << movies[i].title << endl;
                    found = true;
                }

                else if (searchChoice == 2 &&
                    movies[i].language == searchText) {

                    cout << movies[i].title << endl;
                    found = true;
                }

                else if (searchChoice == 3 &&
                    movies[i].genre == searchText) {

                    cout << movies[i].title << endl;
                    found = true;
                }

                else if (searchChoice == 4 &&
                    movies[i].releaseDate == searchText) {

                    cout << movies[i].title << endl;
                    found = true;
                }
            }

            if (!found) {
                cout << "No movies found.\n";
            }

            continue;
        }
        if (choice == 3) {

            cout << "\n=== ADMIN MENU ===\n";
            cout << "1. Add Movie\n";
            cout << "2. Delete Movie\n";
            cout << "Choice: ";

            int adminChoice;
            cin >> adminChoice;

            if (adminChoice == 1) {

                string title;
                string language;
                string genre;
                string releaseDate;
                double price;

                cin.ignore();

                cout << "Title: ";
                getline(cin, title);

                cout << "Language: ";
                getline(cin, language);

                cout << "Genre: ";
                getline(cin, genre);

                cout << "Release Date: ";
                getline(cin, releaseDate);

                cout << "Price: ";
                cin >> price;

                Movie newMovie{
                    title,
                    language,
                    genre,
                    releaseDate,
                    price,
                    vector<Seat>(5)
                };

                movies.push_back(newMovie);
                for (int j = 0; j < movies.back().seats.size(); j++) {

                    movies.back().seats[j].number = j + 1;

                    if (j < 2)
                        movies.back().seats[j].type = SILVER;

                    else if (j < 4)
                        movies.back().seats[j].type = GOLD;

                    else
                        movies.back().seats[j].type = PLATINUM;
                }
                cout << "Movie added successfully!\n";
            }

            else if (adminChoice == 2) {

                cout << "\n=== MOVIES ===\n";

                for (int i = 0; i < movies.size(); i++) {
                    cout << i + 1 << ". "
                        << movies[i].title
                        << endl;
                }

                int deleteChoice;

                cout << "Select movie to delete: ";
                cin >> deleteChoice;

                if (deleteChoice >= 1 &&
                    deleteChoice <= movies.size()) {

                    movies.erase(
                        movies.begin()
                        + (deleteChoice - 1)
                    );

                    cout << "Movie deleted!\n";
                }
                else {
                    cout << "Invalid movie!\n";
                }
            }

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
                << movies[movieChoice - 1].seats[i].number;

            if (movies[movieChoice - 1].seats[i].type == SILVER)
                cout << " (Silver)";

            else if (movies[movieChoice - 1].seats[i].type == GOLD)
                cout << " (Gold)";

            else
                cout << " (Platinum)";

            cout << (movies[movieChoice - 1].seats[i].booked
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
                    double ticketPrice = movies[movieChoice - 1].price;

                    SeatType type =
                        movies[movieChoice - 1].seats[seatChoice - 1].type;

                    if (type == GOLD)
                        ticketPrice += 5;

                    else if (type == PLATINUM)
                        ticketPrice += 10;

                    

                    totalPrice += ticketPrice;

                    cout << "Booking successful for "
                        << movies[movieChoice - 1].title
                        << " at seat " << seatChoice << endl;

                    cout << "Ticket price: $"
                        << ticketPrice << endl;

                    cout << "Current total: $"
                        << totalPrice << endl;
                    while (true) {
                        cout << "\n=== NEXT ACTION ===\n";
                        cout << "1. Main menu\n";
                        cout << "2. Pay\n";
                        cout << "3. Exit\n";
                        cout << "Choice: ";

                        int nextChoice;
                        cin >> nextChoice;

                        if (nextChoice == 1) {
                            break;
                        }
                        else if (nextChoice == 2) {

                            cout << "\nBooking type:\n";
                            cout << "1. Online\n";
                            cout << "2. Walk-in\n";
                            cout << "Choice: ";

                            int bookingType;
                            cin >> bookingType;

                            // payment logic goes here

                            // PAYMENT OPTIONS
                            if (bookingType == 1) {

                                cout << "Online customers must pay by card.\n";

                                cout << "\n===== RECEIPT =====\n";
                                cout << "Total amount: $" << totalPrice << endl;

                                cout << "Payment successful!\n";
                            }
                            else if (bookingType == 2) {

                                cout << "\nPayment method:\n";
                                cout << "1. Cash\n";
                                cout << "2. Card\n";
                                cout << "Choice: ";

                                int paymentChoice;
                                cin >> paymentChoice;

                                if (paymentChoice != 1 && paymentChoice != 2) {
                                    cout << "Invalid payment option.\n";
                                    continue;
                                }

                                cout << "\n===== RECEIPT =====\n";
                                cout << "Total amount: $" << totalPrice << endl;

                                cout << "Payment successful!\n";
                            }
                            else {
                                cout << "Invalid booking type.\n";
                            }
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
