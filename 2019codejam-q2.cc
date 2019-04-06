#include <iostream>
using namespace std;

int N;

int main()
{
    freopen("test2.in", "r", stdin);
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; ++t)
    {
        string P;
        cin >> N >> P;
        for(auto& c : P)
        {
            if(c=='E') c = 'S';
            else c = 'E';
        }
        cout << "Case #" << t << ": " << P << '\n';
    }
    return 0;
}