#include "binary_trees.h"
#include <stdio.h>


/**
 * count_nodes - count the number of children a tree has
 *
 * @tree: tree whose children are to be counted
 *
 * Return: 0 if tree is NULL ; otherwise, the number of children found
 */

int count_nodes(binary_tree_t *tree)
{
	static int count = 1;

	if (tree == NULL)
		return (0);

	if (tree->parent->parent == NULL)
		count = 1;

	count += 1;

	count_nodes(tree->left);
	count_nodes(tree->right);

	return (count - 1);
}

/**
 * binary_tree_is_perfect - check if a binary tree is perfect
 * - i.e. all leaf nodes are on the same level and every other node \
 * -+ (except leaf nodes) have two children
 *
 * @tree: binary tree to check if perfect
 *
 * Return: 1 if perfect ; 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	static int check_null = 1;
	int left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	if (tree->parent == NULL)
	{
		left_nodes = count_nodes(tree->left);
		right_nodes = count_nodes(tree->right);

		if (left_nodes != right_nodes)
			return (0);
		else
			return (1);
	}

	binary_tree_is_perfect(tree->left);
	binary_tree_is_perfect(tree->right);

	if (tree->left == NULL && tree->right != NULL)
		check_null = 0;
	if (tree->right == NULL && tree->left != NULL)
		check_null = 0;
	if (tree->left == NULL && tree->right == NULL)
		check_null = 1;

	return (check_null);
}
