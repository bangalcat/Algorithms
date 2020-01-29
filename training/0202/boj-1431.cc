// 시리얼 번호

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n; 
    vector<string> arr(n);
    for(int i=0;i<n;++i) {
        cin >> arr[i];
    }
    auto comp = [](const string &a, const string &b) {
        if(a.size() == b.size()){
            int asum = 0, 
                bsum = 0;
            
            // for(int i=0; i < a.size(); ++i){
            //     if(a[i] >= '1' && a[i] <= '9')
            //         asum += a[i] - '0';
            // }
            for_each(a.begin(), a.end(), [&asum](char c){
                if(c >= '1' && c <= '9')
                    asum += c - '0';
            });
            for_each(b.begin(), b.end(), [&bsum](char c){
                if(c >= '1' && c <= '9')
                    bsum += c - '0';
            });
            if(asum == bsum){
                return a < b;
            }else
                return asum < bsum;
        }else{
            return a.size() < b.size();
        }
    };
    sort(arr.begin(), arr.end(), comp);
    for(auto s: arr)
        cout << s << '\n';
    return 0;
}