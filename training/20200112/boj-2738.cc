#include <iostream>
#include <functional>

using namespace std;

int mat[101][101] = {0,};

int main() {
    int n, m;
    cin >> n >> m;
    auto wrap_func = [&](function<void(int, int)> f){
        for(int i=0;i<n;++i) {
            for(int j=0;j<m;++j) {
                f(i, j);
            }
        }
    };
    auto input_f = [&](int i, int j){
        int a; cin >> a;
        mat[i][j] += a;
    };
    auto output_f = [m](int i, int j) {
        cout << mat[i][j] << ' ';
        if(j == m-1)
            cout << '\n';
    };
    wrap_func(input_f);
    wrap_func(input_f);
    wrap_func(output_f);
    
    return 0;
}