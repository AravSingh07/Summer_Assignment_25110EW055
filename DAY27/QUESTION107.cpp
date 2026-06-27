#include<bits/stdc++.h>

class Employee {
private:
    int id;
    std::string name;
    std::string designation;
    double basicSalary;
    
    // Components
    double da;      // Dearness Allowance
    double hra;     // House Rent Allowance
    double medical; // Medical Allowance
    double pf;      // Provident Fund Deduction
    double tax;     // Professional Tax
    double grossSalary;
    double netSalary;

    void calculateSalary() {
        da = basicSalary * 0.80;        // 80% of Basic Salary
        hra = basicSalary * 0.10;       // 10% of Basic Salary
        medical = basicSalary * 0.05;   // 5% of Basic Salary
        pf = basicSalary * 0.12;        // 12% PF Deduction
        tax = basicSalary * 0.02;       // 2% Professional Tax Deduction
        
        grossSalary = basicSalary + da + hra + medical;
        netSalary = grossSalary - (pf + tax);
    }

public:
    // Constructor
    Employee(int empId, std::string empName, std::string empDesig, double empSalary) {
        id = empId;
        name = empName;
        designation = empDesig;
        basicSalary = empSalary;
        calculateSalary();
    }

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }

    // Display employee detailed payslip
    void displayPayslip() const {
        std::cout << "\n=========================================\n";
        std::cout << "             SALARY PAYSLIP              \n";
        std::cout << "=========================================\n";
        std::cout << std::left << std::setw(20) << "Employee ID:" << id << "\n";
        std::cout << std::left << std::setw(20) << "Name:" << name << "\n";
        std::cout << std::left << std::setw(20) << "Designation:" << designation << "\n";
        std::cout << "-----------------------------------------\n";
        std::cout << std::left << std::setw(20) << "Basic Salary:" << "$" << basicSalary << "\n";
        std::cout << std::left << std::setw(20) << "DA (80%):" << "$" << da << "\n";
        std::cout << std::left << std::setw(20) << "HRA (10%):" << "$" << hra << "\n";
        std::cout << std::left << std::setw(20) << "Medical (5%):" << "$" << medical << "\n";
        std::cout << "-----------------------------------------\n";
        std::cout << std::left << std::setw(20) << "GROSS SALARY:" << "$" << grossSalary << "\n";
        std::cout << "-----------------------------------------\n";
        std::cout << std::left << std::setw(20) << "PF Deductions (12%):" << "$" << pf << "\n";
        std::cout << std::left << std::setw(20) << "Prof. Tax (2%):" << "$" << tax << "\n";
        std::cout << "-----------------------------------------\n";
        std::cout << std::left << std::setw(20) << "NET PAYABLE:" << "$" << netSalary << "\n";
        std::cout << "=========================================\n";
    }

    // Display row summary for multi-employee list view
    void displayRow() const {
        std::cout << std::left << std::setw(10) << id 
                  << std::setw(20) << name 
                  << std::setw(15) << designation 
                  << "$" << std::setw(14) << basicSalary 
                  << "$" << netSalary << "\n";
    }
};

// Main Management class to control operations
class SalaryManagementSystem {
private:
    std::vector<Employee> employees;

public:
    void addEmployee() {
        int id;
        std::string name, designation;
        double basicSalary;

        std::cout << "\nEnter Employee ID: ";
        while (!(std::cin >> id)) {
            std::cout << "Invalid input. Enter numeric ID: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        // Check if ID already exists
        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                std::cout << "❌ Error: Employee with ID " << id << " already exists!\n";
                return;
            }
        }

        std::cin.ignore(); // Clear newline buffer
        std::cout << "Enter Employee Name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Designation: ";
        std::getline(std::cin, designation);
        std::cout << "Enter Basic Monthly Salary ($): ";
        while (!(std::cin >> basicSalary) || basicSalary < 0) {
            std::cout << "Invalid input. Enter a valid positive salary: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }

        employees.push_back(Employee(id, name, designation, basicSalary));
        std::cout << "✅ Employee added successfully!\n";
    }

    void displayAllEmployees() const {
        if (employees.empty()) {
            std::cout << "\n⚠ No employee records found.\n";
            return;
        }

        std::cout << "\n========================================================================\n";
        std::cout << std::left << std::setw(10) << "ID" 
                  << std::setw(20) << "Name" 
                  << std::setw(15) << "Designation" 
                  << std::setw(15) << "Basic Salary" 
                  << "Net Salary\n";
        std::cout << "========================================================================\n";
        
        for (const auto& emp : employees) {
            emp.displayRow();
        }
        std::cout << "========================================================================\n";
    }

    void searchEmployee() const {
        if (employees.empty()) {
            std::cout << "\n⚠ System is empty. No records to search.\n";
            return;
        }

        int id;
        std::cout << "\nEnter Employee ID to search: ";
        std::cin >> id;

        for (const auto& emp : employees) {
            if (emp.getId() == id) {
                emp.displayPayslip();
                return;
            }
        }
        std::cout << "❌ Employee with ID " << id << " not found.\n";
    }

    void deleteEmployee() {
        if (employees.empty()) {
            std::cout << "\n⚠ System is empty. No records to delete.\n";
            return;
        }

        int id;
        std::cout << "\nEnter Employee ID to remove: ";
        std::cin >> id;

        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (it->getId() == id) {
                std::cout << "🗑 Removing employee: " << it->getName() << "\n";
                employees.erase(it);
                std::cout << "✅ Record deleted successfully!\n";
                return;
            }
        }
        std::cout << "❌ Employee with ID " << id << " not found.\n";
    }
};

int main() {
    SalaryManagementSystem sms;
    int choice;

    // Standardize floating point outputs to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    do {
        std::cout << "\n=========================================\n";
        std::cout << "        SALARY MANAGEMENT SYSTEM         \n";
        std::cout << "=========================================\n";
        std::cout << "1. Add New Employee\n";
        std::cout << "2. Display All Employee Salaries\n";
        std::cout << "3. Generate Individual Payslip (Search)\n";
        std::cout << "4. Delete Employee Record\n";
        std::cout << "5. Exit\n";
        std::cout << "-----------------------------------------\n";
        std::cout << "Enter your choice (1-5): ";
        
        if (!(std::cin >> choice)) {
            std::cout << "Invalid selection. Please use digits 1-5.\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: sms.addEmployee(); break;
            case 2: sms.displayAllEmployees(); break;
            case 3: sms.searchEmployee(); break;
            case 4: sms.deleteEmployee(); break;
            case 5: std::cout << "\nExiting system. Goodbye!\n"; break;
            default: std::cout << "❌ Invalid choice! Please select between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
