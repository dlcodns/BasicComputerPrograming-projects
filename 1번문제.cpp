#include<iostream>
#define SIZE 7

using namespace std;

void swap(int* a, int* b) 
{ 
	if (*a > *b) {
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

int main() 
{
	int count=0;
	int bubble[SIZE];

	for (int i = 0; i < SIZE; i++) {
		cin >> bubble[i];
	}

	while(count<12) {
		
		for (int i = 0; i < SIZE-1; i++) {
			swap(&bubble[i], &bubble[i + 1]);
			count++;
		}
	}

	for (int i = 0; i < SIZE - 1; i++) {
		cout << bubble[i] << " ";
	}
	cout << bubble[SIZE-1];
	return 0;
}