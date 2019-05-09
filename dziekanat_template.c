#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char MAX_NAME_SIZE = 30;

typedef struct node {
    struct node *left, *right, *parent;
    int number;
    char* name;
} node;

node* create_node(int number, char* name) {
  node* tmp = (node*)malloc(sizeof(node));
  tmp->left=tmp->right=tmp->parent=NULL;
  tmp->number=number;
 tmp-> name = malloc(sizeof(char)*(strlen(name)+1));
  strcpy(tmp->name,name);
  return tmp;
  
}

void delete_tree(node* root) {
  if(root->left!=NULL) delete_tree(root->left);
  if(root->right!=NULL) delete_tree(root->right);
  free(root);
}

node* insert (node* root, node* to_insert) {
  if(root==NULL){root=to_insert;}
  else if(root->number<=to_insert->number){root->right=insert(root->right,to_insert);
  }
  else {root->left=insert(root->left,to_insert);}
   return root;
}

node* find (node* root, int number) {
  if(root==NULL)return NULL;
  while(root!=NULL){
    if(root->number<number){
      root=root->right;
    }else if(root->number>number){
      root=root->left;
    }else{
      return root;
    }
  }
  return NULL;
}

node* delete(node* root, int number) {
  if(root==NULL)
    return NULL;
  if(root->number>number){
    root->left=delete(root->left,number);
  }

  else if(root->number<number){
    root->right=delete(root->right,number);
  }

  else {
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        }

	struct node* temp;
	node* current = root->right;
	while (current && current->left != NULL) 
        current = current->left;
	temp = current;
	root->number = temp->number;
	root->right = delete(root->right, temp->number);
  }
  
  /* if(root==NULL)return NULL;
  node* tmp=find(root,number);
  node* left;
  node* holder;

 
  if(tmp!=NULL){
     
    if(tmp->left==NULL&&tmp->right==NULL){
      if(tmp->parent->left==tmp)tmp->parent->left=NULL;
       if(tmp->parent->right==tmp)tmp->parent->right=NULL;
       free(tmp);
    }else if(tmp->right!=NULL&&tmp->left!=NULL){
      left=tmp->left;
      while(left->left!=NULL){
	left=left->left;
      }
      left->parent->left=NULL;
     
      left->left=tmp->left;
      left->right=tmp->right;
       if(tmp->parent->left==tmp)tmp->parent->left=left;
       if(tmp->parent->right==tmp)tmp->parent->right=left;
      free(tmp);
      
    }else{
      if(tmp->left!=NULL){
	if(tmp->parent->left==tmp)tmp->parent->left=tmp->left;
	if(tmp->parent->right==tmp)tmp->parent->right=tmp->left;
      }else{
	if(tmp->parent->left==tmp)tmp->parent->left=tmp->right;
      	if(tmp->parent->right==tmp)tmp->parent->right=tmp->right;
      }
    }

    }*/
   return root;
}

int main() {
    int n, r, f;
    scanf("%d", &n);
    scanf("%d", &r);
    scanf("%d", &f);

    node* root = NULL;
    int number;
    char* name = malloc(MAX_NAME_SIZE*sizeof(char));

    while (n-- > 0) {
        scanf("%d", &number);
        scanf("%s", name);
        root = insert(root, create_node(number, name));
    }

    while (r-- > 0) {
        scanf("%d", &number);
        root = delete(root, number);
    }

    while (f-- > 0) {
        scanf("%d", &number);
        node* x = find(root, number);
        printf("%s\n", x == NULL ? "NOTFOUND" : x->name);
    }

    delete_tree(root);
    free(name);
}
