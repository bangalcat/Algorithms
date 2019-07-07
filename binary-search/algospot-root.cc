#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//단일 변수 다항식 p의 계수가 주어질 때 미분한 결과 p의 계수
vector<double> differentiate(const vector<double>& poly) {
    vector<double> ret;
    int n = poly.size() - 1;
    for(int i=0; i < n; ++i){
        ret.push_back(poly[i] * (n-i));
    }
    return ret;
}
// 1차 혹은 2차 방정식의 해
vector<double> solveNaive(const vector<double>& poly) {
    vector<double> ret;
    // ax + b = 0
    if(poly.size() == 2)
        ret.push_back (-poly[1] / poly[0]);
    // ax^2 + bx + c = 0
    else {
        // (-b + sqrt(b^2 - 4ac)) / 2a
        double r1 = (-poly[1] + sqrt(poly[1] * poly[1] - 4 * poly[2] * poly[0])) / poly[0] / 2;
        double r2 = (-poly[1] - sqrt(poly[1] * poly[1] - 4 * poly[2] * poly[0])) / poly[0] / 2;
        ret.push_back(r1);
        if(r1 != r2)
            ret.push_back(r2);
    }
    sort(ret.begin(), ret.end());
    return ret;
}
// 다항식 f(x)의 계수 poly가 주어질 때, f(x0)를 반환한다.
double evaluate(const vector<double>& poly, double x0) {
    double ret = 0;
    int n = poly.size() - 1;
    for(int i=0; i< poly.size(); ++i){
        ret += pow(x0, n-i) * poly[i];
    }
    return ret;
}
//방정식의 해의 절대값은 L 이하여야한다.
const double L = 25;

vector<double> solve(const vector<double>& poly) {
    int n = poly.size() - 1;
    if(n <= 2) return solveNaive(poly);
    //방정식을 미분해서 n-1차 방정식을 얻는다.
    vector<double> derivative = differentiate(poly);
    vector<double> sols = solve(derivative);
    // 이 극점들 사이를 하나하나 검사하며 근이 있나 확인한다.
    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);
    vector<double> ret;
    for(int i=0; i+1 < sols.size(); ++i) {
        double x1 = sols[i], x2 = sols[i+1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
        // f(x1)과 f(x2)의 부호가 같은 경우 답은 없다.
        if(y1 * y2 > 0) continue;
        if(y1 > y2) {swap(y1, y2); swap(x1, x2);}
        // 이분법
        for(int iter = 0; iter < 100; ++iter) {
            double mx = (x1 + x2) / 2;
            double my = evaluate(poly, mx);
            if(y1 * my > 0) {
                y1 = my;
                x1 = mx;
            }else {
                y2 = my;
                x2 = mx;
            }
        }
        ret.push_back((x1 + x2) / 2);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main()
{
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        vector<double> poly(n+1);
        for(int i=0;i<n+1;++i)
            cin >> poly[i];
        auto ret = solve(poly);
        for(auto& p : ret)
            printf("%.10f ", p);
        cout << endl;
    }

    return 0;
}