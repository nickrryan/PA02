//Nicholas Ryan
//05/26/2020

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include "movies.h"

using namespace std;

void runAll();
void tests_insert();
void tests_find();
void tests_findHighRating();
void tests_getDepth();

void START_TEST(string testname){
  cout<<"Start "<<testname<<endl;
}

void END_TEST(string testname) {
  cout<<"End "<<testname<<endl<<endl;
}

void assertEquals(int expected, int actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else { 
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(string expected, string actual, string testDescription){
  if (expected == actual) {
    cout<<"PASSED " << endl;
  } else {
    cout<< "  FAILED: "<< testDescription << endl <<"   Expected: "<< expected << " Actual: " << actual << endl;
  }
}

void assertEquals(bool expected, bool actual, string testDescription){
	if(expected == actual) {
		cout << "PASSED " << endl;
	} else {
		cout<< "  FAILED: " << testDescription << endl << "   Expected: " << expected << " Actual: " << actual << endl;
	}
}

#endif
