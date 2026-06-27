#include<bits/stdc++.h>

using namespace std;

// ─── ANSI Colors ────────────────────────────────────────────────────────────
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"
#define BLUE    "\033[34m"
#define WHITE   "\033[97m"
#define DIM     "\033[2m"

// ─── Employee Structure ──────────────────────────────────────────────────────
struct Employee {
    int    id;
    string name;
    string department;
    string role;
    double salary;
    string email;
    string phone;
    string startDate;
    bool   active;
};

// ─── Global State ────────────────────────────────────────────────────────────
vector<Employee> employees;
int nextId = 1;

// ─── Helpers ─────────────────────────────────────────────────────────────────
void clearScreen() { cout << "\033[2J\033[H"; }

void printLine(char c = '-', int len = 70) {
    cout << DIM << string(len, c) << RESET << "\n";
}

void printHeader(const string& title) {
    clearScreen();
    printLine('=');
    cout << BOLD << CYAN
         << "  EMPLOYEE MANAGEMENT SYSTEM"
         << RESET << "\n";
    printLine('=');
    if (!title.empty()) {
        cout << BOLD << "  " << title << RESET << "\n";
        printLine();
    }
}

string center(const string& s, int w) {
    int pad = max(0, (w - (int)s.size()) / 2);
    return string(pad, ' ') + s + string(w - pad - (int)s.size(), ' ');
}

string truncate(const string& s, int w) {
    if ((int)s.size() <= w) return s + string(w - s.size(), ' ');
    return s.substr(0, w - 2) + "..";
}

void pause() {
    cout << "\n" << DIM << "  Press Enter to continue..." << RESET;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

string getInput(const string& prompt, bool required = true) {
    string val;
    while (true) {
        cout << "  " << CYAN << prompt << RESET << ": ";
        getline(cin, val);
        // trim
        size_t s = val.find_first_not_of(" \t");
        size_t e = val.find_last_not_of(" \t");
        val = (s == string::npos) ? "" : val.substr(s, e - s + 1);
        if (!required || !val.empty()) return val;
        cout << RED << "  This field is required.\n" << RESET;
    }
}

double getSalary(const string& prompt) {
    while (true) {
        string s = getInput(prompt);
        try {
            double v = stod(s);
            if (v >= 0) return v;
        } catch (...) {}
        cout << RED << "  Enter a valid positive number.\n" << RESET;
    }
}

int getMenuChoice(int lo, int hi) {
    while (true) {
        cout << "\n  " << BOLD << "Choice: " << RESET;
        string s;
        getline(cin, s);
        try {
            int v = stoi(s);
            if (v >= lo && v <= hi) return v;
        } catch (...) {}
        cout << RED << "  Enter a number between " << lo << " and " << hi << ".\n" << RESET;
    }
}

// ─── Table Renderer ───────────────────────────────────────────────────────────
void printTableHeader() {
    cout << "\n"
         << BOLD
         << "  " << left
         << setw(5)  << "ID"
         << setw(22) << "Name"
         << setw(16) << "Department"
         << setw(14) << "Role"
         << setw(12) << "Salary"
         << setw(10) << "Status"
         << RESET << "\n";
    printLine();
}

void printEmployeeRow(const Employee& e) {
    string status = e.active ? (GREEN + string("Active") + RESET)
                              : (RED   + string("Inactive") + RESET);
    string salaryStr = "$" + to_string((int)e.salary);
    cout << "  " << left
         << setw(5)  << e.id
         << setw(22) << truncate(e.name, 21)
         << setw(16) << truncate(e.department, 15)
         << setw(14) << truncate(e.role, 13)
         << setw(12) << salaryStr
         << status   << "\n";
}

// ─── CRUD Operations ─────────────────────────────────────────────────────────
void addEmployee() {
    printHeader("Add New Employee");
    Employee e;
    e.id     = nextId++;
    e.active = true;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    e.name       = getInput("Full name");
    e.email      = getInput("Email");
    e.phone      = getInput("Phone", false);
    e.department = getInput("Department");
    e.role       = getInput("Role / Title");
    e.salary     = getSalary("Salary (USD)");
    e.startDate  = getInput("Start date (YYYY-MM-DD)", false);

    employees.push_back(e);

    cout << "\n  " << GREEN << "✓ Employee #" << e.id
         << " (" << e.name << ") added successfully." << RESET << "\n";
    pause();
}

void listEmployees(const vector<Employee>* src = nullptr) {
    const vector<Employee>& list = src ? *src : employees;
    if (list.empty()) {
        cout << "\n  " << YELLOW << "No employees found.\n" << RESET;
        return;
    }
    printTableHeader();
    for (const auto& e : list) printEmployeeRow(e);
    printLine();
    cout << DIM << "  " << list.size() << " employee(s)\n" << RESET;
}

void viewEmployee() {
    printHeader("View Employee");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string idStr = getInput("Enter Employee ID");
    int id;
    try { id = stoi(idStr); } catch (...) {
        cout << RED << "  Invalid ID.\n" << RESET; pause(); return;
    }
    auto it = find_if(employees.begin(), employees.end(),
                      [id](const Employee& e){ return e.id == id; });
    if (it == employees.end()) {
        cout << RED << "  Employee not found.\n" << RESET; pause(); return;
    }
    const Employee& e = *it;
    printLine('=');
    cout << "\n"
         << BOLD << CYAN << "  #" << e.id << "  " << e.name << RESET << "\n\n"
         << "  " << setw(16) << left << "Email"     << e.email      << "\n"
         << "  " << setw(16) << left << "Phone"     << (e.phone.empty() ? "—" : e.phone) << "\n"
         << "  " << setw(16) << left << "Department"<< e.department << "\n"
         << "  " << setw(16) << left << "Role"      << e.role       << "\n"
         << "  " << setw(16) << left << "Salary"    << "$" << fixed << setprecision(2) << e.salary << "\n"
         << "  " << setw(16) << left << "Start Date"<< (e.startDate.empty() ? "—" : e.startDate) << "\n"
         << "  " << setw(16) << left << "Status"
         << (e.active ? (GREEN + string("Active") + RESET)
                      : (RED   + string("Inactive") + RESET)) << "\n\n";
    printLine('=');
    pause();
}

void editEmployee() {
    printHeader("Edit Employee");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string idStr = getInput("Enter Employee ID to edit");
    int id;
    try { id = stoi(idStr); } catch (...) {
        cout << RED << "  Invalid ID.\n" << RESET; pause(); return;
    }
    auto it = find_if(employees.begin(), employees.end(),
                      [id](const Employee& e){ return e.id == id; });
    if (it == employees.end()) {
        cout << RED << "  Employee not found.\n" << RESET; pause(); return;
    }
    Employee& e = *it;
    cout << "\n  " << DIM << "Leave a field blank to keep the current value.\n\n" << RESET;

    auto update = [&](const string& prompt, string& field) {
        cout << "  " << CYAN << prompt << RESET << " [" << DIM << field << RESET << "]: ";
        string val; getline(cin, val);
        size_t s = val.find_first_not_of(" \t");
        size_t en = val.find_last_not_of(" \t");
        val = (s == string::npos) ? "" : val.substr(s, en - s + 1);
        if (!val.empty()) field = val;
    };

    update("Full name",   e.name);
    update("Email",       e.email);
    update("Phone",       e.phone);
    update("Department",  e.department);
    update("Role",        e.role);
    update("Start date",  e.startDate);

    cout << "  " << CYAN << "Salary" << RESET << " [" << DIM << e.salary << RESET << "]: ";
    string sal; getline(cin, sal);
    if (!sal.empty()) {
        try { double v = stod(sal); if (v >= 0) e.salary = v; } catch (...) {}
    }

    cout << "\n  " << GREEN << "✓ Employee #" << e.id << " updated.\n" << RESET;
    pause();
}

void deleteEmployee() {
    printHeader("Delete Employee");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string idStr = getInput("Enter Employee ID to delete");
    int id;
    try { id = stoi(idStr); } catch (...) {
        cout << RED << "  Invalid ID.\n" << RESET; pause(); return;
    }
    auto it = find_if(employees.begin(), employees.end(),
                      [id](const Employee& e){ return e.id == id; });
    if (it == employees.end()) {
        cout << RED << "  Employee not found.\n" << RESET; pause(); return;
    }
    cout << "\n  Delete " << BOLD << it->name << RESET << "? (y/N): ";
    string confirm; getline(cin, confirm);
    if (confirm == "y" || confirm == "Y") {
        employees.erase(it);
        cout << GREEN << "  ✓ Employee deleted.\n" << RESET;
    } else {
        cout << DIM << "  Cancelled.\n" << RESET;
    }
    pause();
}

void toggleStatus() {
    printHeader("Toggle Status");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string idStr = getInput("Enter Employee ID");
    int id;
    try { id = stoi(idStr); } catch (...) {
        cout << RED << "  Invalid ID.\n" << RESET; pause(); return;
    }
    auto it = find_if(employees.begin(), employees.end(),
                      [id](const Employee& e){ return e.id == id; });
    if (it == employees.end()) {
        cout << RED << "  Employee not found.\n" << RESET; pause(); return;
    }
    it->active = !it->active;
    string newStatus = it->active ? "Active" : "Inactive";
    cout << "\n  " << GREEN << "✓ " << it->name
         << " is now " << newStatus << ".\n" << RESET;
    pause();
}

void searchEmployees() {
    printHeader("Search Employees");
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string q = getInput("Search (name / dept / role)");
    string ql = q;
    transform(ql.begin(), ql.end(), ql.begin(), ::tolower);

    vector<Employee> results;
    for (const auto& e : employees) {
        string n = e.name, d = e.department, r = e.role;
        transform(n.begin(), n.end(), n.begin(), ::tolower);
        transform(d.begin(), d.end(), d.begin(), ::tolower);
        transform(r.begin(), r.end(), r.begin(), ::tolower);
        if (n.find(ql) != string::npos ||
            d.find(ql) != string::npos ||
            r.find(ql) != string::npos)
            results.push_back(e);
    }

    cout << "\n  " << BOLD << results.size() << " result(s) for \""
         << q << "\"\n" << RESET;
    listEmployees(&results);
    pause();
}

void showStats() {
    printHeader("Statistics");
    if (employees.empty()) {
        cout << "\n  " << YELLOW << "No data yet.\n" << RESET;
        pause(); return;
    }
    int active   = 0;
    double total = 0, maxS = 0, minS = 1e18;
    map<string,int> depts;
    Employee *topEmp = nullptr, *botEmp = nullptr;

    for (auto& e : employees) {
        if (e.active) active++;
        total += e.salary;
        depts[e.department]++;
        if (e.salary > maxS) { maxS = e.salary; topEmp = &e; }
        if (e.salary < minS) { minS = e.salary; botEmp = &e; }
    }
    double avg = total / employees.size();

    cout << "\n"
         << "  " << setw(28) << left << BOLD "Total employees" RESET  << employees.size() << "\n"
         << "  " << setw(28) << left << BOLD "Active" RESET           << active << "\n"
         << "  " << setw(28) << left << BOLD "Inactive" RESET         << (employees.size()-active) << "\n"
         << "  " << setw(28) << left << BOLD "Total salary payout" RESET << "$" << fixed << setprecision(2) << total << "\n"
         << "  " << setw(28) << left << BOLD "Average salary" RESET   << "$" << avg << "\n"
         << "  " << setw(28) << left << BOLD "Highest salary" RESET
         << "$" << maxS << "  (" << (topEmp?topEmp->name:"") << ")\n"
         << "  " << setw(28) << left << BOLD "Lowest salary" RESET
         << "$" << minS << "  (" << (botEmp?botEmp->name:"") << ")\n";

    cout << "\n  " << BOLD << "By Department:\n" << RESET;
    printLine();
    for (auto& p : depts)
        cout << "  " << left << setw(24) << p.first << p.second << " employee(s)\n";
    printLine();
    pause();
}

// ─── Seed Data ────────────────────────────────────────────────────────────────
void seedData() {
    employees = {
        {nextId++,"Aisha Patel",   "Engineering","Senior Dev", 95000,"aisha@co.com","+15550101","2021-03-15",true},
        {nextId++,"Marcus Chen",   "Product",    "Manager",   110000,"marcus@co.com","+15550102","2019-07-22",true},
        {nextId++,"Sofia Romero",  "Design",     "Lead",      105000,"sofia@co.com", "+15550103","2020-01-10",true},
        {nextId++,"James Okafor",  "Marketing",  "Senior",     88000,"james@co.com", "+15550104","2022-05-01",true},
        {nextId++,"David Park",    "Finance",    "Manager",   120000,"david@co.com", "+15550106","2018-11-05",false},
        {nextId++,"Priya Nair",    "HR",         "Director",  130000,"priya@co.com", "+15550107","2017-04-20",true},
    };
}

// ─── Main Menu ────────────────────────────────────────────────────────────────
int main() {
    seedData();
    while (true) {
        printHeader("");
        cout << "\n"
             << "  " << BOLD << "1." << RESET << "  List all employees\n"
             << "  " << BOLD << "2." << RESET << "  View employee details\n"
             << "  " << BOLD << "3." << RESET << "  Add new employee\n"
             << "  " << BOLD << "4." << RESET << "  Edit employee\n"
             << "  " << BOLD << "5." << RESET << "  Delete employee\n"
             << "  " << BOLD << "6." << RESET << "  Toggle active / inactive\n"
             << "  " << BOLD << "7." << RESET << "  Search employees\n"
             << "  " << BOLD << "8." << RESET << "  Statistics\n"
             << "  " << BOLD << RED << "0." << RESET << "  Exit\n";
        printLine();

        int choice = getMenuChoice(0, 8);
        switch (choice) {
            case 1: clearScreen(); printHeader("All Employees");
                    listEmployees(); pause(); break;
            case 2: viewEmployee();   break;
            case 3: addEmployee();    break;
            case 4: editEmployee();   break;
            case 5: deleteEmployee(); break;
            case 6: toggleStatus();   break;
            case 7: searchEmployees();break;
            case 8: showStats();      break;
            case 0:
                cout << "\n  " << CYAN << "Goodbye!\n\n" << RESET;
                return 0;
        }
    }
}