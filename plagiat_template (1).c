#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAX_TEXT_LENGTH = 200;


int minimum(int x1, int x2, int x3)
{
    if (x1 >= x2)
        if (x2 >= x3)
            return x3;
        else
            return x2;
    else
        if (x3 >= x1)
            return x1;
 
    return x3;
}
 
 
int MAX_TEXT_LENGTH = 200;
 
int distance(char* a, int a_length, char* b, int b_length) {
    /*********************
    * put your code here *
    *********************/
    int** check=(int**)malloc(sizeof(int*)*MAX_TEXT_LENGTH+1);
    for(int i=0;i<MAX_TEXT_LENGTH+1;i++)
        check[i]=(int*)malloc(sizeof(int)*MAX_TEXT_LENGTH+1);\
    int m=a_length;
    int n=b_length;
    for(int i=0;i<=m;i++)   check[i][0]=i;
    for(int i=0;i<=n;i++)   check[0][i]=i;
    int cost;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
           
            if(a[i-1]==b[j-1])
                cost=0;
            else
                cost=1;
            check[i][j]=minimum(check[i-1][j]+1,check[i][j-1]+1,check[i-1][j-1]+cost);
        }
    }
    return check[a_length][b_length];
}
 

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
