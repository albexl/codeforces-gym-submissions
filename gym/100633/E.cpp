#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

typedef complex<double> point;
typedef complex<ll> pointll;
typedef vector<pointll> polygon;

#define NEXT(i) (((i) + 1) % n)

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

ll cross(pointll a, pointll b) { return imag(conj(a) * b); }

ll dot(pointll a, pointll b) { return real(conj(a) * b); }

ll area2(pointll a, pointll b, pointll c) { return cross(b - a, c - a); }

namespace std
{
	bool operator<(const pointll &a, const pointll &b)
	{
		return real(a) < real(b) || (real(a) == real(b) && imag(a) < imag(b));
	}
}

const ll oo = 0x3f3f3f3f3f3f3f3f;

polygon convex_hull(vector<pointll> &P)
{
	int n = P.size(), k = 0;
	vector<pointll> h(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; h[k++] = P[i++])
		while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
		while (k >= t && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	return polygon(h.begin(), h.begin() + k - (k > 1));
}

struct dynamic_hull
{
	dynamic_hull() : hulls() {}

	void add_point(pointll p)
	{
		hull h;
		h.add_point(p);

		for (hull &_h : hulls)
			if (_h.empty())
			{
				h.swap(_h);
				break;
			}
			else h = merge(h, _h), _h.clear();

		if (!h.empty()) hulls.emplace_back(h);
	}

	pair<ll, pointll> max_dot(pointll p)
	{
		pair<ll, pointll> best = {-oo, {-oo, -oo}};

		for (hull &h : hulls)
			if (!h.empty())
				best = max(h.max_dot(p), best);

		return best;
	}

private:
	struct hull : vector<pointll>
	{
		void add_point(pointll p)
		{
			for (int s = size(); s > 1; --s)
				if (area2(at(s - 2), at(s - 1), p) < 0) break;
				else pop_back();
			push_back(p);
		}

		pair<ll, pointll> max_dot(pointll p)
		{
			int lo = 0, hi = (int) size() - 1, mid;

			while (lo < hi)
			{
				mid = (lo + hi) / 2;

				if (dot(at(mid), p) <= dot(at(mid + 1), p))
					lo = mid + 1;
				else hi = mid;
			}

			return make_pair(dot(at(lo), p), at(lo));
		}
	};

	static hull merge(const hull &a, const hull &b)
	{
		hull h;
		size_t i = 0, j = 0;

		while (i < a.size() && j < b.size())
			if (a[i] < b[j]) h.add_point(a[i++]);
			else h.add_point(b[j++]);

		while (i < a.size()) h.add_point(a[i++]);

		while (j < b.size()) h.add_point(b[j++]);

		return h;
	}

	vector<hull> hulls;
};


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

point reflection(const line &l, const point &p)
{
	return p + 2.0 * (projection(l, p) - p);
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

dynamic_hull LHP, UHP, LHN, UHN;

pointll opt(pointll v){

	auto p1 = LHP.max_dot(v);
	auto p2 = LHN.max_dot(-v);
	auto p3 = UHP.max_dot(v);
	auto p4 = UHN.max_dot(-v);

	p2.second = -p2.second;
	p4.second = -p4.second;

	p1 = max(p1, p2);
	p1 = max(p1, p3);
	p1 = max(p1, p4);

	return p1.second;
}

pointll ort(pointll v){
	return {-v.imag(), v.real()};
}

point convert(pointll p){

	point v = {1.0 * p.real(), 1.0 * p.imag()};
	return v;
}

vector<point> get(pointll v){

	vector<point> ans;

	pointll v2 = ort(v);

	//v
	pointll p1 = opt(v);
	line l1 = {convert(p1), convert(p1 + v2)};

	//-v
	pointll p3 = opt(-v);
	line l3 = {convert(p3), convert(p3 - v2)};

	//ort
	pointll p2 = opt(v2);
	line l2 = {convert(p2), convert(p2 + v)};

	//-ort
	pointll p4 = opt(-v2);
	line l4 = {convert(p4), convert(p4 - v)};

	ans.push_back(crosspoint(l1, l2));
	ans.push_back(crosspoint(l2, l3));
	ans.push_back(crosspoint(l3, l4));
	ans.push_back(crosspoint(l4, l1));

	return ans;
}

double area(vector<point> p){
	return abs(p[0] - p[1]) * abs(p[1] - p[2]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << setprecision(10) << fixed;

	int n;
	cin >> n;

	vector<pointll> a(n);

	for(int i = 0; i < n; i++){

		ll x, y;
		cin >> x >> y;
		a[i] = pointll(x, y);

		UHP.add_point(a[i]);
		LHP.add_point(a[i]);

		LHN.add_point(-a[i]);
		UHN.add_point(-a[i]);
	}

	polygon CH = convex_hull(a);

	int N = (int)CH.size();

	vector<point> ans;
	double area_best = 1e12;

	for(int i = 0; i < N; i++){

		pointll v = CH[i] - CH[(i + 1) % N];
		auto ps = get(v);
		double A = area(ps);

//		cout << A << endl;
//
//		cout << v << endl;
//
//		for(auto &p : ps)
//			cout << p << endl;
//
//		cout << endl;


		if(A < area_best){
			area_best = A;
			ans = ps;
		}
	}

	if(ccw(ans[0], ans[1], ans[2]) != 1)
		reverse(ans.begin(), ans.end());

	for(int i = 0; i < 4; i++)
		cout << ans[i].real() << " " << ans[i].imag() << endl;

	return 0;
}