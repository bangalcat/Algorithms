#include <iostream>

using namespace std;

int main()
{
    int T; cin >> T;
    for(int tc=0;tc<T;++tc) {
        string frogs;
        cin >> frogs;
        int beta=0;
        int len = frogs.size();
        for(auto o : frogs)
            if(o == 'B') beta++;
        char ans = 'N';
        if(beta != len-1 && len-1 <= beta * 2) ans = 'Y';
        cout << "Case #" << tc+1 << ": " << ans << endl;
    }
    return 0;
}