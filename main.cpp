#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>
#include "movies.h"
#include <chrono>

using namespace std::chrono;
using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[2];
    exit(1);
  }

  if (flag == true) {
	movieBST movies1;
	while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
		movies1.insert(movieName, movieRating);
	}
	movies1.printPre();
	movies1.findHighRating(argv[3]);
  }

  if (flag == false) {
	movieBST movies1;
	int numN = 0;
	ofstream ofs;
	ofs.open("pa02_graph.csv");
	while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
		movies1.insert(movieName, movieRating);
		ofs << numN << "," << movies1.getDepth(movieName) << endl;
		numN++;
	}
	double W = atof(argv[3]);
	double min = 1000000000.0;
	double max = 0.0;
	double totalduration = 0.0;
	for (int i = 0; i < W; i++) {
		auto start = high_resolution_clock::now();
		while (getline (movieFile, line) && parseLine(line, movieName, movieRating)) {movies1.find(movieName);}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<nanoseconds>(stop - start);
		totalduration += duration.count();
		if (duration.count() < min) {min = duration.count();}
		if (duration.count() > max) {max = duration.count();}
	}
	double avgDuration = (totalduration / W);
	cout << "Minimum Duration: " << min << " nanoseconds" << endl;
	cout << "Average Duration: " << avgDuration << " nanoseconds" << endl;
	cout << "Maximum Duration: " << max << " nanoseconds" << endl;
	ofs.close();

  }

  movieFile.close();
  return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";

  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;

  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
      if(i==0 && line[0]=='"') continue;
      if(line[i]=='"'){ i++; flag=true; continue;}
      movieName += line[i];
    }
  }
  
  movieRating = stod(tempRating);
  return true;
}

