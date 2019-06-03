#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ord[101]={0};
    int tab[101]={0};
    int tabcnt=0, plugcnt=0;
    for(int i=0;i<k;++i){
        cin >> ord[i];
    }
    loops:
    for(int i=0;i<k;++i){
        int j;
        for(j=0;j<tabcnt;++j){
            if(tab[j] == ord[i]){
                break;
            }
        }
        if(j != tabcnt) continue;
        if(tabcnt < n)
            tab[tabcnt++] = ord[i];
        else{
            int discovered[101]={0};
            int p;
            for(int j=0;j<tabcnt;++j) discovered[j] = -1;
            for(p=i+1;p<k;++p){
                int q;
                for(q=0;q<tabcnt;++q){
                    if(tab[q] == ord[p] && discovered[q] == -1){
                        discovered[q] = p;
                    }
                }
            }
            int target = -1;
            for(int j=0;j<tabcnt;++j){
                if(discovered[j] == -1){
                    tab[j] = ord[i], plugcnt++;
                    target = -1;
                    break;
                }else if(target == -1 || discovered[j] > discovered[target]){
                    target = j;
                }
            }
            if(target != -1)
                tab[target] = ord[i], plugcnt++;
        }
    }
    cout << plugcnt;
    return 0;
}