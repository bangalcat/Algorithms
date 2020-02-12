// python으로 풀었음
#include <iostream>
#include <numeric>

using namespace std;

int main()
{
    char shapes[5], numbers[5];
    int check[10] = {0};
    for(int i=0;i<5;++i){
        cin >> shapes[i];
        cin >> numbers[i];
        check[numbers[i] - '1'] += 1;
    }
    int score = 0;
    // 9가지 조건 순서대로?
    auto solve = [&]() {
        // 숫자가 연속일 떄 -> (1) or (5)
        
    };

    return 0;
}