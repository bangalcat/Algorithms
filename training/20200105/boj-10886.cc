#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int t = n;
    int s = 0;
    while(t--){
        int a;
        cin >> a;
        s += a;
    }
    if(s > n/2)
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";
    
    return 0;
}