#include <assert.h>

#include <iostream>

#include "algorithms.cpp"

using namespace std;

void testUniqueCharactersLogic() {
  assert(myFunctions::uniqueStringCharactersWDS("asdfg") == true);
  assert(myFunctions::uniqueStringCharactersWDS("adfag") == false);
  assert(myFunctions::uniqueStringCharactersWDS("") == true);
  assert(myFunctions::uniqueStringCharactersWODS("asdfg") == true);
  assert(myFunctions::uniqueStringCharactersWODS("asafg") == false);
  assert(myFunctions::uniqueStringCharactersWODS("") == true);
}

void testIsPermutation() {
  assert(myFunctions::isPermutation("abc", "cde") == false);
  assert(myFunctions::isPermutation("abc", "bac") == true);
  assert(myFunctions::isPermutation("abc", "aabc") == false);
  assert(myFunctions::isPermutation("", "") == true);
}

void testURLify() {
  assert(myFunctions::URLify("Mr John Smith    ") == "Mr%20John%20Smith");
}

void testPalindromePermutation() {
  assert(myFunctions::palindromePermutation("Tact Coa") == true);
  assert(myFunctions::palindromePermutation("this should fail") == false);
  assert(myFunctions::palindromePermutation("2") == true);
  assert(myFunctions::palindromePermutation("") == true);
}

int main() {
  testUniqueCharactersLogic();
  testIsPermutation();
  testURLify();
  testPalindromePermutation();
  return 0;
}
