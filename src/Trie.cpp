#include <iostream>
#include <string>
#include <map>
#include "Trie.h"


// constructor
Trie::Trie() {
    root = new Node;
    root->is_end_of_word = false;
    root->letter = '0';
};


void Trie::add_word(std::string word) {
    Node* current_node = root;
    int length = word.size();
    bool end_of_word;

    for (int i = 0; i < length; ++i) {
        char letter = word[i];
        bool is_in_node = current_node->children.count(letter);

        end_of_word = i == length - 1;

        if (is_in_node) {
            current_node = current_node->children[letter];
        } else {
            Node* node = new Node;
            node->letter = letter;
            current_node->children.insert(std::pair<char, Node*>(letter, node));
            current_node = node;
        }
        if (end_of_word) {
            current_node->is_end_of_word = true;
        }
    }
}


bool Trie::find(std::string word) {
    Node* current_node = root;
    int length = word.size();

    for (int i = 0; i < length; i++) {
        char letter = word[i];
        bool is_in_node = current_node->children.count(letter);
        bool end_of_word = i == length - 1;

        if (is_in_node) {
            current_node = current_node->children[letter];
        } else {
            break;
        }

        if (end_of_word) {
            return current_node->is_end_of_word;
        }
    }
    return false;
}