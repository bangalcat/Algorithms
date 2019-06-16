#include <iostream>
#include <algorithm>

using namespace std;

string vow = "aeiou";

void pick(char *set, string& ans, int c, int l, int idx, int trgIdx, int vc, int cc){
    if(idx == l && vc >= 1 && cc >= 2){
        cout << ans << endl;
        return;
    }
    if(trgIdx == c)
        return;
    ans[idx] = set[trgIdx];
    int nvc = vc, ncc = cc;
    if(vow.find(set[trgIdx])!=string::npos) 
        nvc++;
    else 
        ncc++;
    pick(set, ans, c, l, idx+1, trgIdx+1, nvc, ncc);
    pick(set, ans, c, l, idx, trgIdx+1, vc, cc);
}

int main()
{
    int l, c;
    cin >> l >> c;
    char set[16];
    string ans(l, ' ');
    for(int i=0;i<c;++i)
        cin >> set[i];
    sort(set, set+c);
    pick(set, ans, c, l, 0, 0, 0, 0);
    return 0;
}
