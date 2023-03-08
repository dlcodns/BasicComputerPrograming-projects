//정수 N을 입력으로 하여, N번째 Fibonacci number까지 출력하라.
//Recursion을 이용한 함수(Fibo1)와 반복문을 이용한 함수(Fibo2)를 모두 작성하고 두 함수를 비교하라.
//(효율, 프로그래밍의 편의성 등)

//Recursion을 이용한 코드

#include<stdio.h>

int Fibonacci(int num)
{
  if(num==0){
    return 0;
  }
  if(num==1){
    return 1;
  }
  else{
    return Fibonacci(num-1)+Fibonacci(num-2);
  }
}

int main(void)
{
  while(1){
    int N;
  
    printf("\n양의 정수 N을 입력하세요. >> ");
    scanf("%d",&N);

    if(N<=0){
      printf("\n양의 정수가 아닙니다.\n");
      continue;
    }
    else{
      for(int i=1;i<=N;i++){
      printf("%d ",Fibonacci(i));
      }
    }
  }
  return 0;
}
