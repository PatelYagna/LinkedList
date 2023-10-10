#include "singleLinkedList.h"

int main() {
	
	singleLinkedList<string> list;
	int choice;
	while (choice != 'Q'){
		
		//These are the member functions.
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

		//User selection
		cout << endl << "choose an action: "; 
		cin >> choice;
		cout << endl;

		//Switch statment cases that call the chosen function to perform actions.
		switch (choice){
		case 1:
			list.push_front();
			list.print();
			break;

        case 2:
            list.push_back();
            list.print();
            break;
		
        case 3:
            list.pop_front();
            list.print();
            break;

        case 4:
            list.pop_back();
            list.print();
            break;

        case 5:
            cout << list.front() << endl;
            break;

        case 6:
            cout << list.back() << endl;
            break;
		
        case 7:
            cout << "Is List Empty?: ";
			if (list.empty() == 0){
				cout << "False!" << endl << endl;
			}
			else{
				cout << "True!" << endl << endl;
			}
            break;

		/*
		case 8:
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
            cout << "Enter an index to remove: ";
            cin >> inputIndex;
            if (cin.fail()) {
                cout << "Input Error!" << endl;
                cin.clear();
                cin.ignore();
                break;
            }      
			
        case 10:
            cout << "Enter an item to find: ";
            cout << list.find(list.ask()) << endl;
            list.print();
            break;   
            cout << list.remove(inputIndex) << endl;
            list.print();
            break;
			*/
			
		default:
			cout << "SOMETHING WENT WRONG!" << endl;
			break;
		}
	}
}
