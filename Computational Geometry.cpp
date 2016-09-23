#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
inline double sqr(double x) { return x*x; }
struct P { double x, y; P(double _x=0,double _y=0):x(_x),y(_y){} };
typedef P V;
inline double dis2(P A, P B) { return sqr(A.x - B.x) + sqr(A.y - B.y); }
inline double dis(P A, P B) { return sqrt(dis2(A, B)); }
inline double dot(V A, V B) { return A.x*B.x + A.y*B.y; }
inline double det(V A, V B) { return A.x*B.y - A.y*B.x; }
inline double len2(V A) { return sqr(A.x) + sqr(A.y); }
inline double len(V A) { return sqrt(len2(A)); }
inline double angle(V A, V B) { return acos(dot(A, B) / sqrt(len2(A)) / sqrt(len2(B))); }
inline V operator + (V A, V B) { return V(A.x + B.x, A.y + B.y); }
inline V operator - (V A, V B) { return V(A.x - B.x, A.y - B.y); }
inline V operator * (V A, double a) { return V(A.x * a, A.y * a); }
inline V operator / (V A, double a) { return V(A.x / a, A.y / a); }
inline V rot(V A, double rad) { 
    return V(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad)); 
}
inline V unit(V A) { 
    double l = sqrt(len2(A)); 
    return V(A.x / l, A.y / l); 
}
inline bool operator < (const P &A, const P &B) { 
    return A.x < B.x || (A.x == B.x && A.y < B.y); 
}
const double EPS = 1e-10;
inline int cmp0(double x) { 
    if (fabs(x) < EPS)return 0; 
    else return x < 0 ? -1 : 1; 
}
inline bool operator == (P A, P B) { return cmp0(A.x - B.x) == 0 && cmp0(A.y - B.y) == 0; }
inline P lineIntersection(P A, V v1, P B, V v2) { 
    V u = A - B; 
    return A + v1 * (det(v2, u) / det(v1, v2)); 
}
inline double disToLine(P A, P X, P Y) { 
    V v = Y - X; 
    return fabs(det(v, A - X)) / len(v); 
}
double polyArea(vector<P> v) { 
    double tot = 0; 
    int sz = v.size();
    for(int i = 1; i < sz - 1; ++i) 
	tot += det(v[i] - v[0], v[i + 1] - v[0]); 
    return tot / 2; 
}
vector<P> convexHull(vector<P> ps) {
    int n = ps.size();
    if(n <= 1) return ps;
    sort(ps.begin(), ps.end());
    vector<P> qs;
    for(int i = 0; i < n; qs.push_back(ps[i++])){
	P pre = qs[qs.size() - 2];
	while(qs.size() > 1 && det(qs.back() - pre, ps[i] - pre) <= 0)
	    qs.pop_back();
    }
    for(int i = n - 2, t = qs.size(); i >= 0; qs.push_back(ps[i--])){
	P pre = qs[(int)qs.size() - 2];
	while((int)qs.size() > t && det(qs.back() - pre, ps[i] - pre) <= 0)
	    qs.pop_back();
    }
    qs.pop_back();
    return qs;
}
int main()
{
    return 0;
}
