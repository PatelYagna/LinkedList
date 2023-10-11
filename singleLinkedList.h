#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Define a structure for a singly linked list node
template <typename item_Type>
struct Node {
    item_Type data; // Data stored in the node
    Node* next;    // Pointer to the next node
};

// Define a class for a singly linked list
template <typename item_Type>
class singleLinkedList {

private:
    Node<item_Type>* head = nullptr; // Pointer to the first node
    Node<item_Type>* tail = nullptr; // Pointer to the last node
    int numItems = 0;               // Number of items in the list

public:
    // Print the contents of the linked list
    void print() {
        if (numItems == 0) {
            cout << "Empty List" << endl;
        }
        else {
            Node<item_Type>* tempNode = head;
            while (tempNode != nullptr) {
                cout << tempNode->data << " ";
                tempNode = tempNode->next;
            }
            cout << endl << endl;
        }
    }

    // Prompt the user for an input item and return it
    item_Type ask() {
        item_Type input;
        cout << "Enter an input: ";
        cin >> input;
        cout << endl;
        return input;
    }

    // Constructor to initialize an empty linked list
    singleLinkedList() {
        head = nullptr;
        tail = nullptr;
        numItems = 0;
    }

    // Destructor to clean up memory and release nodes
    ~singleLinkedList() {
        while (head != nullptr) {
            Node<item_Type>* tempNode = head;
            head = head->next;
            delete tempNode;
        }
    }

    // Add an item to the front of the linked list
    void push_front() {
        item_Type item = ask();
        Node<item_Type>* tempNode = new Node<item_Type>;
        tempNode->data = item;
        tempNode->next = head;
        head = tempNode;
        if (tail == nullptr) {
            tail = head;
        }
        numItems++;
    }

    // Add an item to the end of the linked list
    void push_back() {
        item_Type item = ask();
        Node<item_Type>* tempNode = new Node<item_Type>;
        tempNode->data = item;
        tempNode->next = nullptr;
        if (numItems == 0) {
            cout << "Empty List!" << endl;
        }
        else {
            tail->next = tempNode;
        }
        tail = tempNode;
        numItems++;
    }

    // Remove an item from the front of the linked list
    void pop_front() {
        if (numItems == 0) {
            cout << "Empty List!" << endl;
        }
        else {
            Node<item_Type>* tempNode = head;
            head = head->next;
            delete tempNode;
            if (head == nullptr) {
                tail = nullptr;
            }
            numItems--;
        }
    }

    // Remove an item from the end of the linked list
    void pop_back() {
        if (numItems == 0) {
            cout << "Empty List!" << endl;
        }
        else {
            if (head == tail) {
                delete tail;
                head = nullptr;
                tail = nullptr;
                numItems--;
            }
            else {
                Node<item_Type>* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                temp->next = nullptr;
                delete tail;
                tail = temp;
                numItems--;
            }
        }
    }

    // Get the data from the first item in the linked list
    item_Type front() {
        if (numItems == 0) {
            cout << "Empty List!" << endl;
        }
        else {
            return head->data;
        }
    }

    // Get the data from the last item in the linked list
    item_Type back() {
        if (numItems == 0) {
            cout << "Empty List!" << endl;
        }
        else {
            return tail->data;
        }
    }

    // Check if the linked list is empty
    bool empty() {
        return numItems == 0;
    }

    // Insert an item at a specified index
    void insert(const item_Type& item, size_t indexNum) {
        if (indexNum == 0) {
            push_front();
        }
        else if (indexNum > numItems) {
            push_back();
        }
        else if (indexNum < numItems && indexNum > 0) {
            item_Type item = ask();
            Node<item_Type>* temp = head;
            for (int i = 0; i < indexNum - 1; i++) {
                temp = temp->next;
            }
            Node<item_Type>* insertNode = new Node<item_Type>;
            insertNode->data = item;
            insertNode->next = temp->next;
            temp->next = insertNode;
            numItems++;
        }
    }

    // Remove an item at a specified index
    bool remove(size_t indexNum) {
        if (indexNum >= numItems) {
            cout << "Index Out of Range!" << endl;
            return false;
        }
        else {
            if (indexNum == 0) {
                pop_front();
                cout << "Index " << indexNum << " Removed" << endl;
                return true;
            }
            else {
                Node<item_Type>* temp = head;
                for (int i = 0; i < indexNum - 1; i++) {
                    temp = temp->next;
                }
                Node<item_Type>* temp2 = temp->next;
                temp->next = temp2->next;
                if (temp2 == tail) {
                    tail = temp;
                }
                delete temp2;
                numItems--;
                cout << "Index Num: " << indexNum << " Removed" << endl;
                return true;
            }
        }
    }

    // Find the index of a specified item in the linked list
    int find(const item_Type& item) {
        Node<item_Type>* temp = head;
        int numIndex = 0;
        while (temp != nullptr) {
            if (temp->data == item) {
                cout << "Index: ";
                return numIndex;
            }
            numIndex++;
            temp = temp->next;
        }
        cout << "Not Found!, List Size: ";
        return numItems;
    }
};
