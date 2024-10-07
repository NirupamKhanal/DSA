# Data Structures and Algorithms in C++ and C

This repository contains various data structures and algorithms implemented in C++ and C. The project is organized into sections that cover Pointers and shell scripts, Data Structures, and Algorithms.

## 1. Pointers and Shell Scripts

### 1.1 Pointers

**Pointers** are variables that store the memory address of another variable. They are one of the most powerful and flexible features in C/C++ programming, enabling dynamic memory management, efficient array handling, and direct manipulation of hardware-level operations. Pointers allow for:

- **Referencing/Pointing** to memory locations.
- **Passing by reference** to modify variables directly.
- **Dynamic Memory Allocation** using `new` and `delete` (or `malloc` and `free` in C).
- **Multiple indirection** with double and triple pointers (pointers to pointers).

Key types of pointers include:
- **Basic Pointers**: Store the address of a variable.
- **Smart Pointers**: Automatically manage memory allocation and deallocation (e.g., `shared_ptr`, `unique_ptr` in C++).
- **Weak Pointers**: Prevent cyclic references in shared ownership scenarios.
- **Double Pointers**: Pointers to other pointers.
- **Parameterized Pointers**: Pointers that work with any data type, typically using templates in C++.

Common use cases of pointers include:
- Dynamic memory management for arrays and data structures like linked lists and trees.
- Efficient function parameter passing to avoid copying large data structures.
- Resource management in complex systems (e.g., file handling, networking buffers).

Example:
```cpp
int* ptr = new int(10);  // Dynamic memory allocation
``` 

### 1.2 Makefile

A **makefile** is a **shell script file** that defines a set of tasks to be executed. Here, we create a Makefile for compiling C/C++ programs with pointers and memory management functions.

**Shell Scripts** are executable files written in the `Bash` language, a `Unix` shell and command language. They are widely used for automating repetitive tasks, running multiple commands, and managing system configurations.

A typical shell script consists of a series of commands that can:
- **Automate compilation processes** (e.g., `MakeFile`).
- Handle **system administration** tasks like file management, backups, and permissions.
- Simplify **project builds** by automating the execution of commands in sequence.

In the context of C/C++ projects, shell scripts are often used to compile and run code, clean up directories, and automate testing.

**Example:**

```bash
#!/bin/bash
# A simple bash script to compile and run a C++ program

g++ -o program main.cpp  # Compile the C++ code
./program                # Run the program
```

### 1.3 Dynamic Memory Allocation

Dynamic memory allocation allows us to allocate memory during runtime using `malloc`, `calloc`, `new`, and `delete` in C/C++.

Use Case: Used in scenarios where the size of the data structure is not known at compile time, such as dynamic arrays, linked lists, and graphs.

```cpp
int main(int argc, char * argv[]) {
    int * dynamic_array; 

    if(argc != 2) {
        cout << "Usage: " << argv[0] << " <num elements\n";
        return 1; 
    }

    int num_elements = atoi(argv[1]);
    dynamic_array = new int[num_elements]; 

    set_all_elements(dynamic_array, 13, num_elements);
    
    cout << "Printing a dynamically allocated array " 
        << "with " << argv[1] << " elements.\n";
    
    for(int i = 0; i < num_elements; ++i) {
        cout << "index[" << i << "]: " << dynamic_array[i] << endl;
    }
    cout << endl;

    delete[] dynamic_array; 

    return 0;
}
```

## 2. Data Structures

**Data Structures** are ways of organizing and storing data to facilitate efficient access and modifications. They form the backbone of algorithm design and are critical for solving computational problems in an optimized manner. Different data structures excel at different types of tasks, and the choice of the right data structure can significantly impact the performance of a program.

Some of the most common types of data structures are:

### 2.1 **Linear Data Structures**: 
   - **Arrays**: Fixed-size collections of elements stored sequentially in memory.
   - **Linked Lists**: Dynamic data structures where elements (nodes) point to the next element, making insertion and deletion efficient.
   - **Stacks**: Last-In-First-Out (LIFO) structures that allow operations only at one end (push/pop).
   - **Queues**: First-In-First-Out (FIFO) structures that allow operations at both ends (enqueue/dequeue).

### 2.2 **Tree Data Structures**: 
   - **Binary Trees**: Hierarchical data structures where each node has at most two children (left and right).
   - **Binary Search Trees (BST)**: A binary tree with the property that the left child is smaller than the parent and the right child is greater.
   - **AVL Trees**: Self-balancing BSTs where the heights of the left and right subtrees differ by at most one.
   - **Red-Black Trees (RB Trees)**: Another type of self-balancing BST that ensures the tree remains balanced during insertions and deletions.

### 2.3 **Hash Tables**: 
   A data structure that maps keys to values using a hash function. It provides efficient average-case time complexity for search, insertion, and deletion.

### 2.4 **Graph Data Structures**:
   A graph consists of a set of nodes (vertices) and edges (connections between nodes). Graphs can be used to model networks, relationships, and traversals.

### 2.5 **Tries (Prefix Trees)**: 
   A specialized tree used to store dynamic sets of strings where common prefixes are shared, making operations like prefix search very efficient.

### Importance of Data Structures
Data structures are essential for:
- **Efficient storage and retrieval** of data.
- **Optimized algorithms** for searching, sorting, and organizing information.
- **Memory management** in applications.
- **Solving complex problems** like shortest path, sorting, searching, and dynamic programming.

Choosing the right data structure is crucial for reducing the time and space complexity of algorithms, and understanding them is fundamental to good software engineering.

### Use Cases of Data Structures
- **Arrays**: Used in situations where random access is needed (e.g., accessing elements by index).
- **Linked Lists**: Ideal when frequent insertions and deletions are needed without shifting elements.
- **Binary Search Trees**: Useful for maintaining sorted data and performing searches efficiently.
- **Hash Tables**: Perfect for cases requiring quick lookups (e.g., database indexing, caching).
- **Tries**: Often used in applications involving text processing, such as autocomplete and spell checking.

## 3. Algorithms
## Algorithms

**Algorithms** are a set of well-defined instructions or steps to solve a particular problem or perform a specific task. In computer science, algorithms form the core of programming as they guide the computer in processing data, solving problems, and making decisions.

Algorithms are typically evaluated based on two key criteria:

1. **Time Complexity**: How the execution time of an algorithm grows with the input size. The goal is to minimize the time taken for large input sizes.
   
2. **Space Complexity**: How the memory usage of an algorithm grows with the input size. Efficient algorithms use minimal memory while processing data.

### Types of Algorithms

### 3.1 **Sorting Algorithms**:
   Sorting algorithms rearrange elements in a specific order (e.g., ascending or descending). Popular sorting algorithms include:
   - **Bubble Sort**: A simple comparison-based algorithm where adjacent elements are repeatedly swapped if they are in the wrong order.
   - **Merge Sort**: A divide-and-conquer algorithm that recursively splits an array into two halves, sorts them, and then merges them back together.
   - **Quick Sort**: Another divide-and-conquer algorithm that selects a pivot element, partitions the array around the pivot, and recursively sorts the partitions.

   Sorting algorithms are critical in applications like data analytics, file organization, and searching tasks.

### 3.2 **Search Algorithms**:
   Searching algorithms find an element within a collection. Common searching algorithms include:
   - **Linear Search**: Sequentially checks each element in the list until the target is found.
   - **Binary Search**: Efficient algorithm that works on sorted arrays by repeatedly dividing the search interval in half.

   Search algorithms are essential for tasks like searching in databases, handling requests, and looking up information.

### 3.3 **Greedy Algorithms**:
   Greedy algorithms make the best possible decision at each step, with the hope of finding a global optimum. Examples include:
   - **Dijkstra’s Algorithm**: Finds the shortest path between nodes in a weighted graph.
   - **Kruskal’s Algorithm**: Finds the minimum spanning tree in a graph by selecting edges with the least weight.

   Greedy algorithms are often used in optimization problems, such as network design, scheduling, and resource allocation.

### 3.4 **Dynamic Programming (DP)**:
   Dynamic programming breaks a problem into smaller overlapping subproblems, solving each only once and storing the results for future use. Examples include:
   - **Fibonacci Sequence**: DP can optimize the computation of Fibonacci numbers by remembering previously computed values.
   - **Knapsack Problem**: DP can be used to find the optimal solution to choosing items without exceeding a weight limit.

   DP is especially useful for problems involving optimization and decision-making over time.

### 3.5 **Divide and Conquer**:
   Divide and conquer algorithms break down a problem into smaller subproblems, solve them independently, and combine their solutions. Examples include:
   - **Merge Sort** and **Quick Sort**: Both use divide and conquer to sort large datasets.
   - **Binary Search**: This algorithm divides the search space in half each time, reducing the number of comparisons.

   Divide and conquer algorithms are useful for problems involving large datasets, like sorting, searching, and matrix operations.

### 3.6 **Backtracking**:
   Backtracking is an algorithmic technique that incrementally builds candidates to a solution and abandons a candidate ("backtracks") if it fails to satisfy the conditions of the problem. Examples include:
   - **Sudoku Solver**: Backtracking can be used to fill in numbers while verifying constraints.
   - **N-Queens Problem**: Backtracking is used to place queens on a chessboard such that no two queens threaten each other.

   Backtracking is useful in constraint satisfaction problems like puzzles, combinatorics, and optimization.

### Importance of Algorithms
- **Efficiency**: Algorithms are crucial for optimizing the use of resources (time and space).
- **Scalability**: Good algorithms can handle growing input sizes efficiently, making them essential for large-scale systems and applications.
- **Problem Solving**: Algorithms are the tools we use to tackle computational problems, from simple tasks to complex real-world challenges like machine learning, networking, and cryptography.

### Use Cases of Algorithms
- **Sorting Algorithms**: Used in file systems, databases, search engines, and data analysis.
- **Search Algorithms**: Used in search engines, recommendation systems, and query processing.
- **Greedy Algorithms**: Applied in network routing, scheduling problems, and financial modeling.
- **Dynamic Programming**: Useful in solving optimization problems in finance, operations research, and bioinformatics.
- **Divide and Conquer**: Critical for handling large datasets, image processing, and numerical simulations.
