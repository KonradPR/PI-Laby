#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct stack {
    int* elements;
    int top;
    int max_size;
} stack;

/***************************************
* paste here your stack implementation *
***************************************/
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

typedef enum entry_type {number, add, subtract, multiply, divide} entry_type;

entry_type parse(char* raw) {
    if (raw[0] == '+') return add;
    if (raw[0] == '-') return subtract;
    if (raw[0] == '*') return multiply;
    if (raw[0] == '/') return divide;
    return number;
}

/****************************
* implement functions below *
****************************/

void do_add(stack* s) {
int tmp = pop(s)+pop(s);
push(s,tmp);    
}

void do_subtract(stack* s) {
int a = pop(s);
int b = pop(s);
int tmp=b-a;
push(s,tmp);
}

void do_multiply(stack* s) {
int tmp = pop(s)*pop(s);
push(s,tmp);
}

void do_divide(stack* s) {
int a=pop(s);
int b=pop(s);
int tmp=b/a;
push(s,tmp);
}

int read_and_calculate(int operands_count, int max_entry_size) {
    stack* operands = new_stack(operands_count);
    char* entry = malloc((max_entry_size+1)*sizeof(char));
while(operands_count!=1) {

        for(int i=0; i<max_entry_size; i++) entry[i] = '\0';
        scanf("%s", entry);

//printf("%s\n",entry);
        char* end;
        int i;
//printf("%d",parse(entry));
	switch(parse(entry)){
	case 0:
	   i=strtol(entry, &end,10);
	   push(operands,i);
           
	  break;
       	case 1:
	  do_add(operands);
operands_count--;
	  break;
	case 2:
	  do_subtract(operands);
operands_count--;
	  break;
	case 3:
	  do_multiply(operands);
operands_count--;
	  break;
	case 4:
	  do_divide(operands);
operands_count--;
	  break;

	  
	};
	
	
    
        
    }

//printf("out");
int result = pop(operands);

    delete_stack(operands);
    free(entry);
    return result;
}

int main() {
    int operands_count, max_entry_size;
    scanf("%d", &operands_count);
    scanf("%d", &max_entry_size);
    printf("%d\n", read_and_calculate(operands_count, max_entry_size));
}
