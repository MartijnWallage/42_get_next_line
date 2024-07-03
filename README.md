# Get Next Line

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

Author: Martijn Wallage

A project of the 42 Core Curriculum.

Score: 125%.

## About

A function for getting the next line of a file. 

The size of the buffer can be set using the -D flag.

## Algorithm

A full line is a string that ends in `\n` or `EOF`.

As long as there is no full line in the buffer, keep reading from the file and appending the read bytes to the buffer.
As soon as there is a full line, remove it from the beginning of the buffer, and return the line.

The buffer has to be a static variable, so that it persists in between calls to get_next_line.

The main challenge in this project is to resolve all memory leaks.

## Bonus

Handle multiple file descriptors.
