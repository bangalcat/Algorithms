#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<string> files(n);
    for(int i=0;i<n;++i) {
        cin >> files[i];
    }
    int fl = files[0].size();
    string ans;
    for(int i=0;i<fl;++i) {
        char c = files[0][i];
        for(int j=1;j<n;++j) {
            if(c != files[j][i]){
                c = '?';
                break;
            }
        }
        ans.push_back(c);
    }
    cout << ans;
    return 0;
}