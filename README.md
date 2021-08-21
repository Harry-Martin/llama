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
    -Multiplication (element-wise)
    -Division (element-wise)
    -Identity
    
## Dependencies

        -Make
        -GNU gcc compiler
        -Unix style `find` command-line utility
        -C standard library


## Build Instructions

Instructions for how to build the library will be updated once the build system is finalised.
        
## TODO

    -Matrix
        -Multiplication
        -Row/Column switching
        -Row/Column multiplication
        -Row/Column Addition
        -Inverse
        -Transpose
        -Rotation
        -Perspective
        -Orthographic
    -Quarternion
    -Better build system
        -release / debug 
    -Unit Tests
    -Anything else I've forgotten!...
   

        
        
