#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N,K; 
    cin >>N >> K;
    deque<char> wheel;
    for(int i=0;i<N;++i)
        wheel.push_back(-1);

    for(int i=0; i<K; ++i){
        int a; char c;
        cin >> a >> c;
        int ct=0, lim = a*N;
        char prev = wheel.back();
        while(a){
            int b = wheel.front();
            wheel.pop_front();
            wheel.push_back(b);
            if(prev != b && (a == 1 && c != b)) {
                a--;
            }
            prev = b;
        }
        char& f = wheel.back();
        if(f == -1) 
            f = c;
        else if(f != c){
            cout << "!";
            return 0;
        }
    }
    for(int i =0;i < N; ++i){
        char c = wheel.back();
        wheel.pop_back();
        if(c == -1)
            cout << '?';
        else
            cout << c;
    }
    
    return 0;
}