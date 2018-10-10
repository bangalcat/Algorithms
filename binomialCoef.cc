#include<cstdio>

int dp[1001];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		dp[i + 1] = 1;
		for(int j = i; j > 0; j--) dp[j] = (dp[j] + dp[j - 1]) % 10007;
	}
	
	printf("%d", dp[k]);
}