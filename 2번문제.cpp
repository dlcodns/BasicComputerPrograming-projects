#include<iostream>
#include<string>

using namespace std;

void rever(string& stu,int i, int j) {    
	int c, i, j;

	for (i < j; i++, j--;) {
		c = stu[i];
		stu[i] = stu[j];
		stu[j] = c;
	}
}

int main() 
{
    string stu;
    getline(cin, stu);

	rever(stu,0,6);
	rever(stu, 4, 5);
	rever(stu, 5, 12);
	rever(stu, 2, 6);

	cout << stu << endl;

	return 0;
}
