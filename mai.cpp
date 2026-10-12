#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

struct Expense {
    string name;
    string category;
    double amount;
};

string readText(string prompt) {
    string s;

    while (true) {
        cout << prompt;
        getline(cin, s);

        if (s.find_first_not_of(" \t\r\n") != string::npos)
            return s;

        cout << "Input cannot be empty. Try again.\n";
    }
}

double readAmount() {
    string s;

    while (true) {
        cout << "Amount (greater than 0): ";
        getline(cin, s);

        stringstream ss(s);
        double amount;
        char extra;

        if ((ss >> amount) && !(ss >> extra) && amount > 0)
            return amount;

        cout << "Invalid amount. Enter a positive number.\n";
    }
}

int readChoice() {
    string s;

    while (true) {
        cout << "\n===== EXPENSE TRACKER =====\n"
             << "1. Add Expense\n"
             << "2. List Expenses\n"
             << "3. Category Totals\n"
             << "4. Overall Total\n"
             << "5. Exit\n"
             << "Choose (1-5): ";

        getline(cin, s);
        stringstream ss(s);
        int choice;
        char extra;

        if ((ss >> choice) && !(ss >> extra)
            && choice >= 1 && choice <= 5)
            return choice;

        cout << "Invalid choice. Enter a number from 1 to 5.\n";
    }
}

void addExpense(vector<Expense>& expenses) {
    Expense e;

    cout << "\n--- Add Expense ---\n";
    e.name = readText("Expense name: ");
    e.category = readText("Category: ");
    e.amount = readAmount();

    expenses.push_back(e);
    cout << "Expense added successfully.\n";
}

void listExpenses(const vector<Expense>& expenses) {
    cout << "\n--- Expense List ---\n";

    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    cout << left << setw(5) << "No."
         << setw(24) << "Name"
         << setw(20) << "Category"
         << right << "Amount\n";

    for (size_t i = 0; i < expenses.size(); i++) {
        cout << left << setw(5) << i + 1
             << setw(24) << expenses[i].name.substr(0, 23)
             << setw(20) << expenses[i].category.substr(0, 19)
             << right << fixed << setprecision(2)
             << expenses[i].amount << "\n";
    }
}

void categoryTotals(const vector<Expense>& expenses) {
    cout << "\n--- Category Totals ---\n";

    if (expenses.empty()) {
        cout << "No expenses recorded yet.\n";
        return;
    }

    map<string, double> totals;

    for (const Expense& e : expenses)
        totals[e.category] += e.amount;

    for (const auto& item : totals) {
        cout << left << setw(22) << item.first
             << "Rs. " << fixed << setprecision(2)
             << item.second << "\n";
    }
}

void overallTotal(const vector<Expense>& expenses) {
    double total = 0;

    for (const Expense& e : expenses)
        total += e.amount;

    cout << "\nOverall total: Rs. "
         << fixed << setprecision(2) << total << "\n";
}

int main() {
    vector<Expense> expenses;

    cout << "Welcome to the Reliable Command-Line Expense Tracker!\n";

    while (true) {
        int choice = readChoice();

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;

            case 2:
                listExpenses(expenses);
                break;

            case 3:
                categoryTotals(expenses);
                break;

            case 4:
                overallTotal(expenses);
                break;

            case 5:
                cout << "Thank you for using the Expense Tracker. Goodbye!\n";
                return 0;
        }
    }
}
