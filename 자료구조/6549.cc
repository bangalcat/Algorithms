/*
    문제 이름 : 히스토그램에서 가장 큰 직사각형
    최상의 해법 : 스위핑
*/

#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<stack>
typedef long long ll;
using namespace std;

// if h[i] < h[i+1]
// h[i]'s right is i+1
// else if h[i] >= h[i+1]
// h[i+1]'s left is remains.top() until h[remains.top()] < h[i]
// so h[i+1] is highest until i+1 in remains
int main()
{
    string line;
    while(getline(cin,line)){
        if(line=="0") break;
        stringstream ss;
        ss.str(line);
        ll num;
        ss >> num;
        vector<ll> hist;
        stack<ll> remains;
        while(ss >> num)
            hist.push_back(num);
        hist.push_back(0);
        ll maxt=0;
        for(int i=0;i<hist.size();i++)
        {
            while(!remains.empty() && (hist[remains.top()] >= hist[i])){
                int j = remains.top();
                remains.pop();
                int width = -1;
                if(remains.empty())
                    width = i;
                else
                    width = i - remains.top() - 1;
                maxt = max(width * hist[j], maxt);
            }
            remains.push(i);
        }
        cout << maxt;
        cout << endl;
    }

    return 0;
}