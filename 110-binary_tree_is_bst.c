#include "binary_trees.h"

/**
 * add_node - add a new node to the end of queue
 *
 * @queue: queue to add a new node to
 * @node: value to add to <node> part of new queue node
 */

void add_node(queue_n *queue, binary_tree_t *node)
{
	queue_n *temp;
	queue_n *new_queue_node;

	if ((queue == NULL) || (node == NULL))
		return;

	temp = queue;

	new_queue_node = malloc(sizeof(queue_n));
	new_queue_node->node = node;
	new_queue_node->next = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_queue_node;
}


/**
 * binary_tree_size - find the size of a binary tree
 * --- size == all nodes inside the binary tree
 *
 * @tree: binary tree to be traversed
 *
 * Return: size of binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 1;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}


/**
 * check_greatness - check that tree abides by greatness order of
 *                   a valid binary search tree
 *
 * @tree: tree to be checked
 * @flag: flag to specify if tree is bst or not
 * @root: pointer to the root node of the tree
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
 * check_duplicate - check for duplicate values in the tree
 *
 * @tree: tree to check
 * @flag: flag to turn on if duplicate found
 */

void check_duplicate(const binary_tree_t *tree, int *flag)
{
	queue_n *queue, *temp_queue;
	int *val_array, array_size, i = 0, j;

	if (tree == NULL)
		return;

	queue = malloc(sizeof(queue_n));
	queue->node = tree->left->parent ? tree->left->parent : tree->left;
	queue->node = tree->right->parent ? tree->right->parent : tree->left;
	queue->next = NULL;
	array_size = binary_tree_size(tree);
	val_array = malloc(sizeof(int) * array_size);

	while (queue != NULL)
	{
		val_array[i] = queue->node->n;

		if (queue->node->left != NULL)
			add_node(queue, queue->node->left);
		if (queue->node->right != NULL)
			add_node(queue, queue->node->right);

		i++;
		temp_queue = queue->next;
		free(queue);
		queue = temp_queue;
	}

	for (i = 0; i <= array_size; i++)
	{
		for (j = i + 1; j <= array_size; j++)
		{
			if (val_array[i] == val_array[j])
			{
				*flag = 0;
				return;
			}
		}
	}
	free(val_array);
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

	check_duplicate(tree, &flag);
	check_greatness(tree, tree, &flag);

	return (flag);
}
