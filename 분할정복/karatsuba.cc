/*
    카라츠바의 큰 수 곱셈 알고리즘
    곱셈 횟수 4번을 3번으로 줄여서 분할정복하는게 핵심
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void normalize(vector<int> &a){
    a.push_back(0);
    for(int i=0;i<a.size();i++){
        if(a[i] < 0){
            int borrow = (abs(a[i]+9))/10;
            a[i+1] -= borrow;
            a[i] += borrow*10;
        }else if(a[i] > 0){
            a[i+1] += a[i]/10;
            a[i] %= 10;
        }
    }
    if(a.back()==0) a.pop_back();
}
void addTo(vector<int>& a, const vector<int>& b,int k){
    a.resize(max<int>(a.size(),b.size()+k));
    for(int i=0,len=b.size();i<len;i++){
        a[i+k]+=b[i];       
    }
    //normalize
}
void subFrom(vector<int>& a, const vector<int>& b){
    a.resize(max(a.size(),b.size())+1);
    for(int i=0,len=b.size();i<len;i++)
        a[i] -= b[i];
    //normalize
}

vector<int> multiply(const vector<int>& a,const vector<int>& b){
    vector<int> c(a.size()+b.size()+1,0);
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
            c[i+j] += a[i] * b[j];
    //normalize;
    return c;
}

vector<int> karatsuba(const vector<int>& a,const vector<int>& b){
    int an = a.size(), bn = b.size();
    if(an < bn) return karatsuba(b, a);
    if(an==0 || bn==0) return vector<int>();
    if(an<5) return multiply(a,b);
    
    int half = an/2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(b.size(),half));
    vector<int> b1(b.begin()+min<int>(b.size(),half), b.end());
    
    //z2 = a1 * b1
    vector<int> z2 = karatsuba(a1,b1);
    //z0 = a0 * b0
    vector<int> z0 = karatsuba(a0,b0);
    
    addTo(a0,a1,0);
    addTo(b0,b1,0);
    //z1 = (a1+a0) * (b1+b0) - z0 - z2
    vector<int> z1 = karatsuba(a0,b0);
    subFrom(z1,z2);
    subFrom(z1,z0);
    vector<int> ret;
    addTo(ret,z0,0);
    addTo(ret,z1,half);
    addTo(ret,z2,half<<1);
    return ret;
}
int hugCount(string &idol, string &fan){
    int i_size = idol.size();
    int f_size = fan.size();
    vector<int> a(i_size);
    vector<int> b(f_size);
    for(int i=0;i<i_size;i++){
        a[i] = idol[i]=='M';
    }
    for(int i=0;i<f_size;i++){
        b[f_size-i-1] = fan[i]=='M';
    }
    vector<int> C = karatsuba(a,b);
    int ret=0;
    for(int i=i_size-1;i<f_size;i++){
        if(C[i]==0)
            ret++;
    }
    return ret;
}

int main()
{
    int t;
    cin >> t;
    while(t--) {
        string idol,fan;
        cin >> idol >> fan;
        
        cout << hugCount(idol,fan)<< endl;
    }
    
    return 0;
}
