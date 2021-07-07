#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...) 9999
#endif

typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second
#define ii pair<int,int>
template <typename G, typename H>
struct triple{G F, S, T;};
#define iii triple<int>

ld eps = 1e-9;
int sign(ld x) { return x < -eps ? -1 : x > eps; }
int dblcmp(ld x, ld y) { return sign(x - y); }
ld dot(point a, point b) { return real(conj(a) * b); }
ld dist(point a, point b) { return sqrtl(dot(a - b, a - b)); }

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int ax, ay, bx, by, cx, cy, dx, dy;
    cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;

    //ax *= 1e4; ay *= 1e4; bx *= 1e4; by *= 1e4;
    //cx *= 1e4; cy *= 1e4; dx *= 1e4; dy *= 1e4;

    point p0(ax, ay), v0(bx - ax, by - ay);
    ld t1 = dist({0,0}, v0);
    if(dblcmp(t1, 0) != 0)
        v0 /= t1;

    point p1(cx, cy), v1(dx - cx, dy - cy);
    ld t2 = dist({0,0}, v1);
    if(dblcmp(t2, 0) != 0)
        v1 /= t2;

    ld l = 0, r = min(t1, t2);
    for(int i=0; i<100; i++)
    {
        ld mid1 = l + (r - l) / 3;
        ld mid2 = l + 2.0 * (r - l) / 3;

        point a1 = p0 + mid1 * v0, b1 = p1 + mid1 * v1;
        point a2 = p0 + mid2 * v0, b2 = p1 + mid2 * v1;

        if(dblcmp(dist(a1, b1), dist(a2, b2)) <= 0)
            r = mid2;
        else
            l = mid1;
    }

    ld ans1 = l;

    l = min(t1, t2), r = max(t1, t2);
    for(int i=0; i<100; i++)
    {
        ld mid1 = l + (r - l) / 3;
        ld mid2 = l + 2.0 * (r - l) / 3;

        point a1 = p0 + mid1 * v0, b1 = p1 + mid1 * v1;
        point a2 = p0 + mid2 * v0, b2 = p1 + mid2 * v1;
        if(dblcmp(t1, t2) <= 0)
            a1 = a2 = {(ld)bx, (ld)by};
        if(dblcmp(t1, t2) >= 0)
            b1 = b2 = {(ld)dx, (ld)dy};

        if(dblcmp(dist(a1, b1), dist(a2, b2)) <= 0)
            r = mid2;
        else
            l = mid1;
    }

    ld ans2 = l;
    ld d = 1e18;

    point a = p0 + ans1 * v0, b = p1 + ans1 * v1;
    d = dist(a, b);

    a = p0 + ans2 * v0, b = p1 + ans2 * v1;
    if(dblcmp(t1, t2) <= 0)
        a = {(ld)bx, (ld)by};
    if(dblcmp(t1, t2) >= 0)
        b = {(ld)dx, (ld)dy};

    d = min(d, dist(a, b));

    cout<<setprecision(7)<<fixed<<d<<'\n';

}