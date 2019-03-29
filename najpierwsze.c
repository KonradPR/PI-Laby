#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


bool isIdeal(long num){
  bool test=true;
  while(num!=0){
    int tmp =num%10;
    num/=10;
    if(num!=0){
      if(tmp<num%10){
	test = false;
      }
    }
    
  }
  return test;
}

int main() {


  long n;

  scanf("%ld",&n);
  for(long i=2;i<=n;i++){
    long k;
    bool prime =true;
    if(i%2==0&&i>2)prime=false;
    for(k=3;k*k<=i;k+=2){
      if(i%k==0){prime=false;}
    }

    if(prime){
      if(isIdeal(i)){
	printf("%ld\n", i);
      }
    }
    
  }
  

  return 0;
}
