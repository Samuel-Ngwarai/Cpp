#include <string>
#include <unordered_set>

using namespace std;

// WDS = With (additional) Data Structures
bool uniqueStringCharactersWDS(string s) {
	unordered_set<char> seen;
	
	for (char c: s) {
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
