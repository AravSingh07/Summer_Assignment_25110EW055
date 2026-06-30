#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Class representing an individual employee
class Employee {
private:
    int id;
    string name;
    string designation;
    double salary;

public:
    // Constructor to initialize employee details
    Employee(int empId, string empName, string empDesignation, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesignation;
        salary = empSalary;
    }

    // Getter methods
    int getId() const { return id; }
    string getName() const { return name; }
    string getDesignation() const { return designation; }
    double getSalary() const { return salary; }

    // Display individual employee record in a table row format
    void displayRecord() const {
        cout << left << setw(10) << id 
             << setw(25) << name 
             << setw(20) << designation 
             << "$" << fixed << setprecision(2) << salary << endl;
    }
};

// Class managing the collection of employees
class EmployeeManagementSystem {
private:
    vector<Employee> employees;

public:
    // 1. Add a new employee record
    void addEmployee() {
        int id;
        string name, designation;
        double salary;

        cout << "\n--- Add New Employee ---" << endl;
        cout << "Enter Employee ID (Integer): ";
        while (!(cin >> id)) {
            cout << "Invalid input. Enter an integer for ID: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        // Check for duplicate ID
        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                cout << "Error: Employee with ID " << id << " already exists!\n";
                return;
            }
        }

        cin.ignore(); // Clear buffer
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Designation: ";
        getline(cin, designation);
        cout << "Enter Salary: ";
        while (!(cin >> salary) || salary < 0) {
            cout << "Invalid input. Enter a positive number for salary: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        employees.push_back(Employee(id, name, designation, salary));
        cout << "Employee record added successfully!\n";
    }

    // 2. Display all employee records
    void displayAllEmployees() const {
        if (employees.empty()) {
            cout << "\nNo employee records found.\n";
            return;
        }

        cout << "\n-------------------------------------------------------------------\n";
        cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
        cout << "-------------------------------------------------------------------\n";
        for (const auto& emp : employees) {
            emp.displayRecord();
        }
        cout << "-------------------------------------------------------------------\n";
    }

    // 3. Search for an employee by ID
    void searchEmployee() const {
        if (employees.empty()) {
            cout << "\nNo records available to search.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to search: ";
        cin >> id;

        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                cout << "\nRecord Found:\n";
                cout << "-------------------------------------------------------------------\n";
                cout << left << setw(10) << "ID" << setw(25) << "Name" << setw(20) << "Designation" << "Salary" << endl;
                cout << "-------------------------------------------------------------------\n";
                emp.displayRecord();
                cout << "-------------------------------------------------------------------\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }

    // 4. Delete an employee record by ID
    void deleteEmployee() {
        if (employees.empty()) {
            cout << "\nNo records available to delete.\n";
            return;
        }

        int id;
        cout << "\nEnter Employee ID to delete: ";
        cin >> id;

        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getId() == id) {
                employees.erase(it);
                cout << "Employee record deleted successfully!\n";
                return;
            }
        }
        cout << "Employee with ID " << id << " not found.\n";
    }
};

int main() {
    EmployeeManagementSystem ems;
    int choice;

    do {
        cout << "\n===== Employee Management System =====" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Search Employee by ID" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";
        
        if (!(cin >> choice)) {
            cout << "Invalid option. Please enter a number between 1 and 5.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                ems.addEmployee();
                break;
            case 2:
                ems.displayAllEmployees();
                break;
            case 3:
                ems.searchEmployee();
                break;
            case 4:
                ems.deleteEmployee();
                break;
            case 5:
                cout << "\nThank you for using the Employee Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please select an option from 1 to 5.\n";
        }
    } while (choice != 5);

    return 0;
}
