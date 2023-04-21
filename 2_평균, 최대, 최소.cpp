#include <iostream>

using namespace std;

int main()
{
	while (1) {			//무한 반복문을 사용한다.
		float array[5] = {};		//5개의 정수를 저장하려 한다.
		float avg = 0, sum = 0;
		float Min = 999999;
		float Max = -999999;

		for (int i = 0; i < 5; i++) {		//for문을 돌려 배열의 수를 채운다.
			cout << i + 1 << "번째 실수를 입력하세요. >> ";
			cin >> array[i];
			sum += array[i];		//합을 구한다.
			if (array[i] >= Max) {	//MAX와 Min을 구하기 위해 조건문을 단다.
				Max = array[i];
			}
			if (array[i] <= Min) {
				Min = array[i];
			}
		}
		avg = (float)round((sum / 5) * 10);	//round는 정수로 반올림하는 함수인데, 소수 첫째자리까지 구하기 위해 먼저 10을 곱한 후 
										//출력할 때 10으로 나누려고 했다.
		cout << "\n∴ 입력 받은 수 : ";
		for (int i = 0; i < 5; i++) {	//for문을 돌리며 배열의 수를 출력한다.
			if (i == 4) {
				cout << array[i] << endl;	//마지막 숫자 뒤에 쉼표가 없게 하기 위해 조건문으로 array[4]만 따로 출력하게 했다.
			}
			else
				cout << array[i] << ", ";
		}
		cout << "∴ Mean : " << (float)avg / 10 << ", Sum : " << sum << ", Min : " << Min << ", Max : " << Max << endl << endl;
	}
}
