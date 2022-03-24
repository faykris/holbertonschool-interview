#include "binary_trees.h"

/**
 * create_node - creates a binary tree node
 * @parent: pointer of tree node
 * @value: integer number to be added
 *
 * Return: pointer new node created
 */
avl_t *create_node(binary_tree_t *parent, int value)
{
	avl_t *new_node;

	new_node = malloc(sizeof(avl_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = NULL;
	if (parent != NULL)
	{
		new_node->parent = parent;
	}
	return (new_node);
}

/**
 * insert_node - recursively sorted node insertion
 * @array: first array element pointer
 * @min: minimum limit value
 * @max: maximum limit value
 *
 * Return: root node poiter, otherwise NULL on error
 */
avl_t *insert_node(int *array, int min, int max)
{
	int middle;
	avl_t *tree;

	if (!array || min > max)
		return (NULL);

	middle = (max + min) / 2;

	tree = create_node(NULL, array[middle]);
	if (!tree)
		return (NULL);

	tree->left = insert_node(array, min, middle - 1);
	tree->right = insert_node(array, middle + 1, max);
	if (tree->left)
		tree->left->parent = tree;
	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: first array element pointer
 * @size: quantity of the array elements
 *
 * Return:root node poiter, otherwise NULL on error
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (insert_node(array, 0, (int)size - 1));
}
