#include "binary_trees.h"

/**
 * check_greatness - check that tree abides by greatness order of
 *                   a valid binary search tree
 *
 * @tree: tree to be checked
 * @flag: flag to specify if tree is bst or not
 * @root: pointer to root node
 */

void check_greatness(const binary_tree_t *tree,
		     const binary_tree_t *root,  int *flag)
{
	if (tree == NULL)
		return;

	if (tree->left != NULL)
	{
		if (tree->left->n > tree->n)
		{
			*flag = 0;
			return;
		}

		if (tree->left->right != NULL)
		{
			if (tree->left->right->n > root->n)
			{
				*flag = 0;
				return;
			}
		}
	}

	if (tree->right != NULL)
	{
		if (tree->right->n < tree->n)
		{
			*flag = 0;
			return;
		}
		if (tree->right->left != NULL)
		{
			if (tree->right->left->n < root->n)
			{
				*flag = 0;
				return;
			}
		}
	}

	check_greatness(tree->left, root, flag);
	check_greatness(tree->right, root, flag);
}


/**
 * binary_tree_is_bst - check if a binary tree is a binary search tree
 *
 * @tree: binary tree to be checked
 *
 * Return: 1 if tree is a binary search tree ; 0 otherwise or if tree == NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int flag = 1;

	if (tree == NULL)
		return (0);

	check_greatness(tree, tree, &flag);

	return (flag);
}
