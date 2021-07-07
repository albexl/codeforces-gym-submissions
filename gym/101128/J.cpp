#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef complex<ll> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

ll dot(point a, point b) { return real(conj(a) * b); }

ll cross(point a, point b) { return imag(conj(a) * b); }

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

int ccw(point a, point b, point c)
{
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1; // counter clockwise
	if (cross(b, c) < 0) return -1; // clockwise
	if (dot(b, c) < 0) return +2; // c--a--b on line
	if (dot(b, b) < dot(c, c)) return -2; // a--b--c on line
	return 0;
}

namespace std
{
	bool operator<(point a, point b)
	{
		if (a.real() != b.real())
			return a.real() < b.real();
		return a.imag() < b.imag();
	}
}


enum { OUT, ON, IN };

polygon convex_hull(vector<point> &P)
{
	int n = P.size(), k = 0;
	vector<point> h(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; h[k++] = P[i++])
		while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
		while (k >= t && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	return polygon(h.begin(), h.begin() + k - (k > 1));
}


int contains_for_real(const polygon &P, const point &p)
{
    bool in = false;
    for (int i = 0, n = P.size(); i < n; ++i)
    {
        point a = P[i] - p, b = P[NEXT(i)] - p;
        if (imag(a) > imag(b)) swap(a, b);
        if (imag(a) <= 0 && 0 < imag(b))
            if (cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0)
            return ON;
    }
    return in ? IN : OUT;
}

struct convex_container{
    polygon pol;

    convex_container(polygon p) : pol(p){
        int pos = 0;

        for (int i = 1; i < p.size(); ++i){
            if (p[i].imag() < p[pos].imag() ||
                (p[i].imag() == p[pos].imag() && p[i].real() < p[pos].real()))
                pos = i;
        }

        rotate(pol.begin(), pol.begin() + pos, pol.end());
    }

    bool contains(point p){
        point c = pol[0];

        if (p.imag() < c.imag() || cross(pol.back() - c, p - c) > 0)
            return false;

        int lo = 1, hi = pol.size() - 1;

        while (lo + 1 < hi){
            int m = (lo + hi) / 2;

            if (cross(pol[m] - c, p - c) >= 0)
                lo = m;
            else
                hi = m;
        }

        polygon v(3);
        v[0] = c;
        v[1] = pol[lo + 1];
        v[2] = pol[lo];

        int result = contains_for_real(v, p);
        return result == IN || result == ON;
        // return cross(pol[lo + 1] - pol[lo], p - pol[lo]) >= 0;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    polygon p(n);

    for(int i = 0; i < n; i++){
    	ll x, y;
    	cin >> x >> y;
    	p[i] = point(x, y);
    }

    auto CH = convex_hull(p);
    convex_container cc(CH);

    int m;
    cin >> m;

    int ans = 0;
    for(int i = 0; i < m; i++){
    	ll x, y;
    	cin >> x >> y;
    	if(cc.contains(point(x, y)))
    		ans++;
    }

    cout << ans << endl;

    return 0;
}