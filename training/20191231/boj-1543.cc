#include <iostream>
#include <vector>

using namespace std;

vector<int> get_pi(const string& s) {
    int m = s.size();
    int j = 0;
    vector<int> pi(m, 0);
    for(int i=1; i < m; ++i){
        while(j > 0 && s[i] != s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            pi[i] = ++j;
    }
    return pi;
}

int kmp(const string &doc, const string& w)
{
    int ret = 0;
    vector<int> pi = get_pi(w);
    int n = doc.size(), m = w.size(), matched=0;
    for(int i=0;i<n;++i) {
        while(matched > 0 && doc[i] != w[matched])
            matched = pi[matched-1];
        if(doc[i] == w[matched]){
            if(matched == m-1){
                ret++;
                matched = 0;
            }else {
                matched++;
            }
        }
    }
    return ret;
}
int main()
{
    string document, word;
    getline(cin, document);
    getline(cin, word);
    cout << kmp(document, word);
    return 0;
}