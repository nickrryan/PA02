// Nicholas Ryan
// 5/24/2020


#include"moviebst.h"
#include<iostream>
#include<string>

using namespace std;

//constructor
movieBST::movieBST() : root(0) { }

//destructor
movieBST::~movieBST() {
	clear(root);
}

//destructor helper function
void movieBST::clear(Node* n) {
	if (n) {
		clear(n->left);
		clear(n->right);
		delete n;
	}
}

//insert movie into tree
bool movieBST::insert(string title, double rating) {
	int depth = 1;
	if (!root) {
		root = new Node(title, rating, depth);
		return true;
	}
	return insert(title, rating, depth, root);
}

//insert helper function
bool movieBST::insert(string title, double rating, int depth, Node* n) {
	if (title == n->title) {return false;}
	if (title < n->info) {
		depth++;
		if (n->left) {return insert(title, rating, depth, n->left);}
		else {
			n->left = new Node(title, rating, depth);

