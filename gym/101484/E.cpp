#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
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

polygon convex_hull(vector<point> &P)
{
	int n = P.size(), k = 0;
	vector<point> h(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; h[k++] = P[i++])
		while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) < 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
		while (k >= t && area2(h[k - 2], h[k - 1], P[i]) < 0) --k;
	return polygon(h.begin(), h.begin() + k - (k > 1));
}

bool check(polygon a, polygon b){
	if(a.size() != b.size())
		return false;
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i])
			return false;
	return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    polygon p1(n), p2(m), p;

    for(int i = 0; i < n; i++){
    	ll x, y;
    	cin >> x >> y;
    	p1[i] = point(x, y);
    	p.push_back(p1[i]);
    }

    for(int i = 0; i < m; i++){
    	ll x, y;
    	cin >> x >> y;
    	p2[i] = point(x, y);
    	p.push_back(p2[i]);
    }

    auto CH = convex_hull(p);

    sort(CH.begin(), CH.end());
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    if(check(CH, p1) || check(CH, p2))
    	cout << "YES" << endl;
    else
    	cout << "NO" << endl;

    return 0;
}