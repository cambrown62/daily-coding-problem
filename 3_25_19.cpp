#include <iostream>

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
};


List::List(){
	head = nullptr;
	tail = nullptr;
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
	
	delete tmp;

}
