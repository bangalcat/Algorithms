#include <iostream>

using namespace std;

int main() 
{
    int k; cin >> k;
    for(int i=0;i<k;++i)
        cout << 1;
    for(int i=0;i<k-1;++i)
        cout << 0;
    return 0;
}