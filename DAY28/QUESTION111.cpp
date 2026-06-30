#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class representing an individual Show/Movie
class Show {
private:
    string movieName;
    string timeSlot;
    double price;
    vector<vector<int>> seats; // 0 = Available, 1 = Booked
    int rows;
    int cols;

public:
    Show(string name, string time, double ticketPrice, int r = 5, int c = 6) {
        movieName = name;
        timeSlot = time;
        price = ticketPrice;
        rows = r;
        cols = c;
        // Initialize all seats to 0 (Available)
        seats.resize(rows, vector<int>(cols, 0));
    }

    string getMovieName() const { return movieName; }
    string getTimeSlot() const { return timeSlot; }
    double getPrice() const { return price; }

    // Displays the visual grid of seats
    void displaySeats() const {
        cout << "\n--- Seating Arrangement for " << movieName << " (" << timeSlot << ") ---\n";
        cout << "      ";
        for (int j = 0; j < cols; j++) {
            cout << "Col" << j + 1 << " ";
        }
        cout << "\n";

        for (int i = 0; i < rows; i++) {
            cout << "Row " << i + 1 << "  ";
            for (int j = 0; j < cols; j++) {
                if (seats[i][j] == 0) {
                    cout << "[ 0 ] "; // Available
                } else {
                    cout << "[ 1 ] "; // Booked
                }
            }
            cout << "\n";
        }
        cout << "Screen This Way (Front)\n\n";
    }

    // Handles the seat booking logic
    bool bookSeat(int r, int c) {
        if (r < 1 || r > rows || c < 1 || c > cols) {
            cout << "Error: Invalid row or column selection.\n";
            return false;
        }
        if (seats[r - 1][c - 1] == 1) {
            cout << "Error: Seat is already booked. Please choose another.\n";
            return false;
        }
        seats[r - 1][c - 1] = 1; // Mark as booked
        return true;
    }
};

// System coordinator class
class TicketBookingSystem {
private:
    vector<Show> shows;

public:
    void addShow(const Show& s) {
        shows.push_back(s);
    }

    // Displays all available shows
    void listShows() const {
        cout << "\n================ Available Shows ================\n";
        cout << left << setw(5) << "ID" << setw(25) << "Movie Name" << setw(15) << "Time Slot" << setw(10) << "Price" << "\n";
        cout << "-------------------------------------------------\n";
        for (size_t i = 0; i < shows.size(); ++i) {
            cout << left << setw(5) << i + 1 
                 << setw(25) << shows[i].getMovieName() 
                 << setw(15) << shows[i].getTimeSlot() 
                 << "$" << fixed << setprecision(2) << shows[i].getPrice() << "\n";
        }
        cout << "=================================================\n";
    }

    // Direct interface handler for booking
    void processBooking() {
        listShows();
        int showChoice;
        cout << "Enter the Show ID you want to book: ";
        cin >> showChoice;

        if (showChoice < 1 || showChoice > static_cast<int>(shows.size())) {
            cout << "Invalid Show ID.\n";
            return;
        }

        Show& selectedShow = shows[showChoice - 1];
        selectedShow.displaySeats();

        int row, col;
        cout << "Enter Row number: ";
        cin >> row;
        cout << "Enter Column number: ";
        cin >> col;

        if (selectedShow.bookSeat(row, col)) {
            cout << "\n🎉 Booking Successful! 🎉\n";
            cout << "Ticket Details:\n";
            cout << "Movie: " << selectedShow.getMovieName() << "\n";
            cout << "Time: " << selectedShow.getTimeSlot() << "\n";
            cout << "Seat: Row " << row << ", Col " << col << "\n";
            cout << "Total Paid: $" << selectedShow.getPrice() << "\n";
        }
    }

    // View specific show layout
    void checkSeatAvailability() const {
        listShows();
        int showChoice;
        cout << "Enter Show ID to check seats: ";
        cin >> showChoice;

        if (showChoice < 1 || showChoice > static_cast<int>(shows.size())) {
            cout << "Invalid Show ID.\n";
            return;
        }
        shows[showChoice - 1].displaySeats();
    }
};

int main() {
    TicketBookingSystem system;

    // Seeding initial show data
    system.addShow(Show("Inception", "10:00 AM", 12.50));
    system.addShow(Show("The Dark Knight", "01:30 PM", 14.00));
    system.addShow(Show("Interstellar", "06:00 PM", 15.00));
    system.addShow(Show("Avatar 2", "09:30 PM", 18.50));

    int choice;
    do {
        cout << "\n===== TICKET BOOKING SYSTEM =====\n";
        cout << "1. View Available Movies\n";
        cout << "2. Check Seat Availability\n";
        cout << "3. Book a Ticket\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.listShows();
                break;
            case 2:
                system.checkSeatAvailability();
                break;
            case 3:
                system.processBooking();
                break;
            case 4:
                cout << "Thank you for using the Ticket Booking System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please pick options between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}
