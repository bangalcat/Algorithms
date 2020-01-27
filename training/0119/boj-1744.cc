#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n; cin >> n;
    long long sum = 0;
    vector<long long> posb, neg;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        if(a == 1) sum += 1;
        else if(a > 0) posb.push_back(a);
        else neg.push_back(a);
    }
    sort(posb.begin(), posb.end(), [](int lhs, int rhs){return lhs > rhs;});
    sort(neg.begin(), neg.end());
    if(posb.size()%2) posb.push_back(1);
    if(neg.size()%2) neg.push_back(1);

    for(int i=0; i < posb.size(); i+=2){
        sum += posb[i] * posb[i+1];
    }
    for(int i=0; i < neg.size() ; i+=2) {
        sum += neg[i] * neg[i+1];
    }
    cout << sum;
    return 0;
}