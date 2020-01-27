#include <iostream>

using namespace std;

int main()
{
    string board[8];
    for(int i=0;i<8;++i) {
        cin >> board[i];
    }
    int count = 0;
    for(int i=0;i<8;i++) {
        for(int j=i%2;j<8;j+=2) {
            if(board[i][j] == 'F') count++;
        }
    }
    cout << count;
    return 0;
}