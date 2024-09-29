me#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Account {
    int accountNumber;
    string accountName;
    string birthday;
    string contactNumber;
    double balance;
    int pinCode;
};

vector<Account> accounts;

void enrollAccount() {
    Account newAccount;

    cout << "Enter Account Number (5 digits): ";
    cin >> newAccount.accountNumber;

    cout << "Enter Account Name: ";
    cin.ignore();
    getline(cin, newAccount.accountName);

    cout << "Enter Birthday: ";
    getline(cin, newAccount.birthday);

    cout << "Enter Contact Number: ";
    getline(cin, newAccount.contactNumber);

    cout << "Enter Initial Deposit (Min. 5000): ";
    cin >> newAccount.balance;

    cout << "Enter Pin Code (Max of 6 digits/4 digits): ";
    cin >> newAccount.pinCode;

    accounts.push_back(newAccount);

    cout << "Enrollment successful!" << endl;
}

void balanceInquiry(int accountNumber) {
   for (const auto& account : accounts) {
       if (account.accountNumber == accountNumber) {
           cout << "Balance: " << account.balance << endl;
           return;
       }
   }

   cout << "Invalid Account Number." << endl;
}

void withdraw(int accountNumber, double amount) {
   for (auto& account : accounts) {
       if (account.accountNumber == accountNumber) {
           if (amount <= account.balance) {
               account.balance -= amount;
               cout << "Withdrawal successful!" << endl;
           } else {
               cout << "Insufficient balance!" << endl;
           }

           return;
       }
   }

   cout << "Invalid Account Number." << endl;
}

void deposit(int accountNumber, double amount) {
   for (auto& account : accounts) {
       if (account.accountNumber == accountNumber) {
           account.balance += amount;
           cout << "Deposit successful!" << endl;
           return;
       }
   }

   cout << "Invalid Account Number." << endl;
}

void fundTransfer(int senderAccountNumber, int receiverAccountNumber, double amount) {
    bool senderFound = false;
    bool receiverFound = false;

    for (auto& account : accounts) {
        if (account.accountNumber == senderAccountNumber) {
            if (amount <= account.balance) {
                account.balance -= amount;
                senderFound = true;
            } else {
                cout << "Insufficient balance for fund transfer!" << endl;
                return;
            }
        } else if (account.accountNumber == receiverAccountNumber) {
            account.balance += amount;
            receiverFound = true;
        }

        if (senderFound && receiverFound) {
            cout << "Fund transfer successful!" << endl;
            return;
        }
    }

    cout << "Invalid Account Number." << endl;
}

void changePinCode(int accountNumber, int newPinCode) {
    for (auto& account : accounts) {
        if (account.accountNumber == accountNumber) {
            account.pinCode = newPinCode;
            cout << "Pin code changed successfully!" << endl;
            return;
        }
    }

    cout << "Invalid Account Number." << endl;
}

int main() {
    int choice, accountNumber, pinCode, newPinCode, senderAccountNumber, receiverAccountNumber;
    double amount;

    do {
        system("cls");
        cout << "\nATM SIMULATION\n" << endl
             << "1. Enrollment" << endl
             << "2. Balance Inquiry" << endl
             << "3. Withdraw" << endl
             << "4. Deposit" << endl
             << "5. Fund Transfer" << endl
             << "6. Change PIN Code" << endl
             << "0. Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1:
                enrollAccount();
                break;
            case 2:
                cout << "\nEnter Account Number: ";
                cin >> accountNumber;
                balanceInquiry(accountNumber);
                break;
            case 3:
                cout << "\nEnter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                withdraw(accountNumber, amount);
                break;
            case 4:
                cout << "\nEnter Account Number: ";
                cin >> accountNumber;
                cout << "Enter Amount to Deposit: ";
                cin >> amount;
                deposit(accountNumber, amount);
                break;
            case 5:
                cout << "\nEnter Sender's Account Number: ";
                cin >> senderAccountNumber;
                cout << "Enter Receiver's Account Number: ";
                cin >> receiverAccountNumber;
                cout<<"Enter Amount to Transfer : ";
                cin>>amount;
                fundTransfer(senderAccountNumber, receiverAccountNumber, amount);
                break;

            case 6:
                cout<<"\nEnter Account Number : ";
                cin>>accountNumber;

                cout<<"Enter New Pin Code : ";
                cin>>newPinCode;

                changePinCode(accountNumber,newPinCode);
                break;

            case 0:
                cout<<"\nThank you for using our ATM Simulation!"<<endl;
                break;

                default:
                cout<<"\nInvalid choice! Please try again."<<endl;
                break;
        }

        system ("pause");
    } while (choice != 0);

    return 0;
}
