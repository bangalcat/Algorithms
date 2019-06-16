#include <bits/stdc++.h>

using namespace std;
const int MAXN = 100000;
const int MAX = numeric_limits<int>::max();

struct RPQ{
    int n;
    vector<int> possible;
    RPQ(vector<int> array){
        n = array.size();
        possible.resize(n*4);

    }
    void init(const vector<int> &minArr, const vector<int>& maxArr, int left, int right, int node, int k)
    {
        if (left == right){
            possible[node] = -maxArr[node] - minArr[node] <= k;
        }
        int mid = (left + right) / 2;
        // int leftMin = init(array, left, mid, node * 2,k);
        // int rightMin = init(array, mid + 1, right, node * 2 + 1,k);
        // return possible[node] = leftMin && rightMin;
    }
    bool query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        //두 구간이 겹치지 않으면 아주 큰 값을 반환한다: 무시 됨
        if (right < nodeLeft || nodeRight < left)
            return false;
        //node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우
        if (left <= nodeLeft && nodeRight <= right)
            return possible[node];
        int mid = (nodeLeft + nodeRight) / 2;
        // return query(left, right, node * 2, nodeLeft, mid)  query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
};

//배열의 구간 최소 쿼리를 해결하기 위한 구간 트리의 구현
struct RMQ
{
    //배열의 길이
    int n;
    bool rev;
    vector<int> rangeMin;
    RMQ(const vector<int> &array, bool isMax)
    {
        n = array.size();
        rangeMin.resize(n * 4);
        rev = isMax;
        init(array, 0, n - 1, 1);
    }

    //node 노드가 array[left...right] 배열을 표현할 때
    //node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소치를 반환한다
    int init(const vector<int> &array, int left, int right, int node)
    {
        if (left == right)
            return rangeMin[node] = rev?-array[left]:array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    //node가 표현하는 범위 array[nodeLeft..nodeRight]가 주어질 때
    //이 범위와 array[left..right]의 교집합의 최소치를 구한다
    int query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        //두 구간이 겹치지 않으면 아주 큰 값을 반환한다: 무시 됨
        if (right < nodeLeft || nodeRight < left)
            return MAX;
        //node가 표현하는 범위가 array[left..right]에 완전히 포함되는 경우
        if (left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];
        //양쪽 구간을 나눠서 푼 뒤 결과를 합친다
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }

    //query()를 외부에서 호출하기 위한 인터페이스
    int query(int left, int right)
    {
        return query(left, right, 1, 0, n - 1);
    }

    //array[index]=newValue로 바뀌었을 떄 node를 루트로 하는
    //구간 트리를 갱신하고 노드가 표현하는 구간의 최소치를 반환한다
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight)
    {
        //index가 노드가 표현하는 구간과 상관없는 경우엔 무시한다
        if (index < nodeLeft || nodeRight < index)
            return rangeMin[node];

        //트리의 리프까지 내려온 경우
        if (nodeLeft == nodeRight)
            return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }

    //update()를 외부에서 호출하기 위한 인터페이스
    int update(int index, int newValue)
    {
        return update(index, newValue, 1, 0, n - 1);
    }
};

int main()
{
    int T; cin >> T;
    for(int t=1;t<=T;++t){
        int r, c, k;
        cin >> r >> c >> k;
        vector<RMQ*> seg_min(r);
        vector<RMQ*> seg_max(r);
        vector<int> line(c);
        vector<vector<vector<bool>>> possible(300, vector<vector<bool>>(300, vector<bool>(300,false)));
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                int a; cin >> a;
                line[j] = a;
            }
            seg_min[i] = new RMQ(line,false);
            seg_max[i] = new RMQ(line,true);
        }
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                for(int l=c-1;l>=j;--l){
                    if(-seg_max[i]->query(j,l) - seg_min[i]->query(j,l) <= k){
                        
                    }
                }
            }
        }
        int ans = 1;
        //300 * 300
        for(int i=0;i<c;++i){
            for(int j=c-1; j>=i;--j){
                if((j-i+1)*r <= ans) continue;
                // * 300
                int l;
                int start = -1;
                for(l=0;l<r;++l){
                    if(start == -1 && (r-l)*(j-i+1) <= ans) break;
                    // * log300
                    // cout << -seg_max[l]->query(i,j) << ' ' << seg_min[l]->query(i,j) << endl;
                    if(possible[l][i][j] || -seg_max[l]->query(i,j) - seg_min[l]->query(i,j) <= k){
                        if(start == -1)
                            start = l;
                        if(possible[l][i][j]) continue;
                        possible[l][i][j] = true;
                        for(int p=i;p<j;++p){
                            possible[l][p][j] = true;
                        }
                        for(int p=j;p>=i;--p){
                            possible[l][i][p] = true;
                        }
                    }
                    else {
                        if(start > -1){
                            ans = max(ans, (j-i+1)*(l-start));
                            start = -1;
                        }
                    }
                }
                if(start == -1) start = l;
                ans = max(ans, (j-i+1)*(l-start));
            }
        }

        cout << "Case #";
        cout << t << ": ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}