#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Define a maximum limit for the student array
const int MAX_STUDENTS = 100;

// Structure to group student data using strings and basic types
struct Student {
    int rollNumber;
    string name;
    string course;
    float marks;
};

// Function declarations for modularity
void addStudentRecord(Student students[], int &currentCount);
void displayAllRecords(const Student students[], int currentCount);
void searchStudentRecord(const Student students[], int currentCount);

int main() {
    Student students[MAX_STUDENTS]; // Array of structures to store student records
    int currentCount = 0;           // Keeps track of the total records inserted
    int choice;

    do {
        // Main Menu Display
        cout << "\n====================================\n";
        cout << "    STUDENT RECORD SYSTEM (ARRAYS)  \n";
        cout << "====================================\n";
        cout << "1. Add Student Record\n";
        cout << "2. Display All Student Records\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        
        // Input validation for menu choices
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudentRecord(students, currentCount);
                break;
            case 2:
                displayAllRecords(students, currentCount);
                break;
            case 3:
                searchStudentRecord(students, currentCount);
                break;
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option! Please pick a selection from 1 to 4.\n";
        }
    } while (choice != 4);

    return 0;
}

// Function to add a student record
void addStudentRecord(Student students[], int &currentCount) {
    if (currentCount >= MAX_STUDENTS) {
        cout << "Database Full! Cannot add more records.\n";
        return;
    }

    Student newStudent;
    cout << "\nEnter Roll Number: ";
    cin >> newStudent.rollNumber;

    // Check for duplicate Roll Numbers
    for (int i = 0; i < currentCount; i++) {
        if (students[i].rollNumber == newStudent.rollNumber) {
            cout << "Error: A student with Roll Number " << newStudent.rollNumber << " already exists!\n";
            return;
        }
    }

    // Clear the input buffer before reading strings with spaces
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Full Name: ";
    getline(cin, newStudent.name);

    cout << "Enter Course/Class: ";
    getline(cin, newStudent.course);

    cout << "Enter Total Marks: ";
    cin >> newStudent.marks;

    // Save to the fixed-size array and increment total count
    students[currentCount] = newStudent;
    currentCount++;

    cout << "Record saved successfully!\n";
}

// Function to display all saved records
void displayAllRecords(const Student students[], int currentCount) {
    if (currentCount == 0) {
        cout << "\nNo records found in the database.\n";
        return;
    }

    cout << "\n---------------------------------------------------------------\n";
    cout << "Roll No.\t| Name\t\t\t| Course\t| Marks\n";
    cout << "---------------------------------------------------------------\n";
    for (int i = 0; i < currentCount; i++) {
        cout << students[i].rollNumber << "\t\t| "
             << students[i].name << "\t\t| "
             << students[i].course << "\t\t| "
             << students[i].marks << "\n";
    }
    cout << "---------------------------------------------------------------\n";
}

// Function to search a specific record by Roll Number
void searchStudentRecord(const Student students[], int currentCount) {
    if (currentCount == 0) {
        cout << "\nNo records available to search.\n";
        return;
    }

    int targetRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> targetRoll;

    // Linear search traversal through the array
    for (int i = 0; i < currentCount; i++) {
        if (students[i].rollNumber == targetRoll) {
            cout << "\n--- Record Found ---\n";
            cout << "Roll Number : " << students[i].rollNumber << "\n";
            cout << "Name        : " << students[i].name << "\n";
            cout << "Course      : " << students[i].course << "\n";
            cout << "Marks       : " << students[i].marks << "\n";
            return;
        }
    }
    cout << "Student with Roll Number " << targetRoll << " not found.\n";
}
