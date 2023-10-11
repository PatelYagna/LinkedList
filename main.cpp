#include "singleLinkedList.h"
#include "employee.h"

int main() {

    // Create a linked list to store strings
    singleLinkedList<string> list;
    int choice, inputIndex, age, hours;
    double salary;
    string inputUser, inputString, itemInput, professionInput, name = "";

    // Run a loop until the user chooses to quit
    while (choice != 'Q') {

        // Display a menu with available options
        cout << "1. Push_front" << endl
             << "2. Push_back" << endl
             << "3. Pop_front" << endl
             << "4. Pop_back" << endl
             << "5. Peek Front item" << endl
             << "6. Peek Back item" << endl
             << "7. Check if Empty" << endl
             << "8. Insert an index" << endl
             << "9. Remove an index" << endl
             << "10. Find an item" << endl 
             << "11. Create an employee" << endl;

        // Prompt the user to choose an action
        cout << endl << "Choose an action: "; 
        cin >> choice;
        cout << endl;

        // Perform actions based on the user's choice using a switch statement
        switch (choice) {
        case 1:
            // Add an item to the front of the linked list
            list.push_front();
            list.print();
            break;

        case 2:
            // Add an item to the end of the linked list
            list.push_back();
            list.print();
            break;
        
        case 3:
            // Remove an item from the front of the linked list
            list.pop_front();
            list.print();
            break;

        case 4:
            // Remove an item from the end of the linked list
            list.pop_back();
            list.print();
            break;

        case 5:
            // Display the first item in the linked list
            cout << list.front() << endl;
            break;

        case 6:
            // Display the last item in the linked list
            cout << list.back() << endl;
            break;
        
        case 7:
            // Check if the linked list is empty and display the result
            if (list.empty() == 0) {
                cout << "List Not Empty!" << endl << endl;
            }
            else {
                cout << "List Empty!" << endl << endl;
            }
            break;

        case 8:
            // Prompt the user to enter an index and insert an item at that index
            cout << "Enter an index to insert at: ";
            cin >> inputIndex;
            if (cin.fail()) {
                cout << "Input Error!" << endl;
                cin.clear();
                cin.ignore();
                break;
            }
            list.insert(inputUser, inputIndex);
            list.print();
            break;

        case 9:
            // Prompt the user to enter an index and remove the item at that index
            cout << "Enter an index to remove at: ";
            cin >> inputIndex;
            cout << endl;
            if (cin.fail()) {
                cout << "Input Error!" << endl;
                cin.clear();
                cin.ignore();
                break;
            }
            cout << list.remove(inputIndex) << endl << endl;
            list.print();
            break;
            
        case 10:
            // Prompt the user to enter an item and find it in the linked list
            cout << "Enter an item to find: ";
            cout << list.find(list.ask()) << endl;
            list.print();
            break;   
            
        case 11:
            // Create an employee based on user input
            cout << "Employee Name: ";
            cin.ignore();
            getline(cin, name);
            
            cout << "Employee Age: ";
            cin >> age;
            if (cin.fail()) {
                cout << "Invalid Input!" << endl;
                cin.clear();
                cin.ignore();
                break;
            }
            
            cout << "Professional [P] or Non-Professional [N] Employee?: ";
            cin >> professionInput;
            
            if (professionInput[0] == 'P' || professionInput[0] == 'p') {
                // Create a professional employee with a monthly salary
                cout << "Monthly Salary: ";
                cin >> salary;
                Professional PEmployee(name, age, salary);
                PEmployee.print();
            }
            else if (professionInput[0] == 'N' || professionInput[0] == 'n') {
                // Create a non-professional employee with hourly wage and weekly hours
                cout << "Hourly Wage: ";
                cin >> salary;
                cout << "Hours in a Week: ";
                cin >> hours;
                Nonprofessional NEmployee(name, age, salary, hours);
                NEmployee.print();
            }
            break;
            
        default:
            // Handle an unknown or invalid choice
            cout << "SOMETHING WENT WRONG!" << endl;
            break;
        }
    }
}
