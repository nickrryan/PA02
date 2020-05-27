// Nicholas Ryan
// 5/24/2020


#ifndef MOVIEBST_H
#define MOVIEBST_H

#include<string>
#include<iostream>

using namespace std;

class movieBST {
	public:
		movieBST();
		~movieBST();
		bool insert (string title, double rating);
		bool find(string t) const;
		void printPre() const;
		bool findHighRating(string p);
		int getDepth(string t) const;
	private:
		struct Node {
                        string title;
                        double rating;
                        int depth;
                        Node *left, *right, *parent;
                        Node(string s = "", double r = 0.0, int d = 0) : title(s), rating(r), depth(d), left(0), right(0), parent(0) { }
                };
		void printNode(Node* n) const;
		Node *root;
		void clear(Node* n);
		Node* find(string t, Node* n) const;
		bool insert (string title, double rating, int depth, Node* n);	
		void printPre(Node* n) const;
		Node* findHighRating(string p, Node* highest, Node* n); 
};

#endif
