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
 *
 *
 *
 *
 *
 */

void check_duplicate(const binary_tree_t *tree, int *index, int **ar)
{
	if (tree == NULL)
		return;

	(*ar)[*index] = tree->n;
	*index += 1;

	check_duplicate(tree->left, index, ar);
	check_duplicate(tree->right, index, ar);
}

/**
 * binary_tree_size - find the size of a binary tree
 * --- size == all nodes inside the binary tree
 *
 * @tree: binary tree to be traversed
 *
 * Return: size of binary tree
 */

size_t tree_size(const binary_tree_t *tree)
{
	int size = 1;

	if (tree == NULL)
		return (0);

	size += tree_size(tree->left);
	size += tree_size(tree->right);

	return (size);
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
	int flag = 1, i, j, index = 0, *int_array = NULL;

	if (tree == NULL)
		return (0);

	check_greatness(tree, tree, &flag);

	if (flag == 1)
	{
		int_array = malloc(sizeof(int) * (tree_size(tree) + 1));
		check_duplicate(tree, &index, &int_array);

		for (i = 0; i < (int) tree_size(tree); i++)
		{
			for (j = 0; j < (int) tree_size(tree); j++)
			{
				if (i == j)
					continue;

				if (int_array[i] == int_array[j])
					flag = 0;
			}
		}

		free(int_array);
	}

	return (flag);
}
