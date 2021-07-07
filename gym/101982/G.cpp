#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };


const double eps = 1e-9;
const double oo = 1e15;

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

#define x(_t) (xa + (_t) * a)
#define y(_t) (ya + (_t) * b)

double radian(double xa, double ya, double xb, double yb)
{
	return atan2(xa * yb - xb * ya, xa * xb + ya * yb);
}

double part(double xa, double ya, double xb, double yb, double r)
{
	double l = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
	double a = (xb - xa) / l, b = (yb - ya) / l, c = a * xa + b * ya;
	double d = 4.0 * (c * c - xa * xa - ya * ya + r * r);
	if (d < eps)
		return radian(xa, ya, xb, yb) * r * r * 0.5;
	else
	{
		d = sqrt(d) * 0.5;
		double s = -c - d, t = -c + d;
		if (s < 0.0) s = 0.0;
		else if (s > l) s = l;
		if (t < 0.0) t = 0.0;
		else if (t > l) t = l;
		return (x(s) * y(t) - x(t) * y(s)
				+ (radian(xa, ya, x(s), y(s))
				+ radian(x(t), y(t), xb, yb)) * r * r) * 0.5;
	}
}

double intersection_circle_polygon(const polygon &P, double r)
{
	double s = 0.0;
	int n = P.size();;
	for (int i = 0; i < n; i++)
		s += part(P[i].real(), P[i].imag(),
			P[NEXT(i)].real(), P[NEXT(i)].imag(), r);
	return fabs(s);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int x, y, xi, yi, xo, yo;
	cin >> x >> y >> xi >> yi >> xo >> yo;
	
	polygon p(4);
	p[0] = point(1.0 * (xi - x), 1.0 * (yi - y));
	p[1] = point(1.0 * (xo - x), 1.0 * (yi - y));
	p[2] = point(1.0 * (xo - x), 1.0 * (yo - y));
	p[3] = point(1.0 * (xi - x), 1.0 * (yo - y));
	
	double lo = 0.0;
	double hi = oo;
	
	cout << setprecision(3) << fixed;
	
	for(int i = 0; i < 100; i++){
		double m = (lo + hi) / 2.0;
		double area = intersection_circle_polygon(p, m);
		//cout << m << " " << area << " dime" << endl;
		if(area < eps)
			lo = m;
		else
			hi = m;
	}
	
	cout << lo << endl;

	return 0;
}