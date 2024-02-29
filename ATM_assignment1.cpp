#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
class BankAccount {
private:
    string userId;
    string password;
    long double balance;

public:
    void createAccount() {
        cout << "Please enter your username: ";
        cin >> userId;
        cout << "Please enter your password: ";
        cin >> password;
        balance = 0.0;
        cout << "Thank you!Your account has been created!\n";
    }

    bool login() {
        string enteredUserId, enteredPassword;
        cout << "Please enter your user ID: ";
        cin >> enteredUserId;
        cout << "Please enter your password: ";
        cin >> enteredPassword;
        return (enteredUserId == userId && enteredPassword == password);
    }

    void depositMoney() {
        long double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        balance += amount;
        cout << "Deposit successful." <<endl;
    }

    void withdrawMoney() {
        long double amount;
        cout << "Enter amount of withdrawal: ";
        cin >> amount;

        if (amount <= balance) {
          balance -= amount;
            cout << "Withdrawal successful. " << "\n";
        } else {
            cout << "Insufficient funds. Withdrawal failed.\n";
        }
    }

    void requestBalance() {
        cout << "Your balance: " << balance << "\n";
    }
};

void printIntroMenu() {
    cout << "Please select an option from the menu below:\n"<< "l -> Login\n"<< "c -> Create New Account\n"<< "q -> Quit\n"<< "> ";
}

void printMainMenu() {
         cout << "d -> Deposit Money\n"<< "w -> Withdraw Money\n"<< "r -> Request Balance\n"<< "q -> Quit\n"<< "> ";
}

void start() {
    BankAccount account;
    char choice;

    do {
        cout << "Hi! Welcome to Ms. Saloni's ATM Machine'\n";
        printIntroMenu();
        cin >> choice;

        switch (choice) {
            case 'l':
                if (account.login()) {
                    char mainMenuChoice;
                    do {
                        cout << "Please select an option from the menu below:\n";
                        printMainMenu();
                        cin >> mainMenuChoice;

                        switch (mainMenuChoice) {
                            case 'd':
                                account.depositMoney();
                                break;
                            case 'w':
                                account.withdrawMoney();
                                break;
                            case 'r':
                                account.requestBalance();
                                break;
                            case 'q':
                                cout << "Thanks for stopping by!\n";
                                exit(0);
                            default:
                                cout << "Invalid choice. Try again.\n";
                        }
                    } while (mainMenuChoice != 'q');
                } else {
                    cout << " ****LOGIN FAILED!****\nReturning to the introduction menu.\n";
                }
                break;
            case 'c':
                account.createAccount();
                break;
            case 'q':
                cout << "Quitting program.\n";
                exit(0);
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 'q');
}

int main() {
    start();
    return 0;
}
