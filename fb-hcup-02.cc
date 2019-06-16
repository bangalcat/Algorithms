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
        char ans = 'Y';
        if((len - 1 > 2 && beta == 1) || beta == len - 1 || beta == 0) ans = 'N';
        cout << "Case #" << tc+1 << ": " << ans << endl;
    }
    return 0;
}