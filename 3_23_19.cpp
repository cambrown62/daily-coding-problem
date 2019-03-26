#include <iostream>
#include <vector>
using namespace std;

/*
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

 - is_locked, which returns whether the node is locked
 - lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
 - unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.

You may augment the node to add parent pointers or any other property you would like. You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. 
Each method should run in O(h), where h is the height of the tree.
*/

class Node {

public:

	bool locked;
	int data;
	int locked_descendants_count;
	Node* parent;
	Node* left;
	Node* right;

	Node(int value, Node* prt, Node* lft, Node* rt);
	bool check_ancestors();
	void check_descendants();
	bool is_locked();
	bool lock();
	bool unlock();
};

Node::Node(int value, Node* prt = nullptr, Node* lft = nullptr, Node* rt = nullptr){
	data = value;
	parent = prt;
	left = lft;
	right = rt;
	locked = false;
	locked_descendants_count = 0;
}

bool Node::is_locked(){
	return locked;
}

bool Node::check_ancestors(){
	if(parent == nullptr){
		return true;
	} 
	else if(parent->locked){
		return false;
	}

	return parent->check_ancestors;
}

void Node::check_descendants(){

	if (left == nullptr && right == nullptr){

	}
	else if(left->locked || right->locked){
		locked_descendants_count += 1;

	}
	else{
		left->check_descendants;
		right->check_descendants;
	}
	
}


bool Node::lock(){
	check_descendants;

	while(current
}

