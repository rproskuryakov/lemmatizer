from trie cimport Trie  # link to according .pxd file

# Create a Cython extension type which holds a C++ instance
# as an attribute and create a bunch of forwarding methods
# Python extension type.
cdef class PyTrie:
    cdef Trie c_tree # Hold a C++ instance which we're wrapping

    def __cinit__(self):
        self.c_tree = Trie()

    def add_word(self, word): # word is a python string
        return self.c_tree.add_word(word) # word is a c++ string

    def find(self, word): # word is a python string
        return self.c_tree.find(word)