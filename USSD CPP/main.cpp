
#include <iostream>
#include <string>

using namespace std;

//function prototypes to keep codes organized
void mainMenu();
void airtimeMenu();
void dataMenu();
void transferMenu();

int main(){
	string ussdCode;
	
	cout<<"----Mobile Service Simulator---"
	<<endl;
	
	cout<<"Enter ussdCode:";
	cin>>ussdCode;
	
	if(ussdCode=="*123#"){
	mainMenu();
	} else{
		cout<<"Connection problem or invalid MMI code."<<endl;
	}
	
	return 0;
}

void mainMenu() {
    int choice;
    cout << "\n--- Welcome to QuickServices ---" << endl;
    cout << "1. Buy Airtime" << endl;
    cout << "2. Buy Data Bundle" << endl;
    cout << "3. Transfer Funds" << endl;
    cout << "4. Check Balance" << endl;
    cout << "0. Exit" << endl;
    cout << "Select option: ";
    cin >> choice;

    switch (choice) {
        case 1:
            airtimeMenu();
            break;
        case 2:
            dataMenu();
            break;
        case 3:
            transferMenu();
            break;
        case 4:
            cout << "\nYour current balance is $1,250.50. Thank you!" << endl;
            break;
        case 0:
            cout << "Request cancelled." << endl;
            break;
        default:
            cout << "Invalid selection. Please try again." << endl;
            mainMenu(); // Recursive call to return to menu
    }
}

void airtimeMenu() {
    int amount;
    cout << "\n--- Buy Airtime ---" << endl;
    cout << "Enter amount: ";
    cin >> amount;
    
    if (amount > 0) {
        cout << "Success! You have purchased $" << amount << " worth of airtime." << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
}

void dataMenu() {
    int choice;
    cout << "\n--- Buy Data Bundle ---" << endl;
    cout << "1. 500MB - $5" << endl;
    cout << "2. 2GB - $15" << endl;
    cout << "3. 10GB - $40" << endl;
    cout << "Selection: ";
    cin >> choice;

    if (choice >= 1 && choice <= 3) {
        cout << "Data bundle activated successfully." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }
}

void transferMenu() {
    string account;
    int amount;
    cout << "\n--- Transfer Funds ---" << endl;
    cout << "Enter recipient account number: ";
    cin >> account;
    cout << "Enter amount to transfer: ";
    cin >> amount;

    cout << "Processing... $" << amount << " successfully sent to " << account << "." << endl;
}
	
