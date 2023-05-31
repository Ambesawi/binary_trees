#include "binary_trees.h"

/**
 * binary_tree_is_root - A function Checks if a node is a root.
 * @node: Is a pointer to the node to check.
 * Return: 1 if node is a root, otherwise 0 If node is NULL, return 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
