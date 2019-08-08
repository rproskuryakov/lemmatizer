#include <gtest/gtest.h>
#include "Trie.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>


TEST(TestTrieSuite, TestIsStringsInTrie)
{
    std::vector<std::string> corpus = {"привет", "пока", "голова", "притча", "приве"};
    int corpus_size = corpus.size();
    Trie TestTrie;
    for (int i = 0; i < corpus_size; ++i) {
        std::string word = corpus[i];
        TestTrie.add_word(word);
    }

    for (int i = 0; i < corpus_size; ++i) {
        std::string word = corpus[i];
        ASSERT_EQ(true, TestTrie.find(word)) << word << " found in trie";
    }
}


TEST(TestTrieSuite, TestIsStringsNotInTrie) {
    std::vector<std::string> corpus = {"привет", "пока", "голова", "притча", "приве"};

    int corpus_size = corpus.size();
    Trie TestTrie;

    for (int i = 0; i < corpus_size; ++i) {
        std::string word = corpus[i];
        TestTrie.add_word(word);
    }

    ASSERT_EQ(false, TestTrie.find("прив"));
    ASSERT_EQ(false, TestTrie.find("привета"));
    ASSERT_EQ(false, TestTrie.find("пок"));
    ASSERT_EQ(false, TestTrie.find(""));
    ASSERT_EQ(false, TestTrie.find("прит"));
    ASSERT_EQ(false, TestTrie.find("притч"));
    ASSERT_EQ(false, TestTrie.find("прива"));
    ASSERT_EQ(false, TestTrie.find("поке"));
    ASSERT_EQ(false, TestTrie.find("притче"));
    ASSERT_EQ(false, TestTrie.find("покемон"));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
