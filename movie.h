// Nicholas Ryan
// 5/24/2020

#include<string>
#include<iostream>

using namespace std;

class movieBST {
	public:
		movieBST();
		~movieBST();
		bool insert (string title, double rating);
		void printNode(Node* n);
		Node* find(string t) const;
		void findPre(string p) const;
		bool findHighRating(string p) const;
	private:
		Node *root;
		void clear(Node* n);
		Node* find(string t, Node* n) const;
		bool insert (string title, double rating, int depth, Node* n) const;
		void findPre(string p, int len, Node* n) const;
		struct Node {
			string title;
			double rating;
			int depth;
			Node *left, *right, *parent;
			Node(string s = "", double r = 0.0, int d = 0) : title(s), rating(r), depth(d), left(0), right(0), parent(0) { }
		};
};
