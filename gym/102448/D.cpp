#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define double long double

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

bool intersect(circle C, circle D)
{
	double d = abs(C.p - D.p);
	if (sign(d - C.r - D.r) > 0) return false;      // too far
	if (sign(d - abs(C.r - D.r)) < 0) return true; // too close
	double a = (C.r*C.r - D.r*D.r + d*d) / (2*d);
	double h = sqrt(C.r*C.r - a*a);
	point v = (D.p - C.p) / d;
	if (sign(h) == 0) return true;         // touch
	return true;				          // intersect
			
}

bool ok(circle c, vector<circle> &C){
	
	for(auto &circ : C){
		auto I = intersect(c, circ);
		if(!I)
			return false;
		c.r += circ.r;
	}
	
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout << setprecision(10) << fixed;
	
	int n;
	cin >> n;
	
	vector<circle> C(n);
	
	ll xo, yo;
	cin >> xo >> yo;
	
	for(int i = 0; i < n; i++){
		ll x, y, r;
		cin >> x >> y >> r;
		C[i] = {point(1.0 * x, 1.0 * y), 1.0 * r};
	}
	
	point p = point(1.0 * xo, 1.0 * yo);
	
	vector<pair<double, int>>to_sort;
	
	for(int i = 0; i < n; i++)
		to_sort.push_back({max((double)0.0, abs(C[i].p - p) - C[i].r), i});
	
	sort(to_sort.begin(), to_sort.end());
	
	vector<circle> sorted;
	for(int i = 0; i < n; i++)
		sorted.push_back(C[to_sort[i].second]);
	
	double lo = 0.0, hi = 1e15;
	
	for(int i = 0; i < 140; i++){
		double mid = (lo + hi) / 2.0;
		
		circle Q = {p, mid};
		
		//cout << mid << " " << ok(Q, sorted) << endl;
		
		if(ok(Q, sorted))
			hi = mid;
		else
			lo = mid;
	}
	
	cout << lo << endl;

	return 0;
}