all: compileArraysAndStrings runArraysAndStrings

compileArraysAndStrings:
	g++ --std=c++17 -o main CrackIt/ArraysAndStrings/main.cpp

runArraysAndStrings:
	./main
