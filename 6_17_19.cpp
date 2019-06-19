#include <iostream>
#include <vector>
using namespace std;

/*
Given a binary tree, return all paths from the root to leaves.

For example, given the tree:

	 1
	/ \
   2   3
	  / \
     4   5


Return [[1, 2], [1, 3, 4], [1, 3, 5]].
*/

struct Node {
	int val;
	Node* left;
	Node* right;
};

class BinaryTree {
	Node* root;

public:
	BinaryTree(int root_key);
	void insert(int key, Node* leaf);

};

vector<vector<int>> paths;
int i = 0;

vector<vector<int>> all_paths(Node* root, int j) {

	paths[j].push_back(root->val);
	if (root->left != nullptr && root->right != nullptr) {
		paths.push_back(vector<int>());
		paths.push_back(vector<int>());
		all_paths(root->left, j + 1);
		all_paths(root->right, j + 2);
	}
}