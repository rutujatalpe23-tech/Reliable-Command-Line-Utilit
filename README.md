# Reliable Command-Line Utility

## Expense Tracker Using C++

A simple menu-driven Expense Tracker developed using C++. This project helps users record expenses, view expense details, calculate category-wise totals, and track overall spending.

## Project Objective

To develop a reliable command-line application using C++ programming concepts such as variables, functions, control statements, collections, and input validation.

## Features

- Add new expenses.
- Store expense name, category, and amount.
- Display all recorded expenses.
- Calculate category-wise expense totals.
- Calculate overall expenses.
- Validate user input.
- Prevent invalid and negative expense amounts.
- Display clear and readable terminal output.
- Handle incorrect menu choices without crashing.

## Technologies Used

- C++
- Standard Template Library (STL)
- Vector
- Map
- String
- Stringstream
- iomanip

## Requirements

- C++ compiler (GCC / MinGW)
- C++11 or higher
- VS Code or any C++ IDE

## How to Compile and Run

### Step 1: Compile

```bash
g++ -std=c++11 main.cpp -o expense_tracker
```

### Step 2: Run

Linux / macOS:

```bash
./expense_tracker
```

Windows:

```bash
expense_tracker.exe
```

## Menu Options

1. Add Expense
2. List Expenses
3. Show Category Totals
4. Show Overall Total
5. Exit

## Sample Output

```text
===== EXPENSE TRACKER =====

1. Add expense
2. List expenses
3. Category totals
4. Overall total
5. Exit

Choose (1-5): 1

--- Add Expense ---

Expense name: Lunch
Category: Food
Amount (> 0): 150

Expense added successfully.

Choose (1-5): 4

Overall total: Rs. 150.00

Choose (1-5): 5

Goodbye!
```

## Working Principle

The program uses a structure named `Expense` to store the expense name, category, and amount.

A vector stores multiple expense records.

Separate functions perform operations such as adding expenses, displaying expenses, calculating category-wise totals, and calculating overall totals.

Input validation ensures that invalid values and incorrect menu selections are handled properly.

## Error Handling

- Rejects negative or zero amounts.
- Handles invalid menu choices.
- Prevents empty expense names and categories.
- Handles non-numeric input without crashing.

## Project Structure

```text
Reliable-Command-Line-Utility/
    main.cpp
    README.md
```

## Limitations

Expenses are stored in memory during program execution. Data is not saved permanently after exiting the application.

## Conclusion

The Reliable Command-Line Utility demonstrates C++ programming fundamentals through a practical expense tracking application.

It provides a simple, interactive, and user-friendly command-line interface with proper input validation and expense calculation functionality.

## Author

Developed as part of the Edvyro C++ Programming Task.
