# Advent of Code 2021
[Advent of Code](https://adventofcode.com/2021/about) is an Advent calendar of small programming puzzles for a variety of skill sets and skill levels that can be solved in any programming language you like.

This repository consists of my solutions in C++ for year 2021.

## How to run?
You need a compiler that supports `c++20`. I use `gcc 11.1.0`.

Each solution resides its own sub directory named `dayXX` in which you will find `main.cpp` and `input.txt`. Code blindly looks for `input.txt` within current directory so you need to run the solution from where `input.txt` is located.

```shell
$ cd day01
$ g++ --std=c++20 main.cpp -o main && ./main
1832
1858
```

Output consists of 2 lines each of which is the solution for part 1 and part 2 respectively.

Alternatively, you can build and run any source file from vscode on Linux.

## Assumptions and Notes
- Assuming all the inputs are in correct format and not user controlled, no input validation is implemented. Inputs that are not in correct format may crash the program.
- Inputs are not altered for the ease of parsing. They are parsed as downloaded from https://adventofcode.com
- Inputs may differ across users. You may need to replace the `input.txt` with your own input to get the correct answer.
