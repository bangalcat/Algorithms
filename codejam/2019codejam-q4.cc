#include <iostream>
#include <vector>

using namespace std;

int N, B, F;

vector<string> columns;

void setColumns()
{
    string s(1024,'0');
    for(int i=0;i<10;++i)
        columns.push_back(s);
    for(int i=0;i<10;++i)
    {
        for(int j=0;j<1024;++j)
        {
            if(j & (1<<i))
                columns[i][j] = '1';
        }
    }
}
vector<int> solve(vector<string>& in, int N)
{
    vector<int> ans;
    bool cols[1024] = {0};
    int n=0;
    for(int i=0;i<N;++i)
    {
        n = 0;
        for(int j=9;j>=0;--j)
        {
            n = (n<<1) + (in[j][i]=='1');
        }
        cols[n] = true;
    }
    for(int i=0;i<N;++i)
        if(!cols[i]) ans.push_back(i);
    return ans;
}

int main()
{
    int tc; cin >> tc;
    setColumns();
    for(int t=1;t<=tc;++t)
    {
        cin >> N >> B >> F;
        vector<string> in(10);
        for(int i=0;i<10;++i)
        {
            cout << columns[i].substr(0,N) << '\n';
            cin >> in[i];
        }
        auto ans = solve(in, N);
        for(auto i : ans)
        {
            cout << i << ' ';
        }
        cout << '\n';
        int ret; cin >> ret;
        if(ret == -1)
        {
            //WA
            break;
        }
    }
    return 0;
}