#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts nodes with at least 1 child in a binary tree.
 * @tree: A pointer to  root node of the tree to count the number of nodes.
 * Return: If tree is NULL,it must return 0, else return node count.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree)
	{
		nodes += (tree->left || tree->right) ? 1 : 0;
		nodes += binary_tree_nodes(tree->left);
		nodes += binary_tree_nodes(tree->right);
	}
	return (nodes);
}
