#pragma once
#include <string>
#include <map>


typedef struct Node {
    std::map<char, struct Node*> children;
    char letter;
    bool is_end_of_word = false;
} Node;


class Trie {
private:
    Node* root;

    //void destroy_recursive(Node* node);
public:
    Trie ();

    //~Trie();

	void add_word(std::string word);

	bool find(std::string word);
};