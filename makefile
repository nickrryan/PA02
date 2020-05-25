all: runMovies tests
runMovies: main.o movies.o
	g++ main.cpp movies.cpp -o runMovies
main.o: main.cpp
	g++ main.cpp -c
movies.o: movies.cpp
	g++ movies.cpp -c
tests.o: tests.cpp
	g++ tests.cpp -c
tests: movies.o tests.o
	g++ movies.cpp tests.cpp -o tests
clean:
	rm runMovies tests main.o movies.o tests.o
