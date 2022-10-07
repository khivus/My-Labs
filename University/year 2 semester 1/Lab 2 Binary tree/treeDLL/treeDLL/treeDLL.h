#pragma once
#ifndef	 _TREEDLLH
#define  _TREEDLLH
#ifdef  TREEDLL_EXPORTS
#define TREEDLL_API __declspec(dllexport) 
#else
#define TREEDLL_API __declspec(dllimport)
#endif
struct Treenode {
    int number;
    int lvl;
    int x;
    int y;
    Treenode* left;
    Treenode* right;
    Treenode* parent;
};
extern "C" TREEDLL_API Treenode* addnode(Treenode* tree, int key, int x, int y, Treenode* parent, int lvl);
extern "C" TREEDLL_API void destroy_tree(Treenode* tree);
extern "C" TREEDLL_API int summing(Treenode* root);
extern "C" TREEDLL_API int find_maxlvl(Treenode* tree, int x);
extern "C" TREEDLL_API Treenode* deltree(Treenode* tree, int key);
extern "C" TREEDLL_API Treenode* find_del(Treenode * tree, int x);

#endif
