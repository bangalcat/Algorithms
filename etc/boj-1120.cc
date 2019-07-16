#include <iostream>

using namespace std;

int partdiff(const string& s1, const string& s2, int strtIdx) {
    int len = s1.size();
    int ret = 0;
    for(int i = 0; i < len; ++i) {
        if(s1[i] != s2[strtIdx + i]) ret++; 
    }
    return ret;
}

int solve(const string& s1, const string& s2) {
    int minPartDiff = 100;
    for(int si = 0; si < s2.size() - s1.size() + 1; ++si) {
        minPartDiff = min(minPartDiff, partdiff(s1,s2,si));
    }
    return minPartDiff;
}


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << solve(s1, s2);
    return 0;
}