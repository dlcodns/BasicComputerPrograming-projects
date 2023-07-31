#include <stdio.h>
#include <stdlib.h>    //동적할당 하려고
//pivot을 기준으로 왼쪽(pivot보다 작은값들) 오른쪽(pivot보다 큰 값들)을 
나누는 것을 계속함

void swap(int *a, int *b){      //서로 값을 바꾸는 함수
 int temp = *a;
 *a = *b;
 *b = temp;
}

void split(int a[], int k, int m, int *i){    //퀵솔팅하는 과정 함수
 int v = a[k];
 int j=k+1; //j는 subarray a의 첫 번째 원소
 *i = m; //i는 subarray a의 m(a의 마지막 원소)
 while( j <= *i ){
         while(a[j] <= v && j<=*i)
             j++; //만약 pivot값 보다 작다면 j++
         while(a[*i] >= v && j<=*i)
             (*i)--; //만약 pivot값 보다 크다면 i--
         if (j< *i)
             swap(&a[j], &a[*i]); //j과 i번째 index 값을 서로 바꾼다.
         else
             break;
 }
 if(*i!=k) {
     a[k]=a[*i];
     a[*i]=v;
 } // == swap(a[k], a[i])
}

//a : Array
//k : lowest index of subArray
//m : highest index of subArray
void quick(int a[], int k, int m){    //
     int i=m; //i is pivot
     if(k<m){
         split(a, k, m, &i);
         //pivot i를 기준으로 왼쪽값들
         quick(a, k, i-1);
         //pivot i를 기준으로 오른쪽값들
         quick(a, i+1, m);
     }
}

int main(void) {
 int x = 0, y = 0;
 int *a;

 int dummy;
 int index = 0;

 // 개수세기
 FILE* fp = fopen("data.txt", "r");
 while(fscanf(fp, "%d", &dummy) != -1)
 {
     x++;
 }

 // 파일 다시 읽기
 fp = fopen("data.txt", "r");
 a = (int*)malloc(sizeof(int)*x);

 while(fscanf(fp, "%d", &a[index++]) != -1); // << while이 한 줄일 때는 
끝에 ; 붙여줘야댐!

for(int i=0; i<x; i++)
    printf("%d ", a[i]);
printf("\n");

 quick(a, 0, x-1);
 for(int i=0;i<x;i++){
     printf("%d ", a[i]);
 }
 printf("\n");
 return 0;
}
