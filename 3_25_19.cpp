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
};

Node::Node(int value, Node* nxt = nullptr){
	data = value;
	next = nxt; 
}

