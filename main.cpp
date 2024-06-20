#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void registerUser() {
    string name, password0, age;
    cout << "_______________________________________" << endl << endl;
    cout << "|-----------------Register ------------|" << endl;
    cout << "|______________________________________|" << endl << endl;
    cout << "Enter user name: ";
    cin >> name;
    cout << "Enter password: ";
    cin >> password0;
    cout << "Enter your age: ";
    cin >> age;

    ofstream of1;
    of1.open("file.txt", ios::app);  // Append to the file
    if (of1.is_open()) {
        of1 << name << "\n";
        of1 << password0 << "\n";
        of1 << age << "\n";
        of1.close();
        cout << "Registration successful" << endl;
    } else {
        cout << "Error opening file" << endl;
    }
}

void loginUser() {
    string user, pass, name, password, age, line;
    bool found = false;

    cout << "__________________________________" << endl << endl;
    cout << "|----------------Login------------|" << endl;
    cout << "|_________________________________|" << endl << endl;

    cout << "Enter user name: ";
    cin >> user;
    cout << "Enter password: ";
    cin >> pass;

    ifstream of2("file.txt");
    if (of2.is_open()) {
        while (getline(of2, name) && getline(of2, password) && getline(of2, age)) {
            if (user == name && pass == password) {
                found = true;
                cout << "----Login successful-----" << endl;
                cout << "Details:" << endl;
                cout << "User name: " << name << endl;
                cout << "Password: " << pass << endl;
                cout << "Age: " << age << endl;
                break;
            }
        }
        of2.close();
        if (!found) {
            cout << "Incorrect Credentials" << endl;
            cout << "|     1. Press 2 to login           |" << endl;
            cout << "|     2. Press 3 to change password  |" << endl;
        }
    } else {
        cout << "Error opening file" << endl;
    }
}

void changePassword() {
    string user, oldPassword, newPassword1, newPassword2, name, password, age, line;
    bool found = false;

    cout << "------------Change password----------" << endl;

    cout << "Enter user name: ";
    cin >> user;
    cout << "Enter old password: ";
    cin >> oldPassword;

    ifstream of0("file.txt");
    ofstream temp("temp.txt");
    if (of0.is_open() && temp.is_open()) {
        while (getline(of0, name) && getline(of0, password) && getline(of0, age)) {
            if (user == name && oldPassword == password) {
                found = true;
                cout << "Enter new password: ";
                cin >> newPassword1;
                cout << "Enter your password again: ";
                cin >> newPassword2;
                if (newPassword1 == newPassword2) {
                    temp << name << "\n";
                    temp << newPassword1 << "\n";
                    temp << age << "\n";
                    cout << "Password changed successfully" << endl;
                } else {
                    temp << name << "\n";
                    temp << password << "\n";
                    temp << age << "\n";
                    cout << "Passwords do not match" << endl;
                }
            } else {
                temp << name << "\n";
                temp << password << "\n";
                temp << age << "\n";
            }
        }
        of0.close();
        temp.close();
        remove("file.txt");
        rename("temp.txt", "file.txt");
        if (!found) {
            cout << "Invalid user name or password" << endl;
        }
    } else {
        cout << "Error opening file" << endl;
    }
}

int main() {
    int choice;

    cout << "     Security System  " << endl;
    cout << "______________________________________" << endl << endl;
    cout << "|            1. Register               |" << endl;
    cout << "|            2. Login                  |" << endl;
    cout << "|            3. Change Password        |" << endl;
    cout << "|__________  4. End Program __________|" << endl << endl;

    do {
        cout << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                changePassword();
                break;
            case 4:
                cout << "__________ Thank You! ___________" << endl;
                break;
            default:
                cout << "Enter a valid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}
