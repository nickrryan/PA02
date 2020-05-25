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
		string getTitle() const;
		double getRating() const;
		bool find(string t) const;
		bool findPre(string p) const;
		bool findHighRating(string p) const;
	private:
		Node *root;
		struct Node {
			string title;
			double rating;
			Node *left, *right, *parent;
			Node(string s = "", double r = 0.0) : title(s), rating(r), left(0), right(0), parent(0) { }
		};
};
