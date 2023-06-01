#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate the nodes of a binary tree left
 *
 * @tree: tree whose nodes are to be rotated
 *
 * Return: new root of the binary tree
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *new_root_left;

	if (tree == NULL)
		return (NULL);
	if (tree->right == NULL)
		return (tree);

	old_root = tree;
	new_root = tree->right;
	new_root_left = tree->right->left;

	new_root->parent = NULL;
	new_root->left = old_root;
	old_root->parent = new_root;

	old_root->right = new_root_left;

	if (new_root_left != NULL)
		new_root_left->parent = old_root;

	tree = new_root;

	return (tree);
}
