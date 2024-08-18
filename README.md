# Overview

This project is a collection of source files that demonstrates random parts
about the C language and standard library that I have discovered and want to
remember. It is structured as a bunch of small executables that each targets a
different topic.

# Building

```bash
mkdir build
cd build
cmake ..
make -j8
```

## Compiler Support

This project makes use of C23 features whose availability is spotty on the
compilers that I've tested (gcc and clang). I have attempted to make the compile
work for at least the gcc and clang versions that are available in the Ubuntu
22.04 software repository.

### Using gcc

```bash
sudo update-alternatives --set cc /usr/bin/gcc
```

### Using clang
```bash
sudo update-alternatives --set cc /usr/bin/clang
```
