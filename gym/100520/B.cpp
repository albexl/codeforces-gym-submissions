#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };
using segment = line;

const double eps = 1e-9;
const double oo = 1e7;

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

bool intersectSS(const segment &s, const segment &t)
{
	return ccw(s.p, s.q, t.p) * ccw(s.p, s.q, t.q) <= 0
			&& ccw(t.p, t.q, s.p) * ccw(t.p, t.q, s.q) <= 0;
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

typedef pair<double, double> pdd;

point null_point = {oo, oo};
pdd null_seg = {oo, oo};


pdd get_segs(segment s, double a, double b){

	if(abs(s.p.imag() - s.q.imag()) < eps){
		if(s.p.imag() > a - eps && s.p.imag() < b + eps)
			return {s.p.real(), s.q.real()};
		return null_seg;
	}

	point I1 = null_point, I2 = null_point;
	segment la = {point(-oo, a), point(oo, a)};
	segment lb = {point(-oo, b), point(oo, b)};

	if(intersectSS(s, la))
		I1 = crosspoint(s, la);
	if(intersectSS(s, lb))
		I2 = crosspoint(s, lb);

	if(I1 != null_point && I2 != null_point)
		return {min(I1.real(), I2.real()), max(I1.real(), I2.real())};

	if(I1 == null_point && I2 == null_point){
		if(s.p.imag() > a - eps && s.p.imag() < b + eps && s.q.imag() > a - eps && s.q.imag() < b + eps)
			return {s.p.real(), s.q.real()};
		else
			return null_seg;
	}

	if(I1 == null_point)
		swap(I1, I2);

	if(s.p.imag() > a - eps && s.p.imag() < b + eps)
		return {min(s.p.real(), I1.real()), max(s.p.real(), I1.real())};
	else
		return {min(s.q.real(), I1.real()), max(s.q.real(), I1.real())};
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cout << setprecision(10) << fixed;

	freopen("bayes.in", "r", stdin);
	freopen("bayes.out", "w", stdout);


	int n;

	while(cin >> n && n){
		double a, b, alpha;
		cin >> a >> b >> alpha;

		n++;

		vector<point> f(n);

		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			f[i] = {1.0 * x, 1.0 * y};
		}

		vector<pair<double, double>> segs;

		double k = 0.0;

		for(int i = 0; i < n - 1; i++){

			segment s = {f[i], f[i + 1]};

			auto x = get_segs(s, a, b);
			if(x != null_seg)
				segs.push_back(x), k += (x.second - x.first);

		}

		alpha *= k;

		int sz = segs.size();

		vector<double> acumL(sz), acumR(sz);

		for(int i = 0; i < sz; i++){
			acumL[i] = segs[i].second - segs[i].first;
			if(i)
				acumL[i] += acumL[i - 1];
		}

		for(int i = sz - 1; i >= 0; i--){
			acumR[i] = segs[i].second - segs[i].first;
			if(i + 1 != sz)
				acumR[i] += acumR[i + 1];
		}

		double opt = oo;
		double x = 0, y = 0;

//		for(auto &e : segs)
//			cout << e.first << " " << e.second << endl;
//		cout << endl;
//
//		cout << alpha << endl;
//		cout << endl;

		for(int i = 0; i < sz; i++){
			int lo = i, hi = sz - 1;
			int q = -1;

			while(lo <= hi){
				int mid = (lo + hi) >> 1;
				double sum = acumL[mid];
				if(i)
					sum -= acumL[i - 1];
				if(sum + eps > alpha){
					q = mid;
					hi = mid - 1;
				}
				else lo = mid + 1;
			}

			if(q == -1)
				continue;

			double dist = acumL[q];
			if(i)
				dist -= acumL[i - 1];

			double xo = segs[i].first;
			double yo = segs[q].second - (dist - alpha);

			if(yo - xo < opt){
				opt = yo - xo;
				x = xo, y = yo;
			}
		}

		for(int i = 0; i < sz; i++){
			int lo = 0, hi = i;
			int q = -1;
			while(lo <= hi){
				int mid = (lo + hi) >> 1;
				double sum = acumR[mid];
				if(i + 1 != sz)
					sum -= acumR[i + 1];
				if(sum + eps > alpha){
					q = mid;
					hi = mid - 1;
				}
				else lo = mid + 1;
			}


			if(q == -1)
				continue;

			double dist = acumR[q];
			if(i + 1 != sz)
				dist -= acumR[i + 1];

			double xo = segs[i].first + (dist - alpha);
			double yo = segs[i].second;

			if(yo - xo < opt){
				opt = yo - xo;
				x = xo, y = yo;
			}

		}

		cout << x << " " << y << endl;
//		cout << opt << endl;

	}

	return 0;
}