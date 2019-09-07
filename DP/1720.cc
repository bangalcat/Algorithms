/**
 *  백준 : 타일 코드
 *  타일링 문제(boj-11727)에서 좌우 뒤집었을 경우 중복 제거
 */
#include <iostream>

using namespace std;

long long dp[31] = {0};
long long f(long long x){
    if(x <= 1) return 1;
    long long &ret = dp[x];
    if(ret != 0) return ret;
    ret = 2 * f(x - 2) + f(x - 1);
    return ret;
}

int main()
{
    int n; cin >> n;
    // 기본적으로 f(n) = 좌우대칭 + 좌우뒤집으면대칭 * 2
    // 즉 (f(n) + 좌우뒤집으면대칭) / 2 = 좌우대칭 + 좌우뒤집으면대칭
    
    if(n % 2) // 홀수 일때, 가운데 세로 블록 하나 && 좌우 대칭
        cout << (f(n) + f(n/2)) / 2;
    else // 짝수일때, 가운데 정사각형, 2*1 두개 + 정가운데 좌우대칭
    {
        cout << (f(n) + f(n/2) + 2 * f(n/2 - 1)) / 2;
    }
    
    return 0;
}