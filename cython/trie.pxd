from libcpp.string cimport string
from libcpp cimport bool

cdef extern from "Trie.cpp":
    pass

# Declare the class with cdef
cdef extern from "Trie.h": # namespace "name"
    cdef cppclass Trie:
        Trie() except + # constructor
        void add_word(string word)
        bool find(string word)
