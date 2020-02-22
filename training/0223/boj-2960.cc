#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int count = 0;
    int era[1010] = {0};
    for(int i=2; i<=n;++i) {
        if(era[i] == 0)
            for(int j=i; j<=n;j+=i){
                if(not era[j]) count += 1;
                if(count == k){
                    cout << j;
                    return 0;
                }
                era[j] = 1;
            }
    }
    return 0;
}