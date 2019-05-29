#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<int>& arr, int n){
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

int solve(vector<int>& russia, vector<int>& korea){
    int ans = 0;
    int n = russia.size();
    sort(russia.begin(), russia.end());
    sort(korea.begin(), korea.end());

    for(int i=0,j=0;i<n;++i){
        if(korea[i] >= russia[j]){
            j++;
        }
        ans = j;
    }
    return ans;
}

int main()
{
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<int> russia(n);
        vector<int> korea(n);
        input(russia, n);
        input(korea, n);
        cout << solve(russia, korea) << '\n';
    }
    return 0;
}