#include<cstdio>
#include <queue>

using namespace std;

int stoi(char *cstr){
    int sum=0;
    for(int i=0;cstr[i]!='\0';i++){
        sum*=10; sum+=(cstr[i]-'0');
    }
    return sum;
}

int main()
{
    queue<int> q;
    char oper[50];
    int n;
    for(scanf("%d",&n);scanf("%s",oper)>0;){
        if(oper[0] == 'p'){
            if(oper[1] == 'u'){
                scanf("%s",oper);
                q.push(stoi(oper));
            }else{
                if(q.empty()) printf("-1\n");
                else{
                    printf("%d\n",q.front());
                    q.pop();
                }
            }
        }else if(oper[0] == 's'){
            printf("%d\n",q.size());
        }else if(oper[0] == 'e'){
            printf("%d\n",q.empty());
        }else if(oper[0] == 'f'){
            if(q.empty()) printf("-1\n");
            else
                printf("%d\n",q.front());
        }else if(oper[0] == 'b'){
            if(q.empty()) printf("-1\n");
            else
                printf("%d\n",q.back());
        }
    }
    return 0;
}