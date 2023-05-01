#include <iostream>
#include <cstring>

using namespace std;

void rever(char* str, int i, int j) 
{
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() 
{
    char str[50];
    cin.getline(str, 50);
    int len = strlen(str);

    rever(str, 0, 6);
    rever(str, 4, 5);
    rever(str, 5, 12);
    rever(str, 2, 6);

    cout << str << endl;

    return 0;
}
