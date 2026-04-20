#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Check if username already exists
bool userExists(string username) {
    ifstream file("users.txt");
    string u, p;

    while (file >> u >> p) {
        if (u == username) {
            return true;
        }
    }
    return false;
}

// Register function
void registerUser() {
    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    // simple validation
    if (username == "" || password == "") {
        cout << "Invalid input!\n";
        return;
    }

    if (userExists(username)) {
        cout << "Username already exists. Try another one.\n";
        return;
    }

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;

    cout << "Registration successful!\n";
}

// Login function
void loginUser() {
    string username, password;
    string u, p;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> u >> p) {
        if (u == username && p == password) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Login successful! Welcome " << username << endl;
    } else {
        cout << "Invalid username or password.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            registerUser();
        }
        else if (choice == 2) {
            loginUser();
        }
        else if (choice == 3) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
