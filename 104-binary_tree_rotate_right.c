#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate the nodes of a binary tree right
 *
 * @tree: tree whose nodes are to be rotatd
 *
 * Return: NULL if tree is NULL ; otherwise new root of tree
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root;
	binary_tree_t *new_root;
	binary_tree_t *new_root_right;

	if (tree == NULL)
		return (NULL);

	if (tree->left == NULL)
		return (tree);

	old_root = tree;
	new_root = tree->left;
	new_root_right = tree->left->right;

	new_root->parent = NULL;
	new_root->right = old_root;
	old_root->parent = new_root;

	old_root->left = new_root_right;

	if (new_root_right != NULL)
		new_root_right->parent = old_root;

	tree = new_root;

	return (tree);
}
