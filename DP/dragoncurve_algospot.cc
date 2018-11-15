/*
    알고스팟 문제 : 드래곤 커브
    드래곤 커브 n세대 후 부분 문자열 구하는 문제
    각 세대의 길이를 미리 계산해 놓는데, X와 Y를 진화시켰을때의 길이를 미리 계산
    X와 Y는 동일한 길이로 진화하기 때문에 결국 하나의 길이 배열만 초기화 해놓으면 됨
    n세대만큼 진화한다고 했을때 k번째 문자를 구하는 함수를 정의
    현재 seed를 순서대로 살피는데, 'X'나 'Y'를 만나면 진화시켰을 때의 길이를 skip과 비교
    n세대 만큼 진화시킨 길이가 현재 skip보다 작다면, 굳이 진화시킬(재귀시킬) 필요 없이 skip에서 그 길이만큼 빼고 넘긴다.
    다음 'X'나 'Y' 만났는데 skip보다 진화시킨 길이가 크다면, 진화시킬 seed를 넘기면서 재귀호출한다.
*/
#include <iostream>
#include <cassert>

using namespace std;
const int MAX = 1e9+100;
const string X_SEED = "X+YF";
const string Y_SEED = "FX-Y";

//X나 Y를 i세대 만큼 진화시킨 길이
int genLen[51];
void preCalc(){
    genLen[0] = 1;
    for(int i=1;i<51;i++){
        genLen[i] = min(MAX,genLen[i-1] * 2 + 2);
    }
}

char dragonCurve(const string& seed, int gene, int skip){
    if(gene==0)
        return seed[skip];
    for(int i=0;i<seed.size();++i){
        if(seed[i] == 'X' || seed[i] == 'Y'){
            if(skip >= genLen[gene]){
                skip-= genLen[gene];
            }else if(seed[i]=='X'){
                return dragonCurve(X_SEED,gene-1,skip);
            }else 
                return dragonCurve(Y_SEED,gene-1,skip);
        }else if(skip>0)
            --skip;
        else
            return seed[i];
    }
    assert(true);
    return '#';
}
int main()
{
    int tc;
    cin >> tc;
    preCalc();
    while(tc--){
        int n,p,l;
        cin >> n >> p >> l;
        for(int i=0;i<l;i++){
            cout << dragonCurve("FX",n,p+i-1);
        }   
        cout << endl;
    }
    return 0;
}
