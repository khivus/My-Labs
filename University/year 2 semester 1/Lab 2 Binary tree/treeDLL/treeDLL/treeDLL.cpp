#include "pch.h"
#include "treeDLL.h"

Treenode* addnode(Treenode* tree, int key, int x, int y, Treenode* parent, int lvl) {
    if (tree == NULL) {
        tree = new Treenode;
        tree->number = key;
        tree->left = NULL;
        tree->right = NULL;
        tree->x = x;
        tree->y = y;
        tree->parent = parent;
        tree->lvl = lvl;
    }
    else if (key <= tree->number)
        tree->left = addnode(tree->left, key, tree->x, tree->y + 50, tree, lvl + 1);
    else
        tree->right = addnode(tree->right, key, tree->x, tree->y + 50, tree, lvl + 1);
    return tree;
}

void destroy_tree(Treenode* tree) {
    if (tree) {
        if (tree->left)
            destroy_tree(tree->left);
        if (tree->right) destroy_tree(tree->right);
        if (tree->parent) {
            if (tree->parent->right == tree)
                tree->parent->right = NULL;
            if (tree->parent->left == tree)
                tree->parent->left = NULL;
        }
        else
            tree = NULL;
        delete tree;
        tree = NULL;
    }
}

int summing(Treenode* tree) {
	if (tree != NULL) {
		return (tree->number + summing(tree->left) + summing(tree->right));
	}
}

int find_maxlvl(Treenode* tree, int x) {
    int maximum;
    if (tree != NULL) {
        int a = find_maxlvl(tree->left, tree->lvl);
        int b = find_maxlvl(tree->right, tree->lvl);
        if (a > x || b > x) {
            if (a > b)
                x = a;
            else
                x = b;
        }
        maximum = x;
    }
    else
        maximum = x;
    return maximum;
}

Treenode* deltree(Treenode* tree, int key) {
	Treenode* p, * p2;
	if (!tree) return tree;
	if (tree->number == key) {
		if (tree->left == NULL && tree->right == NULL) {
			delete tree;
			tree = NULL;
			return NULL;
		}
		else if (tree->left == NULL) {
			p = tree->right;
			/*
			p2 = tree->parent;
			if (p2->right == tree)
			{
				p2->right = p;
			}
			*/
			p->parent = tree->parent;
			p->x = tree->x;
			p->y = tree->y;
			p->lvl = tree->lvl;
			delete tree;
			return p;
		}
		else if (tree->right == NULL) {
			p = tree->left;
			/*
			p2 = tree->parent;
			if (p2->right == tree)
			{
				p2->right = p;
			}
			*/
			p->parent = tree->parent;
			p->x = tree->x;
			p->y = tree->y;
			p->lvl = tree->lvl;
			delete tree;
			return p;
		}
		else {
			p2 = tree->right;
			p = tree->right;
			while (p->left)
			{
				p = p->left;
			}
			tree->number = p->number;
			tree->lvl = p->lvl;
			if (p->parent->left != tree->left)
			{
				p->parent->left = NULL;
				deltree(p, p->number);
			}
			else
			{
				tree->right = deltree(tree->right, tree->right->number);
			}
			return tree;
		}
	}
	if (tree->number < key)tree->right = deltree(tree->right, key);
	else tree->left = deltree(tree->left, key);
	return tree;
}

Treenode* find_del(Treenode* tree, int x) {
    if (tree != NULL) {
        tree->left = find_del(tree->left, x);
        tree->right = find_del(tree->right, x);
        if (tree->number == x) {
            tree = deltree(tree, x);
        }
        return tree;
    }
}