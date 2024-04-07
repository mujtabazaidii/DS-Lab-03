#include<iostream>
using namespace std;

template <class T>
class DoubleLinkedList {
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;
		Node() {
			data = 0;
			next = nullptr;
			prev = nullptr;
		}
	};
	Node* head;
	Node* tail;
public:
	Node* CreateNode(T element) {
		Node* ptr = new Node();
		ptr->data = element;
		ptr->next = nullptr;
	    ptr->prev = nullptr;
		return ptr;
	}
	DoubleLinkedList() {
		head = CreateNode(-1);
		tail = CreateNode(-1);
		head->next = tail;
		tail->prev = head;
	}
	void insertAtStart(T const element) {
		Node* ptr = new Node();
		ptr->data = element;
		ptr->next = head;
		head->prev = ptr;
		head = ptr;
		head->prev = tail;
		tail->next = head;
	}
	void insertAtEnd(T const element) {
		Node* ptr = new Node();
		ptr->data = element;
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr;
		tail->next = head;
		head->prev = tail;
	}
	void DeleteAtStart() {
		Node* ptr = head;
		head = head->next;
		head->prev = tail;
		tail->next = head;
		delete ptr;
	}
	void DeleteAtEnd() {
		Node* ptr = tail;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		delete ptr;
	}
	void printForward() const {
		cout << "Print Forth " << endl;
		Node* ptr = new Node();
		ptr = head;
		while (ptr != tail->prev) {
			cout << ptr->next->data << endl;
			ptr = ptr->next;
		}
	}
	void PrintReverse()const {
		cout << "Print Back " << endl;
		Node* ptr = new Node();
		ptr = tail;
		while (ptr->prev != head) {
			cout << ptr->prev->data << endl;
			ptr = ptr->prev;
		}
	}
	int size()const {
		int counter;
		Node* ptr = new Node();
		ptr = head;
		counter = 0;
		while (ptr != tail->prev) {
			ptr = ptr->next;
			counter ++;
		}
		return counter;
	}
	int ReturnMiddle()const {
		int counter = 0;
		Node* ptr = new Node();
		ptr = head;
		while (ptr != tail->prev) {
			ptr = ptr->next;
			counter ++;
		}
		int middle;
		middle = counter / 2;
		ptr = head;
		counter = 0;
		while (ptr != tail->prev) {
			if (counter == middle) {
				return ptr->data;
			}
			ptr = ptr->next;
			counter++;
		}
	}
	bool IsEmpty() {
		if (tail == nullptr || head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}
	int FindMax() const {
		Node* ptr = new Node();
		int maximum = ptr->data;
		ptr = head;
		while (ptr->next != tail->prev) {
			if (maximum < ptr->data) {
				maximum = ptr->data;
			}
			ptr = ptr->next;
		}
		return maximum;
	}
	~DoubleLinkedList() {
	}
};
int main() {
	DoubleLinkedList<int> d;
	d.insertAtStart(6);
	d.insertAtStart(7);
	d.insertAtStart(8);
	d.insertAtStart(9);
	d.insertAtStart(10);
	d.insertAtEnd(5);
	d.insertAtEnd(4);
	d.insertAtEnd(3);
	d.insertAtEnd(2);
	d.insertAtEnd(1);
	d.printForward();
	d.PrintReverse();
	cout << endl << endl;
	cout << endl;
	if (d.IsEmpty()) {
		cout << "List Empty." << endl;
	}
	else {
		cout << "List is Filled." << endl;
	}
	cout << "Size : " << d.size() << endl;
	cout << "Maximum : " << d.FindMax() << endl;
	cout << "Median : " << d.ReturnMiddle() << endl;

	cout << endl << endl;
	d.DeleteAtEnd();
	d.DeleteAtStart();
	cout << "After Deletion" << endl << endl;
	d.printForward();
	d.PrintReverse();
	cout << endl << endl;
	

	return 0;
}