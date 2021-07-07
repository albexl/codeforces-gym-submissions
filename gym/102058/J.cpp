#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

#define double long double

typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };
using segment = line;

const double eps = 1e-9;
const ll oo = 1e14;

// fix comparations on doubles with this two functions
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


bool intersectLL(const line &l, const line &m)
{
	return abs(cross(l.q - l.p, m.q - m.p)) > eps || // non-parallel
			abs(cross(l.q - l.p, m.p - l.p)) < eps;   // same line
}

bool intersectLS(const line &l, const segment &s)
{
	return cross(l.q - l.p, s.p - l.p) *       // s[0] is left of l
			cross(l.q - l.p, s.q - l.p) < eps; // s[1] is right of l
}

bool intersectLP(const line &l, const point &p)
{
	return abs(cross(l.q - p, l.p - p)) < eps;
}

bool intersectSS(const segment &s, const segment &t)
{
	return ccw(s.p, s.q, t.p) * ccw(s.p, s.q, t.q) <= 0
			&& ccw(t.p, t.q, s.p) * ccw(t.p, t.q, s.q) <= 0;
}

bool intersectSP(const segment &s, const point &p)
{
	return abs(s.p - p) + abs(s.q - p) - abs(s.q - s.p) < eps;
	// triangle inequality
	return min(real(s.p), real(s.q)) <= real(p)
			&& real(p) <= max(real(s.p), real(s.q))
			&& min(imag(s.p), imag(s.q)) <= imag(p)
			&& imag(p) <= max(imag(s.p), imag(s.q))
			&& cross(s.p - p, s.q - p) == 0;
}

point projection(const line &l, const point &p)
{
	double t = dot(p - l.p, l.p - l.q) / norm(l.p - l.q);
	return l.p + t * (l.p - l.q);
}

double distanceLP(const line &l, const point &p)
{
	return abs(p - projection(l, p));
}

double distanceLL(const line &l, const line &m)
{
	return intersectLL(l, m) ? 0 : distanceLP(l, m.p);
}

double distanceLS(const line &l, const line &s)
{
	if (intersectLS(l, s)) return 0;
	return min(distanceLP(l, s.p), distanceLP(l, s.q));
}

double distanceSP(const segment &s, const point &p)
{
	const point r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return min(abs(s.p - p), abs(s.q - p));
}

double distanceSS(const segment &s, const segment &t)
{
	if (intersectSS(s, t)) return 0;
	return min(min(distanceSP(s, t.p), distanceSP(s, t.q)),
			min(distanceSP(t, s.p), distanceSP(t, s.q)));
}

point crosspoint(const line &l, const line &m)
{
	double A = cross(l.q - l.p, m.q - m.p);
	double B = cross(l.q - l.p, l.q - m.p);
	if (abs(A) < eps && abs(B) < eps)
		return m.p; // same line
	if (abs(A) < eps)
		assert(false); // !!!PRECONDITION NOT SATISFIED!!!
	return m.p + B / A * (m.q - m.p);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> X(2 * n), Y(2 * n);

	for(auto &x : X) cin >> x;

	int xo, yo = -1;
	cin >> xo;

	for(int i = 1; i < 2 * n; i++){


		int mul = 1;
		if(i % 2 == 0)
			mul = -1;

		Y[i] = Y[i - 1] + mul * (X[i] - X[i - 1]);

		if(xo >= X[i - 1] && xo <= X[i]){

			yo = Y[i - 1] + mul * (xo - X[i - 1]);

		}

	}


	ll lo = 0, hi = oo;
	ll ans = -1;


	function<bool(ll)> ok = [&](ll h){

		bool res = true;

		segment s2 = {point(0.0, 1.0 * h), point(1.0 * xo, 1.0 * yo)};


		//cout << s2.p << " " << s2.q << endl;

		for(int i = 1; i < 2 * n; i++){
			if(xo >= X[i - 1] && xo <= X[i])
				break;

			point p1 = point(1.0 * X[i - 1], 1.0 * Y[i - 1]);
			point p2 = point(1.0 * X[i], 1.0 * Y[i]);

			segment s1 = {p1, p2};

			if(intersectSS(s1, s2)){

				point I = crosspoint(s1, s2);

				if(abs(I - p1) > eps && abs(I - p2) > eps)
				{
//					cout << p1 << " " << p2 << endl;
//					cout << "false" << endl;
					res = false;
				}

			}
		}

		return res;
	};

	while(lo <= hi){
		ll mid = (lo + hi) >> 1LL;

//		cout << mid << " " << ok(mid) << endl;

		if(ok(mid)){
			ans = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	cout << ans << endl;

	return 0;
}