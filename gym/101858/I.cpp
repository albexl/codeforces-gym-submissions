#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };

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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int s, r, m;
	cin >> s >> r >> m;
	polygon a(s), b(r), c(m);
	
	for(int i = 0, x, y; i < s; i++){
		cin >> x >> y;
		a[i] = point(1.0 * x, 1.0 * y);
	}
	
	for(int i = 0, x, y; i < r; i++){
		cin >> x >> y;
		b[i] = point(1.0 * x, 1.0 * y);
	}
	
	for(int i = 0, x, y; i < m; i++){
		cin >> x >> y;
		c[i] = point(1.0 * x, 1.0 * y);
	}
	
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		point p(1.0 * x, 1.0 * y);
		
		int s1 = contains(a, p);
		if(s1 != OUT){
			cout << "Sheena" << endl;
			continue;
		}
		s1 = contains(b, p);
		if(s1 != OUT){
			cout << "Rose" << endl;
			continue;
		}
		s1 = contains(c, p);
		if(s1 != OUT){
			cout << "Maria" << endl;
			continue;
		}
		cout << "Outside" << endl;
	}

	return 0;
}