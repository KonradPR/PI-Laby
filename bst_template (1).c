#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    struct node *left, *right, *parent;
    int value;
} node;


node* create_node(int val) {
  node* tmp = (node*)malloc (sizeof(node));
  tmp->value=val;
  tmp->left=NULL;
  tmp->right= NULL;
  tmp->parent=NULL;
  return tmp;
}

void delete_tree(node* root) {
  if(root->left!=NULL) delete_tree(root->left);
  if(root->right!=NULL) delete_tree(root->right);
  free(root);
}

void insert (node* root, node* to_insert) {

  
  node * tmp=root;
  node * prev =NULL;
  if(tmp==NULL){
    tmp=to_insert;
    return;
  }
  while(tmp!=NULL){
    prev=tmp;
    if(to_insert->value>=tmp->value){
      tmp=tmp->right;
    }
    else {
      tmp=tmp->left;
    }
   
  }
  to_insert->parent=prev;
  if(prev->value<to_insert->value){
    prev->right=to_insert;
  }else{
    prev->left=to_insert;
  }
  
}

void print_in_order(node* root) {
  if(root==NULL)return;
  print_in_order(root->right);
  printf("%d\n",root->value);
  print_in_order(root->left);
}

int main() {
    int n;
    scanf("%d", &n);
    node* root = NULL;
    int val;

    if (n-- > 0) {
        scanf("%d", &val);
        root = create_node(val);
    }
    while (n-- > 0) {
        scanf("%d", &val);
        insert(root, create_node(val));
    }

    print_in_order(root);

    delete_tree(root);
}
