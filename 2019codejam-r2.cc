
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

void print(vector<int>& output)
{
    for(int i=0;i<18;++i)
        cout << output[i] << ' ';
    cout << '\n';
}

int read(vector<int>& input)
{
    int ret=0;
    for(int i=0;i<18;++i){
        cin >> input[i];
        ret += input[i];
    }
    return ret;
}

int main()
{
    int tc, n, m;
    cin >> tc >> n >> m;
    for(int t=1;t<=tc;++t)
    {
        int ans=0;
        vector<int> output(18,0);
        vector<int> input(18); 
        int ret =0;
        for(int i=0;i<18;++i)
            output[i] = 18;
        for(int i=0;i<n;++i)
        {
            print(output);
            ret = max(ret,read(input));
        }
        cout << ret;
        cin >> ans;
        if(ans == -1) break;
    }
    return 0;
}