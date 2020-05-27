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
		string sub = n->title.substr(0, t.length());
		if (sub == t) {return n;}
		else if (t < sub) {return find(t, n->left);}
		else {return find(t, n->right);}
	}
	return NULL;
}

//return the depth of a node
int movieBST::getDepth(string t) const {
        return ((find(t, root))->depth) + 1;
}

//find movie with the given prefix and print all movies on path
void movieBST::findPre(string p) const {
	findPre(p, root);
	cout << endl;
}

//findPre helper function
void movieBST::findPre(string p, Node* n) const {
	if (n) {
		printNode(n);
		string sub = n->title.substr(0, p.length());
                if (sub == p) {return;}
                else if (p < sub) {find(p, n->left);}
                else {find(p, n->right);}
	}
}

//find movie with given prefix with the highest rating
bool movieBST::findHighRating(string p) {
	Node* highest = findHighRating(p, NULL, root);
	if (highest == NULL) {return false;}
	cout << "Best movie is " << highest->title << " with rating " << highest->rating << endl;
	return true;
}

//findHighRating helper function
movieBST::Node* movieBST::findHighRating(string p, Node* highest, Node* n) { 
	if (n) {
		Node* next = find(p, n);
		if (next != NULL) {
			if (highest == NULL) {highest = next;}
			else if (n->rating > highest->rating) {highest = next;}
			Node* left = find(p, next->left);
			Node* right = find(p, next->right);
			if (left != NULL) {return findHighRating(p, highest, left);}
			else {return findHighRating(p, highest, right);}
		}
		else {return highest;}
        }
	return highest;
}
