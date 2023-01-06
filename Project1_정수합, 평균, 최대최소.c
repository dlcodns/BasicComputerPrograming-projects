//문제: 임의 개수의 정수를 입력으로 하여, 입력 정수들의 합과 평균을 구하고, 최대수와 최소수를 찾아 출력하는 프로그램을 작성하라.
#include<stdio.h>
#include<stdlib.h>

int main(void){
    int *arr;
    int n;
    int add=0;
    float average;
    int MAX=-999999;
    int MIN=999999;

    printf("입력할 정수의 개수를 적으세요. >> ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));

    printf("정수를 입력하세요.\n");
    for(int i=0;i<n;i++){
        printf("%d번째 정수 >> ",i+1);
        scanf("%d",&arr[i]);
        add+=arr[i];
        if(arr[i]>MAX){
            MAX=arr[i];
        }
        if(arr[i]<MIN){
            MIN=arr[i];
        }
    }

    average=(float)add/n;

    printf("\n\n1. 합: %d\n2. 평균: %.1f\n3. 최대수: %d\n4. 최소수: %d\n",add,average,MAX,MIN);

    return 0;
}
