#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string line;
    cin >> line;
    int arr[50] = {0};
    int op[50] = {0};
    op[0] = 1;
    int ct = 0;
    int num = 0;
    int sum = 0;
    for(int i=0;i<line.size();) {
        if(i!=0){
            op[ct] = (line[i] == '+' ? 1 : -1);
            if(op[ct-1] == -1)
                op[ct] = -1;
            i++;
        }
        num = 0;
        while(i < line.size() && line[i] != '+' && line[i] != '-'){
            num *= 10;
            num += line[i] - '0';
            i++;
        }
        arr[ct++] = num;
    }
    for(int i=0;i<ct;++i){
        sum += (op[i] * arr[i]);
    }
    cout << sum;
    return 0;
}