/*
    백준 : 반복수열
*/
#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int MAX = 25e4;

int main()
{
    vector<int> idx(MAX,-1);
    int A, p;
    cin >> A >> p;
    function<int(int,int)> pow = [&](int n, int x){
        return x==0 ? 1 : pow(n,x-1) * n;
    };
    auto nextD = [&,p](int n){
        int ret=0;
        while(n){
            int a = n%10;
            ret += pow(a, p);
            n/=10;
        }
        return ret;
    };
    int cnt=0;
    while(idx[A] == -1){
        idx[A] = cnt++;
        A = nextD(A);
    }
    cout << idx[A];
    return 0;
