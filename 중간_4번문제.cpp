#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    int Max = -9999999;
    int num = 0;

    cin >> num;
    if (num < 1 || num > 500000) {
        return 0;
    }
    int* number = new int[num];
    
    for (int i = 0; i < num; i++) {
        cin >> number[i];
        if (number[i] >= Max) {
            Max = number[i];
        }
    }
    cout << Max;
    delete[] number;

    return 0;
}
