# C - Binary Trees

## Description

This project delves into the realm of binary trees, exploring concepts such as binary trees, binary search trees, tree traversal methods, and the characteristics of different types of binary trees. The goal is to deepen understanding of data structures and algorithms related to binary trees.

## Learning Objectives

By the end of this project, you should be able to:

- Explain what a binary tree is.
- Differentiate between a binary tree and a Binary Search Tree (BST).
- Understand the potential gain in terms of time complexity compared to linked lists.
- Define and explain the concepts of depth, height, and size of a binary tree.
- Familiarize yourself with different traversal methods to navigate through a binary tree.
- Describe a complete, full, perfect, and balanced binary tree.

## Project Requirements

- Use allowed editors: vi, vim, emacs.
- All files will be compiled on Ubuntu 20.04 LTS using gcc with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- End all files with a new line.
- A `README.md` file, at the root of the folder of the project, is mandatory.
- Your code should follow the Betty style. It will be checked using `betty-style.pl` and `betty-doc.pl`.
- You are not allowed to use global variables.
- No more than 5 functions per file.
- You are allowed to use the standard library.
- The prototypes of all your functions should be included in your header file called `binary_trees.h`.
- Don’t forget to push your header file.
- All your header files should be include guarded.

## Data Structures

Please use the following data structures and types for binary trees. Include them in your `binary_trees.h` header file:

### Basic Binary Tree
```c
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
