
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int ct1=0, ct2=0;
    for(int i=0;i<n;++i){
        int a; cin >> a;
        if(a==1) ct1++;
        else ct2++;
    }
    vector<int> primes;
    auto eratones = [&](){
        bool p[500010]={0};
        for(int i=2;i*i<500001;++i){
            if(!p[i]) for(int j=i*i;j<500001;j+=i)
                p[j]=1;
        }
        for(int i=2;i<500001;++i)
            if(!p[i]) primes.push_back(i);
    };
    eratones();
    vector<int> ans;
    int curr=0;
    auto np = primes.begin();
    #define cout1 cout << "1 "
    #define cout2 cout << "2 "
    while(ct1>0 && ct2>0){
        if(curr < *np-1){
            cout2;
            curr += 2;
            ct2--;
            if(curr==*np) np++;
        }else if(curr == *np-1){
            cout1;
            curr++;
            np++;
            ct1--;
        }
    }
    while(ct1>0){
        cout1;
        ct1--;
    }
    while(ct2>0){
        cout2;
        ct2--;
    }
    return 0;
}