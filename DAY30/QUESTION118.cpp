#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// Class representing an individual book
class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    // Constructor to initialize book properties
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }

    // Getter methods
    int getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssueStatus() const { return isIssued; }

    // Methods to change issue status
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    // Helper method to convert string to lowercase for case-insensitive search
    static string toLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

    // Display individual book details in table format
    void displayBook() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << setw(15) << (isIssued ? "Issued" : "Available") << "\n";
    }
};

// Class managing the collection of books
class Library {
private:
    vector<Book> books;

public:
    // 1. Add a new book to the library inventory
    void addBook() {
        int id;
        string title, author;

        cout << "\n--- Add New Book ---\n";
        cout << "Enter Book ID (Numeric): ";
        while (!(cin >> id)) {
            cout << "Invalid input. Please enter a numeric ID: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        cin.ignore(); // Clear newline character from buffer

        // Check for duplicate ID
        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "Error: A book with ID " << id << " already exists!\n";
                return;
            }
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book successfully added to the system!\n";
    }

    // 2. Display all books currently registered in the library
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\nThe library inventory is currently empty.\n";
            return;
        }

        cout << "\n--------------------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(25) << "Author" << setw(15) << "Status" << "\n";
        cout << "--------------------------------------------------------------------------------\n";
        for (const auto& book : books) {
            book.displayBook();
        }
        cout << "--------------------------------------------------------------------------------\n";
    }

    // 3. Search for a book matching a specific title keyword
    void searchBook() const {
        if (books.empty()) {
            cout << "\nThe library inventory is empty. Nothing to search.\n";
            return;
        }

        cin.ignore();
        string searchTitle;
        cout << "\nEnter Book Title to search: ";
        getline(cin, searchTitle);

        string lowerSearch = Book::toLower(searchTitle);
        bool found = false;

        cout << "\n--- Search Results ---\n";
        for (const auto& book : books) {
            if (Book::toLower(book.getTitle()).find(lowerSearch) != string::npos) {
                if (!found) {
                    cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(25) << "Author" << setw(15) << "Status" << "\n";
                    cout << "--------------------------------------------------------------------------------\n";
                }
                book.displayBook();
                found = true;
            }
        }

        if (!found) {
            cout << "No books found matching \"" << searchTitle << "\".\n";
        }
    }

    // 4. Check out a book to a user
    void issueBook() {
        if (books.empty()) {
            cout << "\nNo books available to issue.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (book.getIssueStatus()) {
                    cout << "This book is already checked out (Issued).\n";
                } else {
                    book.issueBook();
                    cout << "Book successfully issued!\n";
                }
                return;
            }
        }
        cout << "Book ID not found in the system.\n";
    }

    // 5. Accept a returned book back into inventory
    void returnBook() {
        if (books.empty()) {
            cout << "\nNo books registered to return.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (!book.getIssueStatus()) {
                    cout << "This book is already available in the library.\n";
                } else {
                    book.returnBook();
                    cout << "Book successfully returned to inventory!\n";
                }
                return;
            }
        }
        cout << "Book ID not found in the system.\n";
    }
};

// Main function managing the menu-driven logic
int main() {
    Library myLibrary;
    int choice;

    while (true) {
        cout << "\n===============================\n";
        cout << "      MINI LIBRARY SYSTEM      \n";
        cout << "===============================\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by Title\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit Application\n";
        cout << "-------------------------------\n";
        cout << "Enter your choice (1-6): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
            cin.clear();
            cin.ignore(123, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                myLibrary.addBook();
                break;
            case 2:
                myLibrary.displayAllBooks();
                break;
            case 3:
                myLibrary.searchBook();
                break;
            case 4:
                myLibrary.issueBook();
                break;
            case 5:
                myLibrary.returnBook();
                break;
            case 6:
                cout << "\nThank you for using the Mini Library System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid selection. Please choose an option from 1 to 6.\n";
        }
    }
    return 0;
}
