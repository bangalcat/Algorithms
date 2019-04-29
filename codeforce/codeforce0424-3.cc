#include <iostream>
#include <vector>

#define ll long long

using namespace std;

int gcd(int r, int k)
{
    return r % k == 0 ? k : gcd(k, r % k);
}

int main()
{
    return 0;
}