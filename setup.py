from distutils.core import setup, Extension
from Cython.Build import cythonize

# reference: https://docs.python.org/2/distutils/apiref.html
setup(ext_modules = [Extension(
    "testc",
    include_dirs=[
    ],
    libraries=[],
    library_dirs=[],
    extra_compile_args=[
        "-std=c++11",
        "-O3"  # aggrassive optimization
    ],
    extra_link_args=[
        "-flto", # link-time optimization
        "-fuse-linker-plugin"
    ],
    sources=[
        "test.cxx"
    ],  # additional C/C++ source file(s)
    language="c++",
)
])
