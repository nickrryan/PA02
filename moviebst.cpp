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
	if (!root) {
		root = new Node(title, rating);
		return true;
	}
	return insert(title, rating, root);
}

//insert helper function
bool movieBST::insert(string title, double rating, Node* n) {
	if ((title == n->title) && (rating == n->rating)) {return false;}
	if 
