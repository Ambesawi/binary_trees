#include "binary_trees.h"

/**
 * binary_tree_insert_left - Function that Inserts a node as the left-child.
 * @parent: - is a pointer to the parent node of the node to create
 * @value: - is the value to put in the new node
 * Description - If parent has a left-child, the new node must take its place.
 * Return: a pointer to the created node, or NULL on failure.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_tree;

	if (!parent)
		return (NULL);

	new_tree = malloc(sizeof(binary_tree_t));
	if (!new_tree)
		return (NULL);

	new_tree->n = value;
	new_tree->parent = parent;
	new_tree->right = NULL;
	new_tree->left = parent->left;
	parent->left = new_tree;
	
	if (new_tree->left)
		new_tree->left->parent = new_tree;
	return (new_tree);
}
