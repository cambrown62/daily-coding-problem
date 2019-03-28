#include <iostream>
using namespace std;

/*
Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
*/

class Node {

public:
	int data;
	Node* next;

};

class List{

public:
	Node* head;
	Node* tail;
	int length;

	List();
	void add_node(int value);
	void remove_kth_last(int k);
	void print_list();
};


List::List(){
	head = nullptr;
	tail = nullptr;
	length = 0;
}

void List::add_node(int value){
	Node* tmp =  new Node;
	tmp->data = value;

	tmp->next = nullptr;

	if (head == nullptr){
		head = tmp;
		tail = tmp;
	}
	else{
		tail->next = tmp;
		tail = tmp;
	}

	length += 1;
}

void List::remove_kth_last(int k){
	int counter = 1;
	Node* tmp = head;
	while(counter < length - k){
		tmp = tmp->next;
		counter += 1;
	}
	Node* tmp2 = tmp->next->next;
	
	delete tmp->next;
	tmp->next = tmp2;
	length -= 1;
}

void List::print_list() {
	Node* tmp = head;
	for (int i = 1; i <= length; i++){
		cout << tmp->data << "\n";
		tmp = tmp->next;
	}
}

int main() {

	List list1;
	list1.add_node(1);
	list1.add_node(2);
	list1.add_node(3);
	list1.add_node(4);
	list1.add_node(5);

	//cout << list1.length << "\n";

	//list1.print_list();

	list1.remove_kth_last(2);

	list1.print_list();

	system("Pause");
	return 0;
}