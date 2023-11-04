#include <iostream>
#include <cstdlib>
#include <cctype>
#include <conio.h>
using namespace std;

// Function to perform addition
double add(double x, double y) {
    return x + y;
}

// Function to perform subtraction
double subtract(double x, double y) {
    return x - y;
}

// Function to perform multiplication
double multiply(double x, double y) {
    return x * y;
}

// Function to perform division
double divide(double x, double y) {
    if (y == 0) {
        return -1;
    }
    return x / y;
}

void clearScreen() {
    system("cls"); 
}

void instructions() {
    clearScreen();
    cout << "********* CALCULATOR *********" << endl;
    cout << "1. Options" << endl;
    cout << "2. Start the program" << endl;
    cout << "3. Quit" << endl;
    cout << "******************************" << endl;
}

void options() {
    clearScreen();
    cout << "Options:" << endl;
    cout << "Enter '+' for addition" << endl;
    cout << "Enter '-' for subtraction" << endl;
    cout << "Enter '*' for multiplication" << endl;
    cout << "Enter '/' for division" << endl;
    cout << "Press any key to go back" << endl;
    while (!_kbhit()) {} 
    _getch(); 
}

int main() {
    char operation;
    double num1, num2, result;
    int choice;

    while (true) {
        instructions();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            options();
            continue; 
        }
        else if (choice == 2) {
            clearScreen();
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;

            while (true) {
                cout << "Enter an operation (or 'q' to go back): ";
                cin >> operation;
                if (operation == 'q') {
                    break;
                }
                switch (operation) {
                case '+':
                    result = add(num1, num2);
                    break;
                case '-':
                    result = subtract(num1, num2);
                    break;
                case '*':
                    result = multiply(num1, num2);
                    break;
                case '/':
                    result = divide(num1, num2);
                    if (result == -1) {
                        cout << "Error: Division by zero is not allowed." << endl;
                        break;
                    }
                    break;
                default:
                    cout << "Invalid operation. Please try again." << endl;
                    break;
                }
                cout << "Result: " << result << endl;
            }
        }
        else if (choice == 3) {
            clearScreen();
            cout << "Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
