//Nicholas Ryan
//05/26/2020


#include "tests.h"
#include "movies.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
  runAll();
  return 0;
}

void runAll() {
        tests_insert();
        tests_find();
        tests_findHighRating();
}

void tests_insert() {
	const string testName = "tests_insert";
	START_TEST(testName);
	movieBST movies3;
	movies3.insert("the godfather", 8.0);
	movies3.insert("casablanca", 7.9);
	movies3.insert("citizen kane", 7.8);
	assertEquals(true, movies3.find("the godfather"), "failed to insert");
	assertEquals(true, movies3.find("casablanca"), "failed to insert");
        assertEquals(true, movies3.find("citizen kane"), "failed to insert");
	END_TEST(testName);
}

void tests_find() {
	const string testName = "tests_find";
        START_TEST(testName); 
        movieBST movies3;
	assertEquals(false, movies3.find("the godfather"), "empty list");
        movies3.insert("the godfather", 8.0);
        movies3.insert("casablanca", 7.9);
        movies3.insert("citizen kane", 7.8);
        assertEquals(true, movies3.find("the godfather"), "should find");
        assertEquals(true, movies3.find("casablanca"), "should find");
        assertEquals(false, movies3.find("pulp fiction"), "should not find");
        END_TEST(testName);
}

void tests_findHighRating() {
	const string testName = "tests_findHighRating";
        START_TEST(testName);
        movieBST movies3;
        assertEquals(false, movies3.findHighRating("the"), "empty list");
        movies3.insert("the godfather", 8.0);
        movies3.insert("the casablanca", 7.9);
        movies3.insert("the citizen kane", 7.8);
        assertEquals(true, movies3.findHighRating("the"), "should find");
        END_TEST(testName);
}



