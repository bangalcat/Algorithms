#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
int ary[20], ans, impossible;
void divide(int L,int W,int H)
{
    if (impossible) return;
    int m = 2, p = 0, num, lwh[3];
    lwh[0] = L, lwh[1] = W, lwh[2] = H;
    sort(lwh, lwh + 3);    
    while (pow(m,p+1)<=lwh[0])
    {
        p++;
    }
    while (ary[p]==0 && p>=0)
    {
        p--;
    }
    if (p < 0)
    {
        impossible = 1;
        return;
    }
    num = pow(m, p);
    m = min(lwh[2] / num, ary[p]);
    ary[p] -= m;
    ans += m;
    if(lwh[2]-m*num != 0) divide(num, num, lwh[2] - m*num);
    if (lwh[0] - num != 0) divide(lwh[0] - num, num, lwh[2]);
    if (lwh[1] - num != 0) divide(lwh[0], lwh[1] - num, lwh[2]);
}
 
int main()
{
    int L,W,H,N,a,b;
    scanf("%d %d %d %d", &L,&W,&H,&N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d%d", &a, &b);
        ary[a] = b;
    }
    divide(L, W, H);
    if (impossible) printf("-1\n");
    else printf("%d\n", ans);
 
    return 0;
}
// [출처] BOJ 그리디(Greedy)문제 |작성자 AintNoFun
