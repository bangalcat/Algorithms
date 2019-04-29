#include <iostream>
using namespace std;

int N;

bool isContain4(int n)
{
    while(n)
    {
        if(n%10==4) return true;
        n/=10;
    }
    return false;
}
pair<int,int> smallSolve(int n)
{
    int n2 = n/2;
    for(int i=1;i<=n2;++i)
    {
        if (!isContain4(i) && !isContain4(N - i))
        {
            return {i, N - i};
        }
    }
    return {0, 0};
}

pair<int,int> biggerSolve(int n)
{
    string num = to_string(n);
    int nsize = num.size();
    int A=0, B=0;
    for(int i=0;i<nsize;++i)
    {
        int k = num[i] - '0';
        if(k==0)
        {
            A = A * 10;
            B = B * 10;
            continue;
        }
        for(int j=0;j<k;++j)
        {
            if(j!=4 && (k-j)!=4)
            {
                A = A * 10 + j;
                B = B * 10 + (k-j);
                break;
            }
        }
    }
    return {A, B};
}

int main()
{
    freopen("test.in", "r", stdin);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        cin >> N;
        pair<int, int> ans;
        ans = biggerSolve(N);

        cout << "Case #" << t << ": " << ans.first << ' ' << ans.second << '\n';
    }
    return 0; 
}