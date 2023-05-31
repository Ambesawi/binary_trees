#include "binary_trees.h"

/**
 * binary_tree_insert_right - A function that Insert a node as the right-child
 *                            of another in a binary tree.
 * @parent: - is a pointer to the parent node of the node to create.
 * @value: - is the value to put in the new node.
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 * Description: If parent already has a right-child, the new node must
 *              take its place, and the old right-child must be set as the
 *              right-child of the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new->right = parent->right;
		parent->right->parent = new;
	}
	parent->right = new;

	return (new);
}
