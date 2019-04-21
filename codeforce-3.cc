
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b, c, ret = 0;
    cin >> a >> b >> c;
    int maxday = min(a/3,min(b/2,c/2));
    ret += maxday * 7;
    a -= maxday*3;
    if(a>3) a = 3;
    b -= maxday*2; 
    if(b>2) b = 2;
    c -= maxday*2; 
    if(c>2) c = 2;
    if(a==0 && b==0 && c==0) {
        cout << ret;
        return 0;
    }
    int plus=a | b | c;
    if (a + b + c >= 2){
        if(a || b) plus = 2;
        else if(a || c) plus = 2;
        else if(a>=2) plus = 2;
        else if(b || c) plus = 2;
    }
    if (a + b + c >= 3)
    {
        if(c>=2 && a>=1) plus = 3;
        else if(a>=2 && b==1) plus = 3;
        else if((a>=1) &&(b>=1) && (c>=1)) plus = 3;
    }
    if(a + b+ c >= 4){
        if(a>=2&& b>=1 && c>=1) plus = 4;
        else if(a>=1 && b>=1 && c>=2) plus = 4;
        else if(a>=2 && b>=2) plus = 4;
    }
    if(a + b + c >= 5){
        if(a>=2 && b>=1 && c>=2) plus = 5;
        else if(a>=1 && b>=2 && c>=2) plus = 5;
        else if(a >= 3 && b >=1 && c>=1) plus = 5;
        else if(a>=2 && b>=2 && c>=1) plus = 5;
    }
    if(a + b+ c>=6){
        if(a>=2 && b>=2 && c>=2)
            plus = 6;
        else if(a>=3 && b>=1 && c>=2) plus = 6;
        else if(a>=3 && b>=2 && c>=1) plus = 6;
    }
    cout << ret + plus;
    return 0;
}