#pragma once
#include <string>
#include <map>

using namespace std;

struct Node {};

class Trie {
private:
	struct Node root;
public:
	void add_word(string word);

	bool find(string word);
};