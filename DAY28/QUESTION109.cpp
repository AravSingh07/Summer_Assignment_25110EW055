#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Class representing a single Book
class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    // Constructor to initialize book details
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
    bool getIssuedStatus() const { return isIssued; }

    // Methods to change issue status
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

    // Display book details in a tabular format
    void displayBook() const {
        cout << left << setw(10) << id 
             << setw(30) << title 
             << setw(25) << author 
             << (isIssued ? "Issued" : "Available") << endl;
    }
};

// Class managing the Library collection and operations
class Library {
private:
    vector<Book> books;

public:
    // 1. Add a new book to the library
    void addBook() {
        int id;
        string title, author;

        cout << "\nEnter Book ID (Integer): ";
        cin >> id;
        
        // Check if ID already exists to avoid duplication
        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "Error: A book with this ID already exists!\n";
                return;
            }
        }

        cin.ignore(); // Clear newline character from buffer
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    // 2. Display all books in the library
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "\nThe library is currently empty.\n";
            return;
        }

        cout << "\n-----------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(25) << "Author" << "Status" << endl;
        cout << "-----------------------------------------------------------------------\n";
        for (const auto& book : books) {
            book.displayBook();
        }
        cout << "-----------------------------------------------------------------------\n";
    }

    // 3. Search for a book by its unique ID
    void searchBook() const {
        if (books.empty()) {
            cout << "\nThe library is empty.\n";
            return;
        }

        int id;
        cout << "\nEnter Book ID to search: ";
        cin >> id;

        for (const auto& book : books) {
            if (book.getId() == id) {
                cout << "\nBook Found:\n";
                cout << "-----------------------------------------------------------------------\n";
                book.displayBook();
                cout << "-----------------------------------------------------------------------\n";
                return;
            }
        }
        cout << "Book with ID " << id << " not found.\n";
    }

    // 4. Issue a book to a user
    void issueBook() {
        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (book.getIssuedStatus()) {
                    cout << "Book is already issued to someone else.\n";
                } else {
                    book.issueBook();
                    cout << "Book successfully issued!\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " does not exist.\n";
    }

    // 5. Return an issued book back to the library
    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (auto& book : books) {
            if (book.getId() == id) {
                if (!book.getIssuedStatus()) {
                    cout << "This book was not issued. It is already in the library.\n";
                } else {
                    book.returnBook();
                    cout << "Book successfully returned to the library!\n";
                }
                return;
            }
        }
        cout << "Book with ID " << id << " does not exist.\n";
    }
};

int main() {
    Library myLibrary;
    int choice;

    // Menu-driven loop
    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

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
                cout << "\nThank you for using the Library Management System!\n";
                break;
            default:
                cout << "Invalid choice! Please select an option between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}
