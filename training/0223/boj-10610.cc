#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string num;
    cin >> num;
    int sum = 0;
    int pos = -1;
    for(int i=0;i<num.size(); ++i){
        sum += num[i] - '0';
    }
    sort(num.begin(), num.end(), [](char &a, char &b){return a > b;});
    if(num.back() == '0' and sum % 3 == 0){
        cout << num;
    } else
        cout << -1;
    return 0;
}