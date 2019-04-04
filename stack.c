#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;

/*****************************
* implements functions below *
*****************************/

void push(stack* s, int n) {
  if(s->top<s->max_size-1){
    s->elements[++s->top]=n;
  }
}

int pop(stack* s) {
  if(s->top!=-1){
    return s->elements[s->top--];
  }else{
    return 0;
  }
}

bool is_empty(stack* s) {
  if(s->top==-1)return true;
  return false;
    
}

stack* new_stack(int size) {
  stack* tmp = (stack*)malloc(sizeof(stack));
  tmp->elements=(int*)malloc(size*sizeof(int));
  tmp->top=-1;
  tmp->max_size=size;
  return tmp;
  
}

void delete_stack(stack* s) {
  free(s->elements);
  free(s);
    
}

int main() {
    int size;
    scanf("%d", &size);
    stack* s = new_stack(size);
    int tmp;

    /***************************************
    * read values and push them on stack   *
    * pop values from stack and print them *
    ***************************************/

    for(int i=0;i<size;i++){

      scanf("%d",&tmp);
      push(s,tmp);
      
    }

    for(int i=0;i<size;i++){

      
      tmp=pop(s);
      printf("%d ", tmp);
      
    }


    delete_stack(s);
}
