
“SPENDING SMART” 


CODE :

#include <iostream>
#include <string>

using namespace std;

// Helper function to get a double input with validation
double getInput(const string& prompt) {
    double value;
    cout << prompt << endl;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cin.ignore(10000, '\n');
            return value;
        }
        cout << prompt << endl;
    }
}

// Helper function to get an integer input with validation
int getIntInput(const string& prompt) {
    int value;
    cout << prompt << endl;
    while (true) {
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a whole number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
        } else {
            cin.ignore(10000, '\n');
            return value;
        }
        cout << prompt << endl;
    }
}

// Helper function to ask yes/no questions
bool askYesNo(const string& question) {
    char response;
    while (true) {
        cout << question << " (y/n): ";
        cin >> response;
        cin.ignore(10000, '\n');
        if (response == 'y' || response == 'Y')
            return true;
        else if (response == 'n' || response == 'N')
            return false;
        else
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
    }
}

// Function to print the expense report in a table format (using basic formatting)
void printExpenseReportTable(
    const string &name,
    int age,
    const string &occupation,
    double rent,
    double electricity,
    double gas,
    double subscriptions,
    double entertainment,
    double groceries,
    double traveling,
    double transport,
    double personalCare,
    double selectedAmount,
    double totalExpenses,
    double budget 
) {
    cout << "\n--- Expense Report Table for " << name << " ---\n";
    cout << "Category\t\tAmount\n";
    cout << "--------------------------------------\n";
    cout << "Rent\t\t\t" << rent << "\n";
    cout << "Electricity\t\t" << electricity << "\n";
    cout << "Gas\t\t\t" << gas << "\n";
    cout << "Subscriptions\t\t" << subscriptions << "\n";
    cout << "Entertainment\t\t" << entertainment << "\n";
    cout << "Groceries\t\t" << groceries << "\n";
    cout << "Traveling\t\t" << traveling << "\n";
    cout << "Transport\t\t" << transport << "\n";
    cout << "Personal Care\t\t" << personalCare << "\n";
    cout << "financialChoice\t\t" << selectedAmount << "\n";
    cout << "--------------------------------------\n";
    cout << "Total Expenses\t\t" << totalExpenses << "\n";

    if (budget >= 0) {
        double remaining = budget - totalExpenses;
        cout << "Remaining Budget\t" << remaining << "\n";
        if (totalExpenses > budget) {
            cout << "Warning! You have exceeded your budget!\n";
        } else {
            cout << "You are within your budget!\n";
        }
    } else {
        cout << "Budget not set.\n";
    }

    cout << "--------------------------------------\n";
    cout << "Thank you, " << name << "! Keep tracking your expenses.\n";
}

// Helper function to get a string with only alphabetic characters and spaces
void getAlphaInput(const string& prompt, string& result) {
    while (true) {
        cout << prompt;
        getline(cin, result);
        bool valid = true;
        if (result.empty()) valid = false;
        for (int i = 0; i < result.length(); ++i) {
            char c = result[i];
            if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' ')) {
                valid = false;
                break;
            }
        }
        if (valid) break;
        cout << "Invalid input. Please enter only alphabetic characters.\n";
    }
}

void runExpenseCalculator(const string& name, int age, const string& occupation, double budget) {
    double rent = 0, electricity = 0, gas = 0, subscriptions = 0;
    double entertainment = 0, groceries = 0, traveling = 0, transport = 0, personalCare = 0;
    double selectedAmount = 0, totalExpenses = 0;
    int financialChoice = 0;

    if (askYesNo("Do you want to enter Rent amount?")) {
        rent = getInput("Enter Rent amount: ");
    }
    if (askYesNo("Do you want to enter Electricity bill amount?")) {
        electricity = getInput("Enter Electricity bill amount: ");
    }
    if (askYesNo("Do you want to enter Gas bill amount?")) {
        gas = getInput("Enter Gas bill amount: ");
    }
    if (askYesNo("Do you want to enter Subscription charges?")) {
        subscriptions = getInput("Enter Subscription charges: ");
    }
    if (askYesNo("Do you want to enter Entertainment budget?")) {
        entertainment = getInput("Enter Entertainment budget: ");
    }
    if (askYesNo("Do you want to enter Groceries budget?")) {
        groceries = getInput("Enter Groceries budget: ");
    }
    if (askYesNo("Do you want to enter Traveling budget?")) {
        traveling = getInput("Enter Traveling budget: ");
    }
    if (askYesNo("Do you want to enter Transport budget?")) {
        transport = getInput("Enter Transport budget: ");
    }
    if (askYesNo("Do you want to enter Personal Care budget?")) {
        personalCare = getInput("Enter Personal Care budget: ");
    }

    cout << "\nChoose one financial option:\n";
    cout << "1. Savings\n2. Insurance\n3. Investments\n";
    while (true) {
        financialChoice = getIntInput("Enter choice (1/2/3): ");
        if (financialChoice < 1 || financialChoice > 3) {
            cout << "Invalid choice. Please enter a valid option (1/2/3).\n";
        } else {
            break;
        }
    }

    switch (financialChoice) {
        case 1:
            if (askYesNo("Do you want to enter Savings amount?")) {
                selectedAmount = getInput("Enter Savings amount: ");
            }
            break;
        case 2:
            if (askYesNo("Do you want to enter Insurance amount?")) {
                selectedAmount = getInput("Enter Insurance amount: ");
            }
            break;
        case 3:
            if (askYesNo("Do you want to enter Investment amount?")) {
                selectedAmount = getInput("Enter Investment amount: ");
            }
            break;
    }

    totalExpenses = rent + electricity + gas + subscriptions +
                    entertainment + groceries + traveling + transport + personalCare +
                    selectedAmount;

    cout << "\n--- Expense Report for " << name << " ---\n";
    printExpenseReportTable(
        name, age, occupation,
        rent, electricity, gas, subscriptions,
        entertainment, groceries, traveling, transport, personalCare,
        selectedAmount,
        totalExpenses,
        budget
    );
}

int main() {
    int choice;
    string name, occupation;
    int age;
    double budget;

    cout << "Welcome to Spending Smart!\n";
    cout << "Choose mode:\n1. Offline Mode\n2. Online Mode\n";
    while (true) {
        choice = getIntInput("Enter choice (1/2): ");
        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter 1 for Offline or 2 for Online.\n";
        } else {
            break;
        }
    }

    if (choice == 1) {
        cout << "--- OFFLINE MODE ---\n";
        getAlphaInput("Enter Name: ", name);

        while (true) {
            age = getIntInput("Enter Age: ");
            if (age > 0) break;
            cout << "Age must be greater than 0.\n";
        }

        getAlphaInput("Enter Occupation: ", occupation);

    } else if (choice == 2) {
        cout << "--- ONLINE MODE ---\n";
        string email, accNum, pin;
        cout << "Enter Email/Phone: ";
        getline(cin, email);
        cout << "Enter Account Number: ";
        getline(cin, accNum);
        cout << "Enter PIN: ";
        getline(cin, pin);
        cout << "[Sign In Successful]\n";

        name = "User 1";
        age = 18;
        occupation = "Student";
    }

    // Ask if user wants to enter budget
    char budgetChoice;
    while (true) {
        cout << "Do you want to enter your total budget? (y/n): ";
        cin >> budgetChoice;
        cin.ignore(10000, '\n');
        if (budgetChoice == 'y' || budgetChoice == 'Y') {
            budget = getInput("Enter your total budget: ");
            break;
        } else if (budgetChoice == 'n' || budgetChoice == 'N') {
            budget = -1;
            break;
        } else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }

    runExpenseCalculator(name, age, occupation, budget);
    return 0;
}







    




