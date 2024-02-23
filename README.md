## LRU Cache Implementation in C
By Eloi Dieme

This project implements a Least Recently Used (LRU) Cache in C, utilizing a custom-built doubly linked list and hash table for efficient storage and retrieval. The LRU cache is designed to store a specified number of key-value pairs and evicts the least recently used item when the capacity is exceeded.

### Features

* Efficient Access: O(1) time complexity for both put and get operations.
* Custom Data Structures: Utilizes a doubly linked list for tracking usage order and a hash table for fast lookup.
* Scalable: Designed to handle a large number of key-value pairs efficiently.

### Getting Started

#### Prerequisites
Ensure you have a C compiler (such as gcc or clang) installed on your system to compile the project. You can check your installation by running:
```bash
gcc --version
```
or
```bash
clang --version
```

#### Installation
* Clone the Repository
```bash
git clone https://github.com/eloidieme/LRU-Cache.git
cd LRU-Cache
```
* Build the Project
Use the provided Makefile to compile the project:
```bash
make
```
This command will compile the source files and generate the executable.

#### Running the Program
After building the project, you can run the LRU cache implementation using:
```bash
./bin/prog
```

### Usage

The LRU cache implementation can be utilized in C programs requiring cache functionality. By default, the main file contains .... Here's a basic example of how to use the cache:

```c
#include "lru_cache.h"

int main() {
    // Initialize the LRU cache with a capacity of 5
    LRUCache* cache = lru_cache_create(5);

    // Clean up
    lru_cache_destroy(cache);

    return 0;
}
```

### Customization

You can customize the LRU cache implementation according to your needs. The key-value types are defined as heap-allocated strings by default, but you can modify lru_cache.h and lru_cache.c to support other data types.
