//정수 N을 입력으로 하여, 2부터 N까지의 모든 소수(prime numbers)를 찾아 출력하는 프로그램을 작성하라.
//0을 입력하면 실행 종료

#include<stdio.h>

int main(void)
{
  while(1){
    int N;
    int count = 0;
    
    printf("\n\n정수를 입력하세요. >> ");
    scanf("%d",&N);
    
    if(N==0){
      break;
    }
    if(N<0){
      continue;
    }
    else{
      for(int i=2;i<=N;i++){
        for(int j=1;j<i;j++){
          if(i%j==0){
            count++;
          }
        }
        if(count==1){
          printf("%d ",i);
        }
        count=0;
      }
    }
  }
  return 0;
}
