#include <iostream>
#include <string>
#include <map>
#include "../include/trie.h"
using namespace std;


int main() {
	int n_cases = 0;
	int n_words = 0;
	string word;
	string search_word;
	bool is_here;

	cin >> n_cases;
	for (int i = 0; i < n_cases; i++) {
		Trie TestTrie;
		cin >> n_words;
		for (int j = 0; j < n_words; j++) {
			cin >> word;
			TestTrie.add_word(word);
		}
		cin >> search_word;
		is_here = TestTrie.find(search_word);
		cout << is_here << endl;
	}
	return 0;
}

