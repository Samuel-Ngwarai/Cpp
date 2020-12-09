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

void testOneEditAway() {
  assert(myFunctions::oneEditAway("pale", "ple") == true);
  assert(myFunctions::oneEditAway("bale", "pale") == true);
  assert(myFunctions::oneEditAway("pa", "pale") == false);
  assert(myFunctions::oneEditAway("bale", "pade") == false);
  assert(myFunctions::oneEditAway("", "") == true);
}

void testStringCompression() {
  assert(myFunctions::stringCompression("aaaaabccsssssdd") == "5a1b2c5s2d");
  assert(myFunctions::stringCompression("abcde") == "abcde");
  assert(myFunctions::stringCompression("AAbbbCCCCCCtt") == "2A3b6C2t");
}

void testMatrixRotation() {
  // matrixes to test with
  vector<vector<int>> originalMatrix{
      {1, 2, 3, 4}, {5, 6, 7, 8}, {0, 2, 4, 6}, {2, 5, 1, 6}};
  vector<vector<int>> finalMatrix{
      {2, 0, 5, 1}, {5, 2, 6, 2}, {1, 4, 7, 3}, {6, 6, 8, 4}};
  vector<vector<int>> originalMatrix1{{1}};
  vector<vector<int>> finalMatrix1{{1}};
  vector<vector<int>> originalMatrix2{{}};
  vector<vector<int>> finalMatrix2{{}};

  // tests
  assert(myFunctions::NinetyDegreeMatrixRotation(originalMatrix) ==
         finalMatrix);
  assert(myFunctions::NinetyDegreeMatrixRotation(originalMatrix1) ==
         finalMatrix1);
  assert(myFunctions::NinetyDegreeMatrixRotation(originalMatrix2) ==
         finalMatrix2);
}

int main() {
  cout << "----- STARTING TESTS -----" << endl;
  testUniqueCharactersLogic();
  testIsPermutation();
  testURLify();
  testPalindromePermutation();
  testOneEditAway();
  testStringCompression();
  testMatrixRotation();
  cout << "----- FINISHED TESTS -----" << endl;
  return 0;
}
