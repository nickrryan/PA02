// Nicholas Ryan
// 5/24/2020


#include"movies.h"
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
	int depth = 0;
	if (!root) {
		root = new Node(title, rating, depth);
		return true;
	}
	return insert(title, rating, depth, root);
}

//insert helper function
bool movieBST::insert(string title, double rating, int depth, Node* n) {
	if (title == n->title) {return false;}
	if (title < n->title) {
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
void movieBST::printNode(Node* n) const {
	cout << n->title << ", " << n->rating << ", " << n->depth << endl;
}

//find a movie in BST
bool movieBST::find(string t) const {
	if (find(t, root) != NULL) {return true;}
	return false;
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
	findPre(p, root);
	cout << endl;
}

//findPre helper function
void movieBST::findPre(string p, Node* n) const {
	if (n) {
		printNode(n);
		if (n->title.substr(0,(p.length()-1)) == p) {return;}
		findPre(p, n->left);
		findPre(p, n->right);
	}
}

//find movie with given prefix with the highest rating
bool movieBST::findHighRating(string p) {
	Node* highest = new Node;
	highest = findHighRating(p, highest, root);
	cout << "Best movie is " << highest->title << " with rating " << highest->rating << endl;
	if (highest != NULL) {return true;}
	return false;
}

//findHighRating helper function
movieBST::Node* movieBST::findHighRating(string p, Node* highest, Node* n) {
	if (n) {
		if ((n->title.substr(0,(p.length()-1)) == p) && (n->rating > highest->rating)) {highest = n;}
                findHighRating(p, highest, n->left);
		findHighRating(p, highest, n->right);
        }
	return highest;
}
