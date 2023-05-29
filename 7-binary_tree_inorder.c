#include "binary_trees.h"

/**
 * binary_tree_inorder - print the data stored in the nodes \
 *                       of a binary tree using the inorder recursive method
 *
 * @tree: binary tree to be traversed
 * @func: function to call on each traversal
 */

void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((tree == NULL) || (func == NULL))
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
