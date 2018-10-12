#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

typedef vector<vector<int>> VVI;
typedef vector<int> VI;

int dirr[4] = {1,-1,0,0}, dirc[4] = {0,0,1,-1};

class Solver{
private:
    VVI board;
    int N;
    int ans = 0;
public:
    Solver(VVI board) :board(board), N(board.size()) {}
    
    //move_count : 이동 횟수
    //
    int solve(int move_count){
        //5회 이동 시 최대값 반환
        if(move_count == 5){
            int maxret=0;
            for(auto v : board){
                for(auto i : v){
                    //cout << i << " ";
                    maxret = max(maxret, i);
                }
                //cout << '\n';
            }
            //cout << '\n';
            return maxret;
        }
        //board 상태를 임시 변수에 copy
        auto prev_board(board);
        int ret=0;
        //상 하 좌 우 이동
        //상하는 대각선 전환. 하,우는 reverse
        for(int d=0; d<4 ; d++){
            //한줄씩 완성하기
            for(int i=0; i<N; i++){
                VI num_line;
                for(int j=0; j<N; j++){
                    if((d<2?board[j][i]:board[i][j])>0)
                        num_line.push_back(d<2?board[j][i]:board[i][j]);
                }
                //뒤집기
                if(d&1) reverse(num_line.begin(),num_line.end());
                
                VI next_line;
                for(int j=0; j<num_line.size(); j++){
                    if(j+1<num_line.size() && num_line[j] == num_line[j+1]){
                        next_line.push_back(num_line[j++]*2);
                    }else
                        next_line.push_back(num_line[j]);
                }
                next_line.resize(N);
                //다시 뒤집기
                if(d&1) reverse(next_line.begin(),next_line.end());
                //원본 배열에 저장
                for(int j=0; j<N; j++)
                    (d<2?board[j][i]:board[i][j]) = next_line[j];
            }
            //다음 상태로 이동
            ret = max(ret,solve(move_count+1));
            //다음 방향 시도 전에 board의 상태를 복원
            for(int i=0;i<N;i++)
                for(int j=0; j<N ; j++)
                    board[i][j] = prev_board[i][j];
        }
        
        return ret;
    }
};

int main()
{
    int n; cin >> n;
    VVI board(n,VI(n));
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> board[i][j];
            
    Solver solver(board);

    cout << solver.solve(0);
    return 0;
}
