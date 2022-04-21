#include <stdlib.h>
#include <stdio.h>

struct tree {
  char info;
  struct tree *left;
  struct tree *right;
};

struct tree *dtree(struct tree *root, char key);
struct tree *stree(struct tree *root,
						 struct tree *r, char info);

int main(void)
{

  struct tree *root=NULL;
  root = stree(root, root, 'd');
  root = stree(root, root, 'b');
  root = stree(root, root, 'a');
  root = stree(root, root, 'c');
  root = stree(root, root, 'f');
  root = stree(root, root, 'g');
  root = stree(root, root, 'e');
  root = dtree(root, 'b');
  root = dtree(root, 'd');
  root = dtree(root, 'a');
  root = dtree(root, 'c');
  root = dtree(root, 'e');
  root = dtree(root, 'f');
  root = dtree(root, 'g');
  return 0;
}

struct tree *stree(
  struct tree *root,
  struct tree *r,
  char info)
{

 if(!r)
	{
	 r = (struct tree *) malloc(sizeof(struct tree));
	 r->left = NULL;
	 r->right = NULL;
	 r->info = info;
	 if(!root) return r;
	 if(info < root->info) root->left = r;
	 else root->right = r;
	 return r;
  }

 if(info < r->info)
	 stree(r, r->left, info);
 else
	 stree(r, r->right, info);

 return root;
}
struct tree *dtree(struct tree *root, char key)
{
  struct tree *p,*p2;
  if(!root) return root;
  if(root->info == key) {
	 if(root->left == root->right){
		free(root);
		return NULL;
	 }
	 else if(root->left == NULL) {
		p = root->right;
		free(root);
		return p;
	 }
	 else if(root->right == NULL) {
		p = root->left;
		free(root);
		return p;
	 }
	 else {
		p2 = root->right;
		p = root->right;
		while(p->left) p = p->left;
		p->left = root->left;
		free(root);
		return p2;
	 }
  }
  if(root->info < key) root->right = dtree(root->right, key);
  else root->left = dtree(root->left, key);
  return root;
}
