#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;



typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };
using segment = line;

const double eps = 1e-9;

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

point rotation(point x, double ang)
{
	ang = (acos(-1.0) * ang) / 180.0;
	return x * polar(1.0, ang);//ang en radianes...
}

enum { OUT, ON, IN };
int contains(const polygon &P, const point &p)
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

polygon get_polygon(int k, double angle, double x){
	polygon p;

	point v(x, 0.0);

	for(int i = 0; i < k; i++){
		p.push_back(v);
		v = rotation(v, angle);
	}

	return p;
}

double area_triangle(double x, double angle){
	angle = (acos(-1.0) * angle) / 180.0;
	return x * x * sin(angle) / 2.0;
}

double get_max(int k, polygon &p){

	double lo = 0.0, hi = 1e7;

	double angle = 360.0 / k;

	for(int i = 0; i < 70; i++){
		double mid = (lo + hi) / 2.0;

		polygon v = get_polygon(k, angle, mid);

		bool ok = true;

		for(auto &el : p){
			int val = contains(v, el);
			if(val == OUT)
				ok = false;
		}

		if(ok)
			hi = mid;
		else
			lo = mid;
	}

	return area_triangle(lo, angle) * 1.0 * k;
}

double get_min(int k, polygon &p){

	double lo = 0.0, hi = 1e7;

	double angle = 360.0 / k;

	for(int i = 0; i < 70; i++){
		double mid = (lo + hi) / 2.0;

		polygon v = get_polygon(k, angle, mid);

		bool ok = true;

		for(auto &el : p){
			int val = contains(v, el);
			if(val == IN || val == ON)
				ok = false;
		}

		if(ok)
			lo = mid;
		else
			hi = mid;
	}

	return area_triangle(lo, angle) * 1.0 * k;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cout << setprecision(10) << fixed;

	int n;
	cin >> n;

	polygon p(n);

	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		p[i] = point(1.0 * x, 1.0 * y);
	}

	int opt = -1;
	double ans = 0.0;

	for(int k = 3; k <= 8; k++){

		double a1 = get_max(k, p);
		double a2 = get_min(k, p);

		double rate = a2 / a1;

		if(rate > ans)
			opt = k, ans = rate;

	}

	cout << opt << " " << ans << endl;

	return 0;
}