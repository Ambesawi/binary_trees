#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth
 *                     of a node in a binary tree.
 * @tree: is a pointer to the node to measure the depth.
 * Return: If tree is NULL, your function must
 *         return 0, else return the depth.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
