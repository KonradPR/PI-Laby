#include <stdio.h>
#include <stdlib.h>

int change(int amount, int* coins, int coins_count, int* result) {
    /******************************************************************
    * put coins to give in `result` table and return a number of them *
    ******************************************************************/
  if(amount<=0)return 0;
  for(int i=coins_count-1;i>=0;i--){
    if(amount>=coins[i]){
      result[0]=coins[i];
      return change(amount-coins[i],coins,coins_count,result+1)+1;
    }
  }

  /* int k=0;
     while(amount>0){
     
      for(int i=coins_count-1;i>=0;i--){
    if(amount>=coins[i]){
      result[0]=coins[i];
      amount=-=coins[i]
      result++;
      k++;
      break;
}
}
}

return k;

*/

  
  
  /* if(amount==0)return 0;
  if(amount<0)return 1000;

  int res = change(amount-coins[0],coins,coins_count,result+1);
  

  int tmp_res;
  if(res>1){
  for(int i=1;i<coins_count;i++){
    if(amount>=coins[i]){
      tmp_res=change(amount-coins[i],coins,coins_count,result+1);
      if(tmp_res<res){
	res=tmp_res;
	printf("in");
      }
  }}
  }
  
  return res+1;*/
  
}

int main() {
    int RESULT_LIMIT = 20;
    int *results = malloc(RESULT_LIMIT*sizeof(int));
    int N, C;
    scanf("%d", &N); // number of test cases
    scanf("%d", &C); // number of coins
    int* coins = malloc(C*sizeof(int));
    for(int i=0; i<C; i++) scanf("%d", &coins[i]);

    int change_to_give, results_count;
    for(int i=0; i<N; i++) {
        scanf("%d", &change_to_give);
        results_count = change(change_to_give, coins, C, results);
        for(int i=0; i<results_count; i++) printf("%d ", results[i]);
        printf("\n");
    }

    free(results);
    free(coins);
}
