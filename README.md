# LLAMA (Library for Linear Algebra Mathematics)

Llama is a library, written in C, which provides functionality useful for solving linear systems. Namely, Vector and Matrix types and their common operations. The Library also provides functionality useful for 3D graphics applications such as creating a perspective matrix.

## Features

### Vector

All vector features support n-dimensional vectors with one obvious exception, the cross product is only defined for 3-dimensional vectors!

        -Addition
        -Subtraction
        -Multiplication (component-wise)
        -Division (component-wise)
        -Scalar Addition
        -Scalar Subtraction
        -Scalar Multiplication
        -Scalar Division
        -Magnitude
        -Normalisation
        -Dot Product
        -Angle
        -Cross Product
        
### Matrix

    -Addition
    -Subtraction
    -Multiplication
    -Transpose
    -Submatrix
    -Determinant
    -Identity
    -Minor matrix
    -Cofactor matrix
    -Adjugate
    -Inverse
    -Multiplication (element-wise)
    -Division (element-wise)

### Utilties

    -Rotation Matrix (3x3)

## Dependencies

    -To build the library
        -Make
        -GNU gcc compiler
        -Unix style `find` command-line utility
        -C standard library
    -To Link against the library
        -C Math Library (`-lm` flag)


## Build Instructions

Clone the repo.
`git clone https://www.github.com/harry-martin/llama`
Go to root directory of the cloned repo
`cd llama`
Build static and shared library.
`make`

To build example
`make example`
NOTE: the example currently links against the shared library. To run the example, you may have to move the shared library to `/usr/lib/` or set the environment variable `LD_LIBRARY_PATH=$(pwd)` in the root directory.
to run example
`./example/example`

## Usage Instructions

To use this library, you will need to link against either the static or shared library.
If you wish to move the shared library to your /usr/lib/ directory, you can do so with `make install`.
You can find the header files for this library in the `include/` directory.

I will update the repo with examples on how to use the library at a later stage.

        
## TODO

    -Matrix
        -Row/Column switching
        -Row/Column multiplication
        -Row/Column Addition
        -Matrix Scaling
        -Vector Scaling
    -Quarternion
    -Better build system
        -release / debug 
    -Unit Tests
    -Anything else I've forgotten!...
   

        
        
