#include <cstdio>
// 타일 채우기 1
// 랭킹 답안
int p[35], n;
int main()
{
  p[0] = 1;
  for (int i = 2; i < 35; i += 2)
  {
    p[i] = p[i - 2];
    for (int j = 2; i >= j; j += 2)
      p[i] += 2 * p[i - j];
  }
  scanf("%d", &n);
  printf("%d", p[n]);
}