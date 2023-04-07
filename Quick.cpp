#include <iostream>

using namespace std;
//pivot을 기준으로 왼쪽(pivot보다 작은값들) 오른쪽(pivot보다 큰 값들)을 나누는 것을 계속함

void swap(int *a, int *b){      //서로 값을 바꾸는 함수
 int temp = *a;
 *a = *b;
 *b = temp;
}

void split(int number[], int k, int m, int *i){    //퀵솔팅하는 과정 함수
  int v = number[k];
  int j=k+1; //j는 subarray number의 첫 번째 원소
  *i = m; //i는 subarray number의 m(number의 마지막 원소)
  while( j <= *i ){
    while(number[j] <= v && j<=*i)
      j++; //만약 pivot값 보다 작다면 j++
    while(number[*i] >= v && j<=*i)
      (*i)--; //만약 pivot값 보다 크다면 i--
    if (j< *i){
      swap(&number[j], &number[*i]); //j과 i번째 index 값을 서로 바꾼다.
    } 
    }  
  if(*i!=k) {
    number[k]=number[*i];
    number[*i]=v;
  } // == swap(number[k], number[i])

}

void quick(int number[], int k, int m){    //퀵을 진행하는 함수
  int i=m; //i is pivot
  
  if(k<m){
    split(number, k, m, &i);
         //pivot i를 기준으로 왼쪽값들
    quick(number, k, i-1);
         //pivot i를 기준으로 오른쪽값들
    quick(number, i+1, m);
  }
}

void fill(int number[], int num){    //빠진 수를 채우는 함수
  int newNum[10]={0,};
  for (int i=0;i<num;i++){
    newNum[i]=number[i];
  }
  for(int j=0;j<10;j++){
    if(newNum[j]!=j){        //number[0]이 0이 아니면 0으로 만들고 나머지 뒤로 밀기
      for(int i=num;i>j;i--){
        newNum[i] = newNum[i-1];
      }
      newNum[j] = j;         //빠져있던 수 채우기
      num++;            //수가 채워졌으니 배열의 수도 늘어나야 함
    }
  } 
  cout << "  Fill integer: ";  //채워진 수 출력
  for(int i=0;i<10;i++){
    cout << newNum[i] << " ";
  }
  cout << "\n\n";  
}

int main(void) {
 // 개수세기
  while(1){
    int num = 0;
    cout << "• 정렬할 1 ~ 9 사이의 서로 다른 정수들의 개수를 입력하세요. >> ";
    cin >> num;
    if(num<=0 || num>9){
      cout << "\n1 ~ 9 사이의 정수가 아닙니다. 다시 입력해주세요.\n\n" << endl;
      continue;
    }
    int* number = new int[num];    //동적할당
    
    cout << "• 0 ~ 9 사이의 " << num << "개의 서로 다른 정수를 입력하세요. >> ";
    for(int i=0;i<num;i++){
      cin >> number[i];
    }
    
    int check = 0;        //check 초기화
    for(int i=0;i<num;i++){    //배열의 범위가 맞지 않을 경우 다시 시작
      for(int j=0;j<i;j++){
        if((number[i]==number[j]) || (number[j]<0 || number[j]>9)){
          cout << "\n0 ~ 9 사이의 서로 다른 정수가 아닙니다. 다시 입력해주세요.\n\n" << endl;
          check+=1;
          j=num;    //j for문에서 나오기 위해 조건 불충분하게 만들기
          i=num;  //i for문에서 나오기 위해 조건 불충분하게 만들기
        }
      }
    }
    if(check!=0){
      continue;   //다시 시작
    }

    cout << "  First array: ";  //사용자가 입력한 배열 출력
    for(int i=0; i<num; i++){
      cout << number[i] << " ";
    }
    cout << endl;

    quick(number, 0, num-1);
    cout << "  Quick sorting: ";  //배열을 퀵솔팅한 배열 출력
    for(int i=0;i<num;i++){
      cout << number[i] << " ";
    }
    cout << endl;

    fill(number, num);           //빈자리를 찾아 채워주는 함수
  }
  return 0;
}
