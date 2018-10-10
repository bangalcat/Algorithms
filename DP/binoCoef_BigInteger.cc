#include<cstdio>

const long long LONG_LIMIT = 1e14;

struct BigInteger{
    long long high=0;
    long long low=0;
    void print(){
        if(high > 0)
            printf("%lld%014lld",high,low);
        else
            printf("%lld",low);
    }
    
    BigInteger operator+(BigInteger n){
        low = low + n.low;
        high = high + n.high + low/LONG_LIMIT;
        low %= LONG_LIMIT;
        return *this;
    }
    
    BigInteger operator=(BigInteger n){
        high = n.high;
        low = n.low;
    }
};
BigInteger dp[501];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	dp[0].low = 1;
	for(int i = 0; i < n; i++){
		dp[i + 1].low = 1;
		for(int j = i; j > 0; j--) dp[j] = (dp[j] + dp[j - 1]);
	}
	
	dp[k].print();
} 