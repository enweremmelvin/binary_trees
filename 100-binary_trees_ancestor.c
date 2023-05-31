#include "binary_trees.h"

/**
 * look_up_second - search for the ancestor of given nodes by looking \
 *                  upwards from second node
 *
 * @root: current root to be looked at
 * @second: node to try matching underneath root
 *
 * Return: NULL if (second is null or no ancestor found) otherwise sec parent
 */

binary_tree_t *look_up_second(binary_tree_t *root, binary_tree_t *second)
{
	binary_tree_t *temp_second;

	if (second == NULL)
		return (NULL);

	temp_second = second;
	look_up_second(root, second->parent);

	while (temp_second != NULL)
	{
		if ((root->left == temp_second->parent) ||
		    (root->right == temp_second->parent))
			return (temp_second->parent);

		temp_second = temp_second->parent;
	}

	return (NULL);
}

/**
 * get_second_ancestor - find the second node under current root
 *
 * @root: current root to search for second in
 * @second: second node to be searched for
 *
 * Return: NULL if second node not found ; otherwise return root
 */

binary_tree_t *get_second_ancestor(binary_tree_t *root, binary_tree_t *second)
{
	if ((root == NULL) || ((root->left == NULL) && (root->right == NULL)))
		return (NULL);

	if ((root->left == second) || (root->right == second))
		return (root);

	get_second_ancestor(root->left, second);
	get_second_ancestor(root->right, second);

	return (NULL);
}


/**
 * get_ancestor - try to find the lowest common ancestor of node
 *
 * @first: first node
 * @second: second node
 * @ancestor: pointer to ancestor
 * @n: number of times to iterate upwards a node's parent
 *
 * Return: 1 if ancestor found ; 0 otherwise
 */

int get_ancestor(const binary_tree_t *first,
		 const binary_tree_t *second,
		 binary_tree_t **ancestor, int n)
{
	int i;
	binary_tree_t *temp, *sec;

	if ((first == NULL) || (second == NULL) ||
	    (first->parent == NULL))
		return (0);

	sec = second->parent;
	temp = first->parent;

	/*redundant assignment to bypass const assignment restrictions*/
	sec->left == second ? sec = sec->left : 1 * 0;
	sec->right == second ? sec = sec->right : 1 * 0;
	temp->left == first ? temp = temp->left : 1 * 0;
	temp->right == first ? temp = temp->right : 1 * 0;

	for (i = 0; ((i < n) && (temp->parent != NULL)); i++)
		temp = temp->parent;

	if (temp != NULL)
	{
		/* search for second node under current parent */
		if (get_second_ancestor(temp, sec) != NULL)
		{
			*ancestor = temp;
			return (1);
		}
		else if (look_up_second(temp, sec) != NULL)
		{
			*ancestor = temp;
			return (1);
		}
	}

	return (0);
}


/**
 * binary_trees_ancestor - find the lowest common ancestor
 *                         of two nodes in a binary tree
 *
 * @first: first node
 * @second: second node
 *
 * Return: pointer to lowest common ancestor of the two nodes \
 *         or NULL if there is no common ancestor for the two given nodes
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	int i, ret_val;
	binary_tree_t *ancestor = NULL;

	if ((first == NULL) || (second == NULL))
		return (NULL);

	if (((first->parent == NULL) &&
	    (first->left == NULL) && (first->right == NULL)) ||
	    ((second->parent == NULL) && (second->left == NULL) &&
	     (second->right == NULL)))
		return (NULL);

	/*return root node if either of nodes is root*/
	if (first->parent == NULL)
		return (first->left->parent);
	else if (second->parent == NULL)
		return (second->left->parent);

	/*return either node if both nodes are same*/
	if (first == second)
	{
		if (first->parent->left == first)
			return (first->parent->left);
		else
			return (first->parent->right);
	}

	for (i = 0; i < 100; i++)
	{
		ret_val = get_ancestor(first, second, &ancestor, i);

		if (ret_val == 1)
			break;
	}

	return (ancestor);
}
