#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// 테트로미노 도형 문제
//i +1 ..cnt
//j +1 ..cnt
//direct = 0 1 2 왼쪽 오른쪽 아래쪽
// 빠른 방법 : 19가지 경우의 수를 그냥 체크해버리는 방법
int dfs(vector<vector<int>> &arr, int i,int j, int cnt,int direct){
    if(i >= arr.size() || i<0) return 0;
    if(j >= arr[0].size() || j<0) return 0;
    if(cnt==1) return arr[i][j];
    int cross=0;
    if(cnt == 4){
        int up = dfs(arr,i-1,j,1,0);
        int down = dfs(arr,i+1,j,1,0);
        int right = dfs(arr,i,j+1,1,0);
        int left = dfs(arr,i,j-1,1,0);
        cross =  up+down+right+left - min({up,down,right,left});
    }
    
    if(direct == 0)
        return arr[i][j] + max({dfs(arr,i,j-1,cnt-1,0),dfs(arr,i+1,j,cnt-1,2),cross});
    else if(direct == 1)
        return arr[i][j] + max({dfs(arr,i,j+1,cnt-1,1),dfs(arr,i+1,j,cnt-1,2),cross});
    else
        return arr[i][j] + max({dfs(arr,i,j-1,cnt-1,0),dfs(arr,i,j+1,cnt-1,1),dfs(arr,i+1,j,cnt-1,2),cross});
    
}
int getMax(vector<vector<int>> &arr,int n, int m){
    int sum = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int s = dfs(arr,i,j,4,2);
            if(s > sum) sum = s;
        }
    };
    return sum;
}
int main()
{
    int n,m; cin >> n >> m;
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> mat[i][j];
    cout << getMax(mat,n,m);
    return 0;    
}