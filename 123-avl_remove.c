#include "binary_trees.h"

/**
 * bal - A function that Measures balance factor of a AVL.
 * @tree: is a tree to go through.
 * Return: balanced factor
 */

void bal(avl_t **tree)
{
	int b_val;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	bal(&(*tree)->left);
	bal(&(*tree)->right);
	b_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - A function that get the next successor
 *             i mean the min node in the right subtree.
 * @node: Is a tree to check.
 * Return: the min value of this tree
 */

int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}

}

/**
 *remove_type - A function that removes a node depending of its children.
 *@root: is a node to remove.
 *Return: 0 if it has no children or other value if it has.
 */

int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - A function that remove a node from a BST tree.
 * @root: is a root of the tree.
 * @value: is a node with this value to remove.
 * Return: the tree changed
 */

bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - A function that remove a node from a AVL tree.
 * @root: is a root of the tree.
 * @value: is a node with this value to remove.
 * Return: the tree changed
 */

avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
