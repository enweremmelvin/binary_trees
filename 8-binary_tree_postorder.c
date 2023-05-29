#include "binary_trees.h"

/**
 * binary_tree_postorder - print the data in nodes \
 *                         of a binary tree using the post order traversal
 *
 * @tree: binary tree to be traversed
 * @func: function to be called on each traversal
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if ((tree == NULL) || (func == NULL))
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
