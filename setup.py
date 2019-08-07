from distutils.core import setup, Extension
from Cython.Build import cythonize

extension = Extension("pytrie",  # name of extension
                      sources = ["cython/pytrie.pyx"],  # filename of our Cython source
                      language="c++",  # this causes Cython to create c++ source
                      include_dirs=['include/', 'src/']
                      )
#                       include_dirs=[...],  # usual stuff
#                       libraries=[...],  # ditto
#                       extra_link_args=[...],  # if needed
# )

setup(name='My Trie',
      ext_modules=cythonize(extension))
