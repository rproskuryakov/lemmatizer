#include <iostream>
#include <string>
#include <map>
#include "trie.h"
using namespace std;

struct Node {
	map<char, struct Node*> children;
	char letter;
	bool is_end_of_word = false;
};


class Trie {
private:
	struct Node root;
public:
    Trie () {};

	void add_word(string word) {
		struct Node* current_node = &root;
		int length = word.size();

		for (int i = 0; i < length; i++) {
			const char letter = word[i];
			bool is_in_node = (*current_node).children.count(letter);

			if (is_in_node) {
				current_node = (*current_node).children[letter];
			}
			else {
				struct Node node;
				node.letter = letter;
				(*current_node).children.insert(pair<const char, struct Node*>(letter, &node));
				current_node = &node;
			}
			if (i == length - 1) {
				(*current_node).is_end_of_word = false;
			}
		}
	}

	bool find(string word) {
		struct Node* current_node = &root;
		int length = word.size();

		for (int i = 0; i < length; i++) {
			//����������� �� �����
			const char letter = word[i];
			bool is_in_node = (*current_node).children.count(letter);
			if (is_in_node) {
				current_node = (*current_node).children[letter];
			}

			if (i == length - 1 && (*current_node).is_end_of_word) {
				return true;
			}
		}
		return false;
	}
};