#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n; scanf("%d",&n);
    vector<string> vec;
    string s;
    while(n--){
        char cstr[51];
        scanf("%s",cstr);
        vec.push_back(string(cstr));
    }
    auto cmp = [](const string& s1, const string& s2){
        if(s1.size() == s2.size())
            return s1 < s2;
        return s1.size() < s2.size();
    };
    sort(vec.begin(),vec.end(),cmp);
    vector<string>::iterator ends = unique(vec.begin(),vec.end());
    for(auto i=vec.begin(); i < ends; i++){
        printf("%s\n",(*i).c_str());
    }
    return 0;
}