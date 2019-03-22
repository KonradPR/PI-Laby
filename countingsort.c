#include<stdio.h>
#include<stdlib.h>

void countingSort(int* tab, int n, int k) {
    int *counters = malloc(k*sizeof(int));
    int* result = malloc(n*sizeof(int*));
      for(int j=0;j<k;j++){
	counters[j]=0;
    }

    for(int i=0;i<n;i++){
      counters[tab[i]]++;
    }
    for(int m=1;m<k;m++){
      counters[m]+=counters[m-1];
    }
    for(int i=n-1;i>=0;i--){
      counters[tab[i]]--;
      result[counters[tab[i]]]=tab[i];
    }
    for(int j=0;j<n;j++){
      tab[j]=result[j];
    }
    
    
}

int main() {
    int Z;
    scanf("%d", &Z);

	while (Z--) {

		int n, k;
		scanf("%d", &n);
        scanf("%d", &k);
		int *tab = malloc(n*sizeof(int*));
		for(int i=0; i<n; i++) {
			scanf("%d", &tab[i]);
		}

        countingSort(tab, n, k);
        for(int i=0; i<n; i++) {
            printf("%d\n", tab[i]);
        }
        free(tab);
    }
}