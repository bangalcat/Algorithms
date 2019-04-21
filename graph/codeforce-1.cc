#include <iostream>

using namespace std;

int main()
{
    // a+b, b+c, c+a, a+b+c
    int num[4];
    cin >> num[0] >> num[1] >> num[2] >> num[3];
    int maxi=-1;
    for(int i=0;i<4;++i)
        if(maxi==-1 || num[maxi] < num[i])
            maxi = i;
    for(int i=0;i<3;++i){
        for(int j=i+1;j<4;++j){
            if (i != maxi && j != maxi && i != j)
                cout << num[i] + num[j] - num[maxi] << ' ';
        }
    }

    return 0;
}