#include <iostream>
#include <vector>

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int main()
{
    int n, a;
    cin >> n >> a;
    vector<vector<int>> board(n, vector<int>(n));
    int k = n/2;
    int num = n * n;
    for(int i=0;i<k;++i) {
        int r,c;
        r = c = i;
        for(int d=0;d<4;++d) {
            for(int j=0; j < n - 1 - i * 2; j++){
                board[r][c] = num--;
                r += dr[d];
                c += dc[d];
            }
        }
    }
    board[k][k] = 1;
    int ar=0, ac=0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cout << board[i][j] << ' ';
            if(board[i][j] == a){
                ar = i+1, ac = j+1;
            }
        }
        cout << '\n';
    }
    cout << ar << ' ' << ac;
    return 0;
}