#include "binary_trees.h"

/**
 * validate_is_avl - check if tree is AVL
 *
 * @tree: binary tree pointer position
 * @min: minimum value
 * @max: maximum value
 * @height: height of the binary tree
 * Return: 1 if binary tree is AVL, otherwise 0
 */
int validate_is_avl(const binary_tree_t *tree, int min, int max, int *height)
{
    int h1 = 0, h2 = 0;

    if (!tree)
        return (1);
    if (tree->n <= min || tree->n >= max)
        return (0);
    if (!validate_is_avl(tree->left, min, tree->n, &h1) ||
        !validate_is_avl(tree->right, tree->n, max, &h2))
        return (0);
    *height = MAX(h1, h2) + 1;
    return (ABS(h1 - h2) <= 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 *
 * @tree: binary tree pointer
 * Return: 1 if tree is a valid AVL, otherwise 0
 *
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    int height;

    if (!tree)
        return (0);
    return (validate_is_avl(tree, INT_MIN, INT_MAX, &height));
}
