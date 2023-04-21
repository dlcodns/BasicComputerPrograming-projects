#include <iostream>

using namespace std;

typedef struct {
	char studentName[20];
	int studentAge;
	int studentID;
	char studentAddress[100];
} student;

void Add(student(&st)[5]);		//학생 나이를 +1하는 함수

int main() {
	student cbnuS[5] = { {"김일번", 20, 1, "청주시"},		//배열을 만듦
						{"김이번", 20, 2, "청주시"},
						{"김삼번", 21, 3, "대전광역시"},
						{"김사번", 22, 4, "부산광역시" },
						{"김오번", 23, 5, "울산광역시" } };

	cout << "2022년" << endl;

	for (int i = 0; i < 5; i++) {
		cout << cbnuS[i].studentName << " 학생은 " <<
			cbnuS[i].studentAge << " 살이고, 학번은 " <<
			cbnuS[i].studentID << " 이며, " <<
			cbnuS[i].studentAddress << "에 산다." << endl;
	}

	Add(cbnuS);		//+1함수 호출

	cout << "\n2023년" << endl;

	for (int i = 0; i < 5; i++) {			//바뀐 나이 출력
		cout << cbnuS[i].studentName << " 학생은 " <<
			cbnuS[i].studentAge << " 살이고, 학번은 " <<
			cbnuS[i].studentID << " 이며, " <<
			cbnuS[i].studentAddress << "에 산다." << endl;
	}
}

void Add(student(&st)[5]) {			//+1하는 함수
	for (int i = 0; i < 5; i++) {
		st[i].studentAge += 1;
	}
}
