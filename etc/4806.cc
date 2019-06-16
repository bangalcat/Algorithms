#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    string s;
    while (1)
    {
        char str[110];
        cin.getline(str,101);
        if(str[0] != 0) count++;
        else break;
    }
    cout << count;
    return 0;
}