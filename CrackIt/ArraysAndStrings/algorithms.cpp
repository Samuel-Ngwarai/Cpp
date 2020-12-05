#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace myFunctions {
// WDS = With (additional) Data Structures
bool uniqueStringCharactersWDS(string s) {
  unordered_set<char> seen;

  for (char c : s) {
    if (seen.find(c) != seen.end()) return false;
    seen.insert(c);
  }
  return true;
}

// WODS = Without (additional) Data structures
bool uniqueStringCharactersWODS(string s) {
  sort(s.begin(), s.end());

  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) return false;
  }
  return true;
}

// check if one string is a permutation of another
bool isPermutation(string a, string b) {
  if (a.length() != b.length()) return false;

  unordered_map<char, int> charCount;

  for (char c : a) {
    charCount[c]++;
  }

  for (char c : b) {
    if (charCount.find(c) == charCount.end() || charCount[c] == 0) return false;
    charCount[c]--;
  }

  return true;
}

// replace spaces with %20
string URLify(string a) {
  if (a.size() == 0) return a;

  int pos = a.size() - 1;
  if (a[pos] != ' ') {
    cout << "given string does not have space at the end for the function to "
            "work. returning string as is"
         << endl;
    return a;
  }

  int it = pos;
  while (a[it] == ' ' && it >= 0) {
    it--;
  }

  while (it != 0 && it < pos) {
    if (a[it] != ' ') {
      a[pos--] = a[it--];
      continue;
    }

    a[pos--] = '0';
    a[pos--] = '2';
    a[pos--] = '%';
    it--;
  }

  return a;
}

// check if a string is a permutation of a palindrome
bool palindromePermutation(string a) {
  if (a.length() <= 1) return true;

  unordered_map<char, int> charCounts;

  for (char c : a) {
    if (c != ' ') charCounts[tolower(c)]++;
  }

  int evens = 0, odds = 0;

  for (auto [c, count] : charCounts) {
    if (count % 2 == 0)
      evens++;
    else
      odds++;

    if (odds > 1) return false;
  }

  return true;
}

}  // namespace myFunctions
