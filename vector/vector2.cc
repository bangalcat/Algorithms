#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

const double PI = 2.0 * acos(0.0);

/*
    rhs는 right hand side로 보통 인자 두개는 lhs, rhs쓰고 인자 한개는 rhs 씀
    operator 함수에 많이씀
 */

struct vector2{
    double x, y;
    explicit vector2(double x_ = 0, double y_ = 0) : x(x_), y(y_){}

    bool operator==(const vector2& rhs)const{
        return x == rhs.x && y == rhs.y;
    }
    bool operator < (const vector2& rhs) {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
    vector2 operator + (const vector2& rhs) const {
        return vector2(x + rhs.x, y + rhs.y);
    }
    vector2 operator - (const vector2& rhs) const {
        return vector2(x - rhs.x, y - rhs.y);
    }
    vector2 operator * (double rhs) const {
        return vector2(x * rhs, y * rhs);
    }
    //벡터의 길이 반환
    double norm() const {
        return hypot(x, y);
    }
    //방향이 같은 단위 벡터를 반환
    vector2 normalize() const {
        return vector2(x / norm(), y / norm());
    }
    //x축의 양의 방향으로부터 이 벡터까지 반시계 방향으로 잰 각도
    double polar() const {
        return fmod(atan2(y, x) + 2* PI, 2 * PI);
    }
    //벡터의 내적
    double dot(const vector2& rhs) const {
        return x * rhs.x + y * rhs.y;
    }
    //외적
    double cross(const vector2& rhs) const {
        return x * rhs.y - rhs.x * y;
    }
    //이 벡터를 rhs에 사영한 결과
    vector2 project(const vector2& rhs) const {
        vector2 r = rhs.normalize();
        return r * r.dot(*this);
    }
};
//벡터의 방향성을 판단하는 ccw() 함수의 구현
//원점에서 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평해이면 0 반환
double ccw(vector2 a, vector2 b) {
    return a.cross(b);
}
//점 p를 기준으로 벡터 b가 벡터 a의 반시계 방향이면 양수, 시계 방향이면 음수, 평행이면 0
double ccw(vector2 p, vector2 a, vector2 b) {
    return ccw(a-p, b-p);
}

// (a, b)를 포함하는 선과 (c,d)를 포함하는 선의 교점을 x에 반환한다
// 두 선이 평행이면(겹치는경우 포함) 거짓을, 아니면 참을 반환한다.)
bool lineIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& x){
    double det = (b - a).cross(d - c);
    //두 선이 평행인 경우
    if(fabs(det) < numeric_limits<double>::epsilon()) return false;
    x = a + (b - a) * ((c - a).cross(d - c) / det);
    return true;
}

//(a, b)와 (c, d)가 평행한 두 선분일 때 이들이 한 점에서 겹치는지 확인한다.
bool parallelSegments(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p){
    if(b < a) swap(a, b);
    if(d < c) swap(c, d);
    //한 직선 위에 없거나 두 선분이 겹치지 않는 경우를 우선 걸러낸다
    if(ccw(a, b, c) != 0 || b < c || d < a) return false;
    //두 선분은 확실히 겹친다. 교차점을 하나 찾자
    if(a < c) p = c; 
    else p = a;
    return true;
}
// p가 (a, b)를 감싸면서 각 변이 x, y축에 평행한 최소 사각형 내부에 있는지 확인한다.
// a, b, p는 일직선 상에 있다고 가정한다.
bool inBoundingRectangle(vector2 p, vector2 a, vector2 b) {
    if(a < b) swap(a, b);
    return p == a || p == b || (a < p && p < b);
}

// (a, b) 선분과 (c, d)선분의 교점을 p에 반환한다.
// 교점이 여러 개일 경우 아무 점이나 반환한다.
// 두 선분이 교차하지 않을 경우 false를 반환한다.
bool segmentIntersection(vector2 a, vector2 b, vector2 c, vector2 d, vector2& p) {
    // 두 직선이 평행인 경우를 우선 예외로 처리한다.
    if( !lineIntersection(a, b, c, d, p))
        return parallelSegments(a, b, c, d, p);
    //p가 두 선분에 포함되어 있는 경우에만 참을 반환한다.
    return inBoundingRectangle(p, a, b) && inBoundingRectangle(p, c, d);
}

int main()
{
    return 0;
}