#include<bits/stdc++.h>
using namespace std;

// Structure to group subject attributes
struct Subject {
    string name;
    double marks;
};

class Marksheet {
private:
    string studentName;
    int rollNumber;
    string className;
    vector<Subject> subjects;
    double totalMarks;
    double percentage;
    bool isPassed;

    // Internal logic to validate mark parameters
    double inputValidMarks(const string& subjectName) {
        double mark;
        while (true) {
            cout << "Enter marks for " << subjectName << " (0-100): ";
            if (cin >> mark && mark >= 0 && mark <= 100) {
                return mark;
            }
            cout << "⚠️ Invalid input! Please enter a numeric value between 0 and 100.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Internal calculation engine
    void calculateResults() {
        totalMarks = 0;
        isPassed = true; // Remains true unless a subject fails
        
        for (const auto& sub : subjects) {
            totalMarks += sub.marks;
            if (sub.marks < 40) { // 40 is the minimum passing threshold per subject
                isPassed = false;
            }
        }
        
        percentage = (totalMarks / (subjects.size() * 100)) * 100;
    }

    // Grade boundary evaluation 
    char computeGrade() const {
        if (!isPassed) return 'F';
        if (percentage >= 90) return 'A';
        if (percentage >= 80) return 'B';
        if (percentage >= 70) return 'C';
        if (percentage >= 60) return 'D';
        if (percentage >= 40) return 'E';
        return 'F';
    }

public:
    // Core data entry interface
    void inputDetails() {
        cout << "========================================\n";
        cout << "      ENTER STUDENT INFORMATION         \n";
        cout << "========================================\n";
        cout << "Enter Student Full Name: ";
        cin.ignore();
        getline(cin, studentName);
        
        cout << "Enter Roll Number: ";
        while (!(cin >> rollNumber) || rollNumber <= 0) {
            cout << "⚠️ Invalid Roll Number! Enter a positive integer: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Enter Class/Grade: ";
        cin.ignore();
        getline(cin, className);

        // Subject list initialization
        vector<string> subjectNames = {"Mathematics", "Physics", "Chemistry", "English", "Computer Science"};
        subjects.clear();
        
        cout << "\n----------------------------------------\n";
        cout << "             ENTER MARKS                \n";
        cout << "----------------------------------------\n";
        for (const auto& name : subjectNames) {
            double m = inputValidMarks(name);
            subjects.push_back({name, m});
        }

        calculateResults();
    }

    // Visual layout generation
    void printMarksheet() const {
        cout << "\n\n";
        cout << "=======================================================\n";
        cout << "                ACADEMIC PERFORMANCE REPORT            \n";
        cout << "=======================================================\n";
        cout << left << setw(15) << "Student Name:" << setw(20) << studentName 
             << setw(12) << "Roll No:" << rollNumber << "\n";
        cout << left << setw(15) << "Class:" << setw(20) << className << "\n";
        cout << "-------------------------------------------------------\n";
        cout << left << setw(5) << "S.No" << setw(25) << "Subject" 
             << setw(12) << "Max Marks" << setw(12) << "Obtained" << "\n";
        cout << "-------------------------------------------------------\n";

        for (size_t i = 0; i < subjects.size(); ++i) {
            cout << left << setw(5) << (i + 1) 
                 << setw(25) << subjects[i].name 
                 << setw(12) << "100" 
                 << setw(12) << fixed << setprecision(1) << subjects[i].marks << "\n";
        }

        cout << "-------------------------------------------------------\n";
        cout << left << setw(30) << "Aggregate Marks:" << totalMarks << " / " << (subjects.size() * 100) << "\n";
        cout << left << setw(30) << "Percentage:" << fixed << setprecision(2) << percentage << "%\n";
        cout << left << setw(30) << "Final Grade:" << computeGrade() << "\n";
        cout << left << setw(30) << "Status:";
        
        if (isPassed) {
            cout << "PASSED 🎉\n";
        } else {
            cout << "FAILED ❌ (Deficit marks in one or more papers)\n";
        }
        cout << "=======================================================\n";
    }
};

int main() {
    Marksheet studentRecord;
    char choice;

    do {
        studentRecord.inputDetails();
        studentRecord.printMarksheet();

        cout << "\nDo you want to generate another marksheet? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "\nExiting system. Have a great day!\n";
    return 0;
}
