#include <iostream>
#include <vector>
using namespace std;

/*
Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of its descendants or ancestors are unlocked.

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
	void update_ancestors(bool L_or_UL);
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

	return parent->check_ancestors();
}

void Node::update_ancestors(bool L_or_UL){
	if(parent != nullptr){
		if(!L_or_UL){
			parent->locked_descendants_count += 1;
			parent->update_ancestors(L_or_UL);
		}
		else{
			parent->locked_descendants_count -= 1;
			parent->update_ancestors(L_or_UL);
		}
	}
}

bool Node::lock(){

	if (left == nullptr && right == nullptr){
		if (check_ancestors()){
			locked = true;
			cout << "Lock successful" << "\n";
			update_ancestors(false);
			return true;	
		}
		else{
			cout << "Could not lock" << "\n";
			return false;
		}
	}
	else if (parent == nullptr){
		if (locked_descendants_count == 0){
			locked = true;
			cout << "Lock successful" << "\n";
			return true;
		}
		else{
			cout << "Could not lock" << "\n";
			return false;
		}
	}
	else {
		if (locked_descendants_count == 0 || check_ancestors()){
			locked = true;
			cout << "Lock successful" << "\n";
			update_ancestors(false);
			return true;
		}
		else{
			cout << "Could not lock" << "\n";
			return false;
		}
	}
}

bool Node::unlock(){

	if (left == nullptr && right == nullptr){
		if (check_ancestors()){
			locked = false;
			cout << "Unlock successful" << "\n";
			update_ancestors(true);
			return true;	
		}
		else{
			cout << "Could not unlock" << "\n";
			return false;
		}
	}
	else if (parent == nullptr){
		if (locked_descendants_count == 0){
			locked = false;
			cout << "Unlock successful" << "\n";
			return true;
		}
		else{
			cout << "Could not unlock" << "\n";
			return false;
		}
	}
	else {
		if (locked_descendants_count == 0 || check_ancestors()){
			locked = false;
			cout << "Unlock successful" << "\n";
			update_ancestors(true);
			return true;
		}
		else{
			cout << "Could not unlock" << "\n";
			return false;
		}
	}
}

/*
     2
    / \
   1   5 
  /	\   \
 6   3   4
	      \
		   0

*/


int main() {

	Node zero(0);
	Node one(1);
	Node two(2);
	Node three(3);
	Node four(4);
	Node five(5);
	Node six(6);

	two.left = &one;
	two.right = &five;

	five.right = &four;
	five.parent = &two;

	one.parent = &two;


	zero.parent = &four;
	four.parent = &five;
	four.right = &zero;

	six.parent = &one;

	three.parent = &one;

    six.lock();
	three.lock();
	four.lock();

	cout << four.locked << "\n";
	//three.lock();
	zero.lock();

	//cout << two.locked_descendants_count << "\n";

	system("pause");
	return 0;
}