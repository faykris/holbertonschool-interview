#include "binary_trees.h"


/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!*root)
	{
		return (*root = binary_tree_node(NULL, value));
	}
	else
	{
		if (value >= (*root)->n)
		{
			new = binary_tree_node(NULL, value);
			(*root)->parent = new;
			if (!new->left)
				new->left = *root;
			else if (!new->right)
				new->right = *root;
			*root = new;
		}
		else
		{
			new = binary_tree_node(*root, value);
			new->parent = *root;
			if (!(*root)->left)
				(*root)->left = new;
			else if (!(*root)->right)
				(*root)->right = new;
		}
		return (new);
	}

	return (binary_tree_node(*root, value));
}
