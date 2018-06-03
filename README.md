# scratch



## Overview

- [Prerequisites](#prerequisites)
- [Build](#build)
- [Programs](#usage)



## Prerequisites

- cmake >= 3.0.0
- a C11-compliant compiler
- a C++17-compliant compiler
- doxygen >= 1.8.0 (optional)



## Build

```
$ git clone https://github.com/wrpaape/scratch.git
$ mkdir scratch/build
$ cd scratch/build
$ cmake ..
$ cmake --build .

```



## Programs
built executables will be output to `bin`


### base_converter
changes the numerical base representation of a number

#### usage
```
./base_converter <number> <base_number> <base_desired>
```

#### example
```
./base_converter DEADBEEFCAFEBABE 16 10
16045690984503098046
```
