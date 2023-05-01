#include <iostream>
#include <cstring>

using namespace std;

void calc(char*arr, int k, int p, int len) 
{
    while (1) {
        if (arr[k] == '+') {
            arr[k - 1] = arr[k - 1] + arr[k + 1];
            for (int j = k; j < len; j++) {
                arr[j] = arr[j + 2];
            }
            len = len - 2;

            if (arr[p] == '+') {
                arr[p - 1] = arr[p - 1] + arr[p + 1];
                for (int j = p; j < len; j++) {
                    arr[j] = arr[j + 2];
                }
                len = len - 2;
                break;
            }
            if (arr[p] == '-') {
                arr[p - 1] = arr[p - 1] - arr[p + 1];
                for (int j = p; j < len; j++) {
                    arr[j] = arr[j + 2];
                }
                len = len - 2;
                break;
            }
        }
        if (arr[k] == '-') {
            arr[k - 1] = arr[k - 1] - arr[k + 1];
            for (int j = k; j < len; j++) {
                arr[j] = arr[j + 2];
            }
            len = len - 2;
            if (arr[p] == '+') {
                arr[p - 1] = arr[p - 1] + arr[p + 1];
                for (int j = p; j < len; j++) {
                    arr[j] = arr[j + 2];
                }
                len = len - 2;
                break;
            }
            if (arr[p] == '-') {
                arr[p - 1] = arr[p - 1] - arr[p + 1];
                for (int j = p; j < len; j++) {
                    arr[j] = arr[j + 2];
                }
                len = len - 2;
                break;
            }
        }
    }
    
    if (arr[1] == '+') {
        arr[0] = arr[0] + arr[2];
    }
    if (arr[1] == '-') {
        arr[0] = arr[0] - arr[2];
    }
}

int main() 
{
    int min = 99;
    char arr[50];
    cin.getline(arr, 50);
    int len = strlen(arr);
    
    for (int i = 1; i < (len / 2)+1; i++) {
        for (int j = 1; j < (len / 2); j++) {
            calc(arr, i, j, len);
            if (arr[0] < min) {
                min = arr[0];
            }
        }  
    }
    cout << min;
}
