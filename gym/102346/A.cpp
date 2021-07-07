#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define MAX

typedef complex<double> point;
typedef long long ll;
typedef pair<int, int> pii;

struct circle { point p; double r; };
struct line { point p, q; };
using segment = line;

const double eps = 1e-9;

int sign(double x) { return x < -eps ? -1 : x > eps; }

int dblcmp(double x, double y) { return sign(x - y); }

double dot(point a, point b) { return real(conj(a) * b); }

double cross(point a, point b) { return imag(conj(a) * b); }

double area2(point a, point b, point c) { return cross(b - a, c - a); }

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

vector<point> intersect(circle C, circle D)
{
	double d = abs(C.p - D.p);
	if (sign(d - C.r - D.r) > 0) return {};      // too far
	if (sign(d - abs(C.r - D.r)) < 0) return {}; // too close
	double a = (C.r*C.r - D.r*D.r + d*d) / (2*d);
	double h = sqrt(C.r*C.r - a*a);
	point v = (D.p - C.p) / d;
	if (sign(h) == 0) return {C.p + v*a};         // touch
	return {C.p + v*a + point(0,1)*v*h,           // intersect
			C.p + v*a - point(0,1)*v*h};
}

vector<point> intersect(line L, circle C)
{
	point u = L.p - L.q, v = L.p - C.p;
	double a = dot(u, u), b = dot(u, v), c = dot(v, v) - C.r*C.r;
	double det = b*b - a*c;
	if (sign(det) < 0) return {};             // no solution
	if (sign(det) == 0) return {L.p - b/a*u}; // touch
	return {L.p + (-b + sqrt(det))/a*u,
			L.p + (-b - sqrt(det))/a*u};
}

struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<circle> c(k);

	for(int i = 0; i < k; i++){
		int x, y, r;
		cin >> x >> y >> r;

		c[i] = {point(1.0 * x, 1.0 * y), 1.0 * r};
	}

	union_find ds(n + 4);


	for(int i = 0; i < k; i++){
		for(int j = i + 1; j < k; j++){
			vector<point> I = intersect(c[i], c[j]);
			if(!I.empty())
				ds.join(i + 4, j + 4);
		}

		line l = {point(0.0, 0.0), point(1.0 * n, 0.0)};
		auto I = intersect(l, c[i]);

		if(!I.empty())
			ds.join(i + 4, 0);

		l = {point(1.0 * n, 0.0), point(1.0 * n, 1.0 * m)};
		I = intersect(l, c[i]);

		if(!I.empty())
			ds.join(i + 4, 1);

		l = {point(1.0 * n, 1.0 * m), point(0.0, 1.0 * m)};
		I = intersect(l, c[i]);

		if(!I.empty())
			ds.join(i + 4, 2);

		l = {point(0.0, 1.0 * m), point(0.0, 0.0)};
		I = intersect(l, c[i]);

		if(!I.empty())
			ds.join(i + 4, 3);

	}

	bool ok = true;

	if(ds.root(0) == ds.root(3) || ds.root(1) == ds.root(2) || ds.root(0) == ds.root(2) || ds.root(3) == ds.root(1))
		ok = false;

	cout << (ok ? "S" : "N") << endl;


	return 0;
}