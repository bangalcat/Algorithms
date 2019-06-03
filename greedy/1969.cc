
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> dnas(n);
    for(int i=0;i<n;++i){
        cin >> dnas[i];
    }
    int ans=0;
    string ans_str;
    for(int i=0;i<m;++i){
        int d[4] = {0};
        for(int j=0;j<n;++j){
            if(dnas[j][i]=='A') d[0]++;
            else if(dnas[j][i]=='C') d[1]++;
            else if(dnas[j][i]=='G') d[2]++;
            else if(dnas[j][i]=='T') d[3]++;
        }
        for(int t=0;t<4;++t){
            if(ans_str.size() <= i && d[t] == max({d[0],d[1],d[2],d[3]}))
                ans_str.push_back(t+1);
            else 
                ans += d[t];
        }
    }
    for(int i=0;i<m;++i)
        if(ans_str[i] == 1)
            ans_str[i] = 'A';
        else if(ans_str[i] == 2)
            ans_str[i] = 'C';
        else if(ans_str[i] == 3)
            ans_str[i] = 'G';
        else if(ans_str[i] == 4)
            ans_str[i] = 'T';
    cout << ans_str << endl;
    cout << ans;
    return 0;
}