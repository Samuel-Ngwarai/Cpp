#include "algorithms.cpp"
#include <iostream>
#include <assert.h>
// #include <gtest/gtest.h>
// read about and introduce a proper unit testing framework

using namespace std;

void testUniqueCharactersLogic() {
	assert(uniqueStringCharactersWDS("asdfg") == true);
	assert(uniqueStringCharactersWDS("adfag") == false);
	assert(uniqueStringCharactersWDS("") == true);
	assert(uniqueStringCharactersWODS("asdfg") == true);
	assert(uniqueStringCharactersWODS("asafg") == false);
	assert(uniqueStringCharactersWODS("") == true);
}

int main() {
	testUniqueCharactersLogic();
	return 0;
}
