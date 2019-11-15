#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int L=0, R=0;
    vector<int> z(n,0);
    for (int i=0; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while(R < n && s[R-L] == s[R])
                R++;
            z[i] = R - L;
            R--;
        }else {
            int k = i - L;
            if (z[k] < R - i + 1)
                z[i] = z[k];
            else {
                L = i;
                while(R < n && s[R-L] == s[R])
                    R++;
                z[i] = R - L; 
                R--;
            }
        }
    }
    int ret=0, maxz = 0;
    for(int i=0; i < n; ++i) {
        if (z[i] == n - i && maxz >= n - i){
            ret = i;
            break;
        }
        maxz = max(maxz, z[i]);
    }
    if(ret > 0)
        cout << s.substr(ret);
    else
        cout << "Just a legend";
    
    return 0;
}