#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> scores(n, vector<int>(3, 0));
    for (int i = 0; i < n; ++i) {
        int idx, gold, silver, bronze;
        cin >> idx >> gold >> silver >> bronze;
        scores[idx - 1] = {-gold, -silver, -bronze};
    }
    auto kth = scores[k-1];
    sort(scores.begin(), scores.end());
    auto it = lower_bound(scores.begin(), scores.end(), kth);
    cout << it - scores.begin() + 1;
    return 0;
}