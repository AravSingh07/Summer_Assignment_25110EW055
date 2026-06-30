#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Global constant to set maximum database capacity
const int MAX_STUDENTS = 100;

// Function Prototypes (Declarations)
void displayMenu();
void addStudent(string names[], int rollNumbers[], float grades[], int& currentCount);
void displayAllStudents(const string names[], const int rollNumbers[], const float grades[], int currentCount);
void searchStudent(const string names[], const int rollNumbers[], const float grades[], int currentCount);
void updateGrade(const string names[], const int rollNumbers[], float grades[], int currentCount);

int main() {
    // Parallel Arrays tracking distinct properties by shared index positions
    string studentNames[MAX_STUDENTS];
    int studentRolls[MAX_STUDENTS];
    float studentGrades[MAX_STUDENTS];
    
    int studentCount = 0; // Tracks the current active number of student entries
    int choice;

    cout << "=========================================\n";
    cout << "   Welcome to the Student System Mini-Project \n";
    cout << "=========================================\n";

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        
        // Handle non-integer inputs gracefully to prevent infinite loops
        if (!(cin >> choice)) {
            cout << "Invalid system input! Please enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(studentNames, studentRolls, studentGrades, studentCount);
                break;
            case 2:
                displayAllStudents(studentNames, studentRolls, studentGrades, studentCount);
                break;
            case 3:
                searchStudent(studentNames, studentRolls, studentGrades, studentCount);
                break;
            case 4:
                updateGrade(studentNames, studentRolls, studentGrades, studentCount);
                break;
            case 5:
                cout << "\nExiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please select between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}

// Function to print the main UI options menu
void displayMenu() {
    cout << "\n--- Main Options Menu ---\n";
    cout << "1. Add New Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Search Student by Roll Number\n";
    cout << "4. Update Student Grade\n";
    cout << "5. Exit Project\n";
    cout << "-------------------------\n";
}

// Function to insert a student entry into the parallel arrays
void addStudent(string names[], int rollNumbers[], float grades[], int& currentCount) {
    if (currentCount >= MAX_STUDENTS) {
        cout << "Error: Database is full! Cannot add more students.\n";
        return;
    }

    cout << "\nEnter student roll number: ";
    int roll;
    cin >> roll;

    // Data Validation: Check if roll number already exists
    for (int i = 0; i < currentCount; i++) {
        if (rollNumbers[i] == roll) {
            cout << "Error: A student with Roll Number " << roll << " already exists!\n";
            return;
        }
    }

    rollNumbers[currentCount] = roll;

    cout << "Enter student full name: ";
    cin.ignore(); // Clear newline buffer left by previous cin
    getline(cin, names[currentCount]); // Using string library to capture full names with spaces

    cout << "Enter student grade/marks (0.0 - 100.0): ";
    cin >> grades[currentCount];

    currentCount++; // Increment trackers to save space allocations
    cout << "Student record added successfully!\n";
}

// Function to safely display all entries using iterative arrays loops
void displayAllStudents(const string names[], const int rollNumbers[], const float grades[], int currentCount) {
    if (currentCount == 0) {
        cout << "\nNo student records found in the system database.\n";
        return;
    }

    cout << "\n-----------------------------------------------------\n";
    cout << left << setw(12) << "Roll No" << setw(25) << "Student Name" << setw(10) << "Grade" << endl;
    cout << "-----------------------------------------------------\n";

    for (int i = 0; i < currentCount; i++) {
        cout << left << setw(12) << rollNumbers[i] 
             << setw(25) << names[i] 
             << setw(10) << fixed << setprecision(2) << grades[i] << endl;
    }
    cout << "-----------------------------------------------------\n";
}

// Function to perform a linear search using structural arrays
void searchStudent(const string names[], const int rollNumbers[], const float grades[], int currentCount) {
    if (currentCount == 0) {
        cout << "\nDatabase is empty. Nothing to search.\n";
        return;
    }

    int searchRoll;
    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < currentCount; i++) {
        if (rollNumbers[i] == searchRoll) {
            cout << "\n--- Student Record Found! ---\n";
            cout << "Roll Number : " << rollNumbers[i] << endl;
            cout << "Full Name   : " << names[i] << endl;
            cout << "Current Grade: " << fixed << setprecision(2) << grades[i] << endl;
            return; // Exit function immediately when found
        }
    }
    cout << "Student with Roll Number " << searchRoll << " not found.\n";
}

// Function to update an existing element using references
void updateGrade(const string names[], const int rollNumbers[], float grades[], int currentCount) {
    if (currentCount == 0) {
        cout << "\nDatabase is empty. Nothing to update.\n";
        return;
    }

    int searchRoll;
    cout << "\nEnter Roll Number to update grade: ";
    cin >> searchRoll;

    for (int i = 0; i < currentCount; i++) {
        if (rollNumbers[i] == searchRoll) {
            cout << "Modifying record for: " << names[i] << " (Current Grade: " << grades[i] << ")\n";
            cout << "Enter new grade: ";
            cin >> grades[i];
            cout << "Grade updated successfully!\n";
            return;
        }
    }
    cout << "Student with Roll Number " << searchRoll << " not found.\n";
}