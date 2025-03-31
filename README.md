# Generalized m-ary Heap 

## Project Overview
The efficiency of priority queue implementations significantly impacts the performance of various algorithms, such as Huffman coding, Dijkstra's algorithm, and Kruskal's algorithm. One efficient way to implement a priority queue is by using heap trees.
This project involves implementing a generalized binary heap, specifically an m-ary heap, using a vector-based representation. A generalized m-ary heap is a complete or nearly complete m-ary tree that follows the heap property. For example, a binary heap is a 2-heap, a ternary heap is a 3-heap, and so on. This implementation focuses on a min-m-heap.

## Technologies Used
- **Backend:** C++

## Features
The project includes a C++ implementation of a heap structure containing integer keys, with the following operations:
- **void init(int m)** - Creates a new (empty) m-ary heap.
- **void add(int elem, int &steps)** - Inserts an element into the heap.
- **int get()** - Retrieves the minimum element from the heap.
- **int delete(int &steps)** - Removes the minimum element from the heap.
- **void convertTo(int newM)** - Converts the heap into a heap of a specified order.
- **void union(Heap h, int &steps)** - Merges two heaps into one, modifying the existing heap.
- **operator<<** - Prints the heap as an m-ary tree.
- **void destroy()** - Deletes and deallocates the heap.
- **Additional feature:** Deleting an arbitrary key.
Each insertion, deletion, and merging operation returns the number of steps taken to complete the operation, including comparisons and swaps.

## Implementation Details
Proper memory management is ensured.
Additional necessary methods (such as constructors and destructors) are implemented.
The implementation includes an interactive menu allowing the user to interact with public heap methods.
The program allows data to be loaded from a command line, a file, or randomly generated.
