#pragma once
#include <string>
#include <map>

using namespace std;


class Trie {
private:
	struct Node root;
public:
	void add_word(string word);

	bool find(string word);
};