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
			n->left->parent = n;
			return true;
		}
	}
	else {
		depth++;
		if (n->right) {return insert(title, rating, depth, n->right);}
		else {
			n->right = new Node(title, rating, depth);
			n->right->parent = n;
			return true;
		}
	}
}
//print a movie node
void moviesBST::printNode(Node* n) {
	cout << n->title << ", " << n->rating << ", " << n->depth << endl;
}

//find a movie in BST
movieBST::Node* movieBST::find(string t) const {
	return find(t, root);
}

//find helper function
movieBST::Node* movieBST::find(string t, Node* n) const {
	if (n) {
		if (n->title == t) {return n;}
		else if (n->title > t) {return find(t, n->left);}
		else if (n->title < t) {return find(t, n->right);}
	}
	return NULL;
}

//find movie with the given prefix
void movieBST::findPre(string p) const {
	len = p.length - 1;
	findPre(strint p, int len, root);
	cout << endl;
}

//findPre helper function
void moviesBST::findPre(string p, int len, Node* n) const {
	if (n) {
		printNode(n);
		if (n->title.substr(0,len) == p) {return;}
		findPre(string p, n->left);
		findPre(string p, n->right);
	}
}

//find movie with given prefix with the highest rating
movieBST::Node* movieBST::findHighRating(string p) const {
	double highest = 0.0;
	return findHighRating(p, highest, root);
}

//findHighRating helper function
movieBST::Node* movieBST::findHighRating(string p, int highest, Node* n) const {
	//create new BST of all the movies with the prefix p,
	//then find the node with the highest rating and print that
}
