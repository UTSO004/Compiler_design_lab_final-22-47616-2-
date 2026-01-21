#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isValidInput(const string& s) {
    for (char c : s) {
        if (c != 'a' && c != 'b') {
            return false;
        }
    }
    return true;
}

int getNextState(int currentState, char input) {
    switch (currentState) {
        case 0:
            if (input == 'b') return 0;
            if (input == 'a') return 1;
            return -1;

        case 1:
            if (input == 'a') return 1;
            if (input == 'b') return 2;
            return -1;

        case 2:
            if (input == 'a') return 3;
            return -1;

        case 3:
            if (input == 'a' || input == 'b') return 1;
            return -1;

        default:
            return -1;
    }
}

bool isAccepted(const string& s) {
    if (!isValidInput(s)) return false;

    int currentState = 0;

    for (char c : s) {
        currentState = getNextState(currentState, c);
        if (currentState == -1) return false;
    }

    return (currentState == 1);
}

int main() {
    string userInput;

    cout << "*********************************************\n";
    cout << "DFA for RE: b* a [ a + ba(a+b) ]*\n";
    cout << "Type 'exit' to quit the program.\n";
    cout << "*********************************************\n";

    while (true) {
        cout << "\nEnter a string (only a/b allowed): ";
        cin >> userInput;

        if (userInput == "exit") {
            break;
        }

        if (!isValidInput(userInput)) {
            cout << "Error: Input must contain only 'a' and 'b'\n";
            continue;
        }

        if (isAccepted(userInput)) {
            cout << "Result: Accepted";
        } else {
            cout << "Result: Rejected";
        }
        cout << endl;
    }

    cout << "\nProgram terminated.\n";
    return 0;
}





