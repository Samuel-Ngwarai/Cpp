all: compileAndRunArraysAndStrings compileAndRunLinkedLists

compileAndRunArraysAndStrings:
	g++ --std=c++17 -o main CrackIt/ArraysAndStrings/main.cpp
	./main

compileAndRunLinkedLists:
	g++ -std=c++17 -o main CrackIt/LinkedLists/main.cpp
	./main
