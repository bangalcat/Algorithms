#include<iostream>
#include<cstdio>
#include<string>
#include<queue>

using namespace std;

struct RNG{
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next(){
        unsigned ret = seed;
        seed = ((seed*214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};
int countRanges(int k, int n){
    RNG rng;
    int rangeSum = rng.next();
    int tail=0,ret=0;
    queue<int> range;
    range.push(rangeSum);
    for(int i=0; i<n; i++){
        while(rangeSum < k && tail+1 < n ){
            int r = rng.next();
            rangeSum += r;
            range.push(r);
            tail++;
        }
        if(rangeSum == k) ret++;
        rangeSum -= range.front();
        range.pop();
    }
    return ret;
}

int main()
{
    int N; cin >> N;
    while(N--){
        int n,k;
        cin >> k >> n;
        cout << countRanges(k,n) << '\n';
    }
    return 0;
}
