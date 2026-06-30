#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Class representing a single Contact
class Contact {
private:
    string name;
    string phone;
    string email;
    string address;

public:
    // Constructor
    Contact(string n = "", string p = "", string e = "", string a = "") 
        : name(n), phone(p), email(e), address(a) {}

    // Getters
    string getName() const { return name; }
    string getPhone() const { return phone; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }

    // Setters
    void setName(const string& n) { name = n; }
    void setPhone(const string& p) { phone = p; }
    void setEmail(const string& e) { email = e; }
    void setAddress(const string& a) { address = a; }

    // Helper to display a contact in a row format
    void displayRow(int index) const {
        cout << left << setw(6) << index 
             << setw(20) << name 
             << setw(15) << phone 
             << setw(25) << email 
             << setw(20) << address << endl;
    }
};

// Class handling CRUD operations and file storage
class ContactManager {
private:
    vector<Contact> contacts;
    const string filename = "contacts.txt";

    // Load data from text file into RAM vector
    void loadFromFile() {
        contacts.clear();
        ifstream file(filename);
        if (!file.is_open()) return; // File doesn't exist yet

        string name, phone, email, address;
        // Read file line by line using custom delimiter '#'
        while (getline(file, name, '#') &&
               getline(file, phone, '#') &&
               getline(file, email, '#') &&
               getline(file, address, '\n')) {
            contacts.emplace_back(name, phone, email, address);
        }
        file.close();
    }

    // Save current vector contents back to the file
    void saveToFile() const {
        ofstream file(filename, ios::trunc); // Overwrite mode
        if (!file.is_open()) {
            cout << "\x1B[31mError saving data to file!\x1B[0m\n";
            return;
        }
        for (const auto& contact : contacts) {
            file << contact.getName() << "#"
                 << contact.getPhone() << "#"
                 << contact.getEmail() << "#"
                 << contact.getAddress() << "\n";
        }
        file.close();
    }

    // Clear stream helper to handle invalid inputs safely
    void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    ContactManager() {
        loadFromFile();
    }

    // 1. Create: Add a new contact
    void addContact() {
        string name, phone, email, address;
        clearInput();

        cout << "\n--- Add New Contact ---\n";
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Phone Number: ";
        getline(cin, phone);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Address: ";
        getline(cin, address);

        if (name.empty() || phone.empty()) {
            cout << "\x1B[31mError: Name and Phone are required fields.\x1B[0m\n";
            return;
        }

        contacts.emplace_back(name, phone, email, address);
        saveToFile();
        cout << "\x1B[32mContact added successfully!\x1B[0m\n";
    }

    // 2. Read: Display all contacts
    void displayAll() const {
        if (contacts.empty()) {
            cout << "\n\x1B[33mNo contacts available.\x1B[0m\n";
            return;
        }

        cout << "\n-----------------------------------------------------------------------------------------\n";
        cout << left << setw(6) << "S.No" 
             << setw(20) << "Name" 
             << setw(15) << "Phone" 
             << setw(25) << "Email" 
             << setw(20) << "Address" << endl;
        cout << "-----------------------------------------------------------------------------------------\n";
        
        for (size_t i = 0; i < contacts.size(); ++i) {
            contacts[i].displayRow(i + 1);
        }
        cout << "-----------------------------------------------------------------------------------------\n";
    }

    // 3. Read: Search for a contact by name
    void searchContact() {
        clearInput();
        cout << "\nEnter Name to search: ";
        string query;
        getline(cin, query);

        // Convert query to lower case for case-insensitive search
        transform(query.begin(), query.end(), query.begin(), ::tolower);

        bool found = false;
        for (size_t i = 0; i < contacts.size(); ++i) {
            string currentName = contacts[i].getName();
            transform(currentName.begin(), currentName.end(), currentName.begin(), ::tolower);

            if (currentName.find(query) != string::npos) {
                if (!found) {
                    cout << "\nMatch found:\n";
                    found = true;
                }
                contacts[i].displayRow(i + 1);
            }
        }

        if (!found) {
            cout << "\x1B[31mNo contact matches your query.\x1B[0m\n";
        }
    }

    // 4. Update: Edit a contact using its index number
    void editContact() {
        displayAll();
        if (contacts.empty()) return;

        cout << "Enter the Serial Number (S.No) to edit: ";
        size_t index;
        cin >> index;

        if (cin.fail() || index < 1 || index > contacts.size()) {
            cout << "\x1B[31mInvalid Serial Number!\x1B[0m\n";
            clearInput();
            return;
        }

        index--; // Convert to 0-based indexing
        clearInput();

        string temp;
        cout << "\n--- Leaving an item blank keeps current details ---\n";
        
        cout << "Edit Name [" << contacts[index].getName() << "]: ";
        getline(cin, temp);
        if (!temp.empty()) contacts[index].setName(temp);

        cout << "Edit Phone [" << contacts[index].getPhone() << "]: ";
        getline(cin, temp);
        if (!temp.empty()) contacts[index].setPhone(temp);

        cout << "Edit Email [" << contacts[index].getEmail() << "]: ";
        getline(cin, temp);
        if (!temp.empty()) contacts[index].setEmail(temp);

        cout << "Edit Address [" << contacts[index].getAddress() << "]: ";
        getline(cin, temp);
        if (!temp.empty()) contacts[index].setAddress(temp);

        saveToFile();
        cout << "\x1B[32mContact updated successfully!\x1B[0m\n";
    }

    // 5. Delete: Remove a contact using its index number
    void deleteContact() {
        displayAll();
        if (contacts.empty()) return;

        cout << "Enter the Serial Number (S.No) to delete: ";
        size_t index;
        cin >> index;

        if (cin.fail() || index < 1 || index > contacts.size()) {
            cout << "\x1B[31mInvalid Serial Number!\x1B[0m\n";
            clearInput();
            return;
        }

        contacts.erase(contacts.begin() + (index - 1));
        saveToFile();
        cout << "\x1B[32mContact deleted successfully!\x1B[0m\n";
    }
};

// Driver code setup with structural menu flow
int main() {
    ContactManager manager;
    int choice;

    do {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add New Contact\n";
        cout << "2. Display All Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Exit Application\n";
        cout << "=====================================\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addContact(); break;
            case 2: manager.displayAll(); break;
            case 3: manager.searchContact(); break;
            case 4: manager.editContact(); break;
            case 5: manager.deleteContact(); break;
            case 6: cout << "\nThank you for using CMS!\n"; break;
            default: 
                cout << "\x1B[31mInvalid selection. Please input numbers 1-6.\x1B[0m\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 6);

    return 0;
}
