#include<stdio.h>
#include<stdlib.h>

int digit(char* number, int position) {
    return (int)(number[position] - '0');
}

void sortByPosition(char** tab, int n, int pos) {
    int k = 10;
    int *counters = malloc(k*sizeof(int));
    char** result = malloc(n*sizeof(char*));
   for(int j=0;j<k;j++){
	counters[j]=0;
    }

    for(int i=0;i<n;i++){
      counters[digit(tab[i],pos)]++;
    }
    for(int m=1;m<k;m++){
      counters[m]+=counters[m-1];
    }
    for(int i=n-1;i>=0;i--){
      counters[digit(tab[i],pos)]--;
      result[counters[digit(tab[i],pos)]]=tab[i];
    }
    for(int j=0;j<n;j++){
      tab[j]=result[j];
    }
}

void radixSort(char** tab, int n, int length) {
  for(int i=0;i<length;i++){
    sortByPosition(tab,n,i);
  }
}

int main() {
    int Z;
    scanf("%d", &Z);

	while (Z--) {

		int n, length;
		scanf("%d", &n);
        scanf("%d", &length);
		char **tab = malloc(n*sizeof(char*));
		for(int i=0; i<n; i++) {
			tab[i] = malloc((length+1)*sizeof(char));
            int read_len = scanf("%s", tab[i]);
		}

        radixSort(tab, n, length);
        for(int i=0; i<n; i++) {
            printf("%s\n", tab[i]);
            free(tab[i]);
        }
        free(tab);
    }
}
