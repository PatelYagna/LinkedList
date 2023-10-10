#include <iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename item_Type>
struct Node {
	item_Type data;
	Node* next;
};

template <typename item_Type>
class singleLinkedList {

	private:
	Node<item_Type>* head = nullptr;
	Node<item_Type>* tail = nullptr;
	int numItems = 0;

	public:
	void print(){
		if (numItems == 0){
			cout << "Empty List" << endl;
		}
		else{
			Node<item_Type>* tempNode = head;
			while (tempNode != nullptr){
				cout << tempNode->data << " ";
				tempNode = tempNode->next;
			}
			cout << endl << endl;
		}
	};

	item_Type ask(){
		item_Type input;
		cout << "Enter an input: ";
		cin >> input;
		cout << endl;
		return input;
		};

	singleLinkedList() {
		head = nullptr;
		tail = nullptr;
		numItems = 0;
	};

	~singleLinkedList() {
		while (head != nullptr) {
			Node<item_Type>* tempNode = head;
			head = head->next;
			delete tempNode;
		}
	};

	void push_front(){
		item_Type item = ask();
		Node<item_Type>* tempNode = new Node<item_Type>;
			tempNode->data = item;
			tempNode->next = head;
			head = tempNode;
			if (tail == nullptr) {
				tail = head;
			}
			numItems++;
	};

	void push_back(){
		item_Type item = ask();
		Node<item_Type>* tempNode = new Node<item_Type>;
		tempNode->data = item;
		tempNode->next = nullptr;
		if (numItems == 0){
			cout << "Empty List!" << endl;
		}
		else {
			tail->next = tempNode;
		}
		tail = tempNode;
		numItems++;
	};

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
	};

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

	};

	item_Type front() {
		if (numItems == 0) {
			cout << "Empty List!" << endl;
		}
		else
			return head->data;
	};

	item_Type back() {
		if (numItems == 0) {
			cout << "Empty List!" << endl;
		}
		else
			return tail->data;
	};

	bool empty(){
		return numItems == 0;
	}
};
