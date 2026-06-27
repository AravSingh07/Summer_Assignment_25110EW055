#include<bits/stdc++.h>
class Student {
private:
    int rollNumber;
    std::string name;
    int age;
    double gpa;

public:
    // Constructor
    Student(int roll, std::string studentName, int studentAge, double studentGpa) 
        : rollNumber(roll), name(studentName), age(studentAge), gpa(studentGpa) {}

    // Getters
    int getRollNumber() const { return rollNumber; }
    std::string getName() const { return name; }
    int getAge() const { return age; }
    double getGpa() const { return gpa; }

    // Setters for updating records
    void setName(std::string newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }
    void setGpa(double newGpa) { gpa = newGpa; }

    // Display student details in a formatted row
    void displayRow() const {
        std::cout << std::left << std::setw(15) << rollNumber 
                  << std::setw(25) << name 
                  << std::setw(10) << age 
                  << std::setw(10) << std::fixed << std::setprecision(2) << gpa << "\n";
    }
};

class StudentManager {
private:
    std::vector<Student> students;

    // Helper method to find student index by Roll Number
    int findStudentIndex(int rollNumber) {
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i].getRollNumber() == rollNumber) {
                return i;
            }
        }
        return -1; // Not found
    }

public:
    // 1. Add a new student record
    void addStudent() {
        int roll, age;
        std::string name;
        double gpa;

        std::cout << "\n--- Add New Student ---\n";
        std::cout << "Enter Roll Number: ";
        while (!(std::cin >> roll)) {
            std::cout << "Invalid input. Enter an integer for Roll Number: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Check for duplicate Roll Number
        if (findStudentIndex(roll) != -1) {
            std::cout << "Error: A student with Roll Number " << roll << " already exists!\n";
            return;
        }

        std::cin.ignore(); // Clear newline buffer
        std::cout << "Enter Full Name: ";
        std::getline(std::cin, name);

        std::cout << "Enter Age: ";
        while (!(std::cin >> age) || age <= 0) {
            std::cout << "Invalid input. Enter a valid positive age: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Enter GPA (0.0 - 4.0): ";
        while (!(std::cin >> gpa) || gpa < 0.0 || gpa > 4.0) {
            std::cout << "Invalid input. Enter a valid GPA between 0.0 and 4.0: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        students.push_back(Student(roll, name, age, gpa));
        std::cout << "Student record added successfully!\n";
    }

    // 2. View all student records
    void viewAllStudents() const {
        if (students.empty()) {
            std::cout << "\nNo student records found.\n";
            return;
        }

        std::cout << "\n------------------------------------------------------------\n";
        std::cout << std::left << std::setw(15) << "Roll Number" 
                  << std::setw(25) << "Name" 
                  << std::setw(10) << "Age" 
                  << std::setw(10) << "GPA" << "\n";
        std::cout << "------------------------------------------------------------\n";
        
        for (const auto& student : students) {
            student.displayRow();
        }
        std::cout << "------------------------------------------------------------\n";
    }

    // 3. Search for a specific student
    void searchStudent() {
        if (students.empty()) {
            std::cout << "\nNo records available to search.\n";
            return;
        }

        int roll;
        std::cout << "\nEnter Roll Number to search: ";
        std::cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            std::cout << "\nRecord Found:\n";
            std::cout << "------------------------------------------------------------\n";
            std::cout << std::left << std::setw(15) << "Roll Number" 
                      << std::setw(25) << "Name" 
                      << std::setw(10) << "Age" 
                      << std::setw(10) << "GPA" << "\n";
            std::cout << "------------------------------------------------------------\n";
            students[index].displayRow();
            std::cout << "------------------------------------------------------------\n";
        } else {
            std::cout << "Student with Roll Number " << roll << " not found.\n";
        }
    }

    // 4. Update an existing student record
    void updateStudent() {
        if (students.empty()) {
            std::cout << "\nNo records available to update.\n";
            return;
        }

        int roll;
        std::cout << "\nEnter Roll Number to update: ";
        std::cin >> roll;

        int index = findStudentIndex(roll);
        if (index == -1) {
            std::cout << "Student with Roll Number " << roll << " not found.\n";
            return;
        }

        std::string newName;
        int newAge;
        double newGpa;

        std::cin.ignore();
        std::cout << "Enter New Name (Leave blank to keep current: " << students[index].getName() << "): ";
        std::getline(std::cin, newName);
        if (!newName.empty()) {
            students[index].setName(newName);
        }

        std::cout << "Enter New Age (Enter 0 to keep current: " << students[index].getAge() << "): ";
        while (!(std::cin >> newAge) || newAge < 0) {
            std::cout << "Invalid input. Enter a positive integer: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (newAge != 0) {
            students[index].setAge(newAge);
        }

        std::cout << "Enter New GPA (Enter -1 to keep current: " << students[index].getGpa() << "): ";
        while (!(std::cin >> newGpa) || (newGpa < 0.0 && newGpa != -1.0) || newGpa > 4.0) {
            std::cout << "Invalid input. Enter a valid GPA (0.0 - 4.0): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (newGpa != -1.0) {
            students[index].setGpa(newGpa);
        }

        std::cout << "Student record updated successfully!\n";
    }

    // 5. Delete a student record
    void deleteStudent() {
        if (students.empty()) {
            std::cout << "\nNo records available to delete.\n";
            return;
        }

        int roll;
        std::cout << "\nEnter Roll Number to delete: ";
        std::cin >> roll;

        int index = findStudentIndex(roll);
        if (index != -1) {
            students.erase(students.begin() + index);
            std::cout << "Student record deleted successfully!\n";
        } else {
            std::cout << "Student with Roll Number " << roll << " not found.\n";
        }
    }
};

int main() {
    StudentManager manager;
    int choice;

    do {
        std::cout << "\n=================================\n";
        std::cout << " STUDENT RECORD SYSTEM MENU\n";
        std::cout << "=================================\n";
        std::cout << "1. Add Student Record\n";
        std::cout << "2. View All Student Records\n";
        std::cout << "3. Search Student Record\n";
        std::cout << "4. Update Student Record\n";
        std::cout << "5. Delete Student Record\n";
        std::cout << "6. Exit\n";
        std::cout << "---------------------------------\n";
        std::cout << "Enter your choice (1-6): ";
        
        while (!(std::cin >> choice) || choice < 1 || choice > 6) {
            std::cout << "Invalid selection. Please enter a number from 1 to 6: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1: manager.addStudent(); break;
            case 2: manager.viewAllStudents(); break;
            case 3: manager.searchStudent(); break;
            case 4: manager.updateStudent(); break;
            case 5: manager.deleteStudent(); break;
            case 6: std::cout << "\nExiting program. Goodbye!\n"; break;
        }
    } while (choice != 6);

    return 0;
}
