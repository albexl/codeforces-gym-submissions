#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
 
typedef long double ld;
typedef long long ll;
 
const ld pi = acos(-1.0l);
 
int t;
int gx, gy, gr;
int vx, vy, vr;
 
ld Area(ld r) { return pi * r * r; }
 
ll squareDist() { return ll(gx - vx) * (gx - vx) + ll(gy - vy) * (gy - vy); }
 
ld Cut(ld r, ld a)
{
        ld hs = a / (2.0l * r);
        if (hs < -1) hs = -1;
        else if (hs > 1) hs = 1;
        ld alpha = 2.0l * asin(hs);
        return r * r / 2 * (alpha - sin(alpha));
}
 
ld Intersection()
{
        if (gr > vr) { swap(gx, vx); swap(gy, vy); swap(gr, vr); }
        ll sD = squareDist();
        if (sD >= ll(vr + gr) * (vr + gr)) return 0.0l;
        if (ll(vr - gr) * (vr - gr) >= sD) return Area(gr);
        ld D = sqrt(ld(sD));
        ld a = (ld(gr) * gr + ld(sD) - ld(vr) * vr) / (2.0l * D);
        ld h = 2.0l * sqrt(ld(gr) * gr - a * a);
        return Cut(vr, h) + (a >= 0? Cut(gr, h): Area(gr) - Cut(gr, h));
}
 
int main()
{
        scanf("%d", &t);
        for (int tc = 1; tc <= t; tc++) {
                scanf("%d %d %d", &gx, &gy, &gr);
                scanf("%d %d %d", &vx, &vy, &vr);
                printf("Case #%d: %.10lf\n", tc, double(Area(gr) - Intersection()));
        }
        return 0;
}