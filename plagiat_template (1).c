#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_TEXT_LENGTH = 200;




int distance(char* a, int a_length, char* b, int b_length) {

  if(a_length==0)return b_length;
  if(b_length==0)return a_length;
  
  if(a[a_length-1]==b[b_length-1]){
    return distance(a,a_length-1,b,b_length-1);
  }else{
    int a=distance(a,a_length-1,b,b_length);
    int b=distance(a,a_length,b,b_length-1);
    int c = distance(a,a_length-1,b,b_length-1);
  }
  
}

int main() {
    char* a = malloc(MAX_TEXT_LENGTH*sizeof(char));
    char* b = malloc(MAX_TEXT_LENGTH*sizeof(char));
    scanf("%[^\n]", a);
    scanf("%c\n", b); // reads \n
    scanf("%[^\n]", b);
    printf("%d\n", distance(a, strlen(a), b, strlen(b)));
}
