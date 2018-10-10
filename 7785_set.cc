#include <iostream>
#include <set>
using namespace std;
int main(){
    set<string> sets;
    int n; cin >> n;
    while(n--){
        string name, enter;
        cin >> name >> enter;
        if(enter=="leave" ){
            sets.erase(sets.find(name));
        }else{
            sets.insert(name);
        }
    }
    for(auto it=sets.rbegin(); it!=sets.rend(); i++)
        cout << *it << '\n'
    return 0;
}