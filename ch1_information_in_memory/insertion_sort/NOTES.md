# Notes on Multi-File Compilation

### Entry: April 24th, 2024

When using `g++`, the best way to compile this without `Makefile` implementations is to type

``` shell
g++ main.cpp insertion_sort.cpp -o sort_test
```

Where here we are compiling the two files together as args to g++ with the `-o` flag in place at the end to change the name of the output compiled binary. 

So far, I can only get `g++` to work with my current installations on this M2 MacBook, so we’ll stick with that for now. 

---

