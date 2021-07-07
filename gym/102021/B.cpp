#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define double long double

typedef long long ll;
typedef pair<int, int> pii;

typedef complex<double> point;
typedef vector<point> polygon;

struct circle { point p; double r; };

const double eps = 1e-10;
vector<point> tangent(point p, circle C)
{
	double D = abs(p - C.p);

	if (D + eps < C.r) return {};
	point t = C.p - p;

	double theta = asin( C.r / D );
	double d = cos(theta) * D;

	t = t / abs(t) * d;
	if ( abs(D - C.r) < eps ) return {p + t};
	point rot( cosl(theta), sinl(theta) );
	return {p + t * rot, p + t * conj(rot)};
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x, y, r;

	cin >> x >> y;
	point from = {(double)x, (double)y};

	cin >> x >> y;
	point to = {(double)x, (double)y};

	cin >> x >> y >> r;
	cin >> x >> y >> r;

	circle C = {{(double)x, (double)y}, (double)r};

	auto tf = tangent(from, C);
	auto tt = tangent(to, C);

	double d = -1;
	for(auto &p1 : tf)
		for(auto &p2 : tt)
		{
			double d1 = abs(p1 - from) + abs(p2 - to);

			point a = p1 - C.p;
			point b = p2 - C.p;

			double alpha = arg(a), beta = arg(b);
			if(alpha < 0) alpha = 2 * acos(-1) + alpha;
			if(beta < 0) beta = 2 * acos(-1) + beta;

			if(beta > alpha) swap(alpha, beta);
			alpha -= beta;

			d1 += min(alpha * C.r, (2 * acos(-1) - alpha) * C.r);

			if(d < 0.5)
				d = d1;
			else
				d = min(d, d1);
		}

	cout << fixed << setprecision(12) << d << endl;

	return 0;
}