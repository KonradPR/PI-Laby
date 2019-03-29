#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_triangular(int** tab, int n) {

  bool flag = true;
  for(int i=0;i<n;i++){
    for(int j=n-1;j>=n-i;j--){
      if(tab[i][j]!=0){
	flag=false;
      }
    }
  }
  
  return flag;
}

int main() {
    int n;
    scanf("%d", &n);
    int** tab;

    tab = (int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
      tab[i]=(int*)malloc(n*sizeof(int));
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	scanf("%d",&(tab[i][j]));
      }
    }


    printf(is_triangular(tab, n) ? "YES\n" : "NO\n");
    
    for(int i =0; i<n;i++){
      free(tab[i]);
    }
    free(tab);
}
