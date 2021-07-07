#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

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

double area2(const polygon &P)
{
	double A = 0;
	for (int i = 0, n = P.size(); i < n; ++i)
		A += cross(P[i], P[NEXT(i)]);
	return A;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	while(true){
		
		double xa, ya, xb, yb, xc, yc;
		double xd, yd, xe, ye, xf, yf;
		cin >> xa >> ya >> xb >> yb >> xc >> yc;
		cin >> xd >> yd >> xe >> ye >> xf >> yf;
		
		point A(xa, ya);
		point B(xb, yb);
		point C(xc, yc);
		
		point D(xd, yd);
		point E(xe, ye);
		point F(xf, yf);
		
		int cnt = 0;
		if(A == point(0.0, 0.0))
			cnt++;
		if(B == point(0.0, 0.0))
			cnt++;
		if(C == point(0.0, 0.0))
			cnt++;
		if(D == point(0.0, 0.0))
			cnt++;
		if(E == point(0.0, 0.0))
			cnt++;
		if(F == point(0.0, 0.0))
			cnt++;
		
		if(cnt == 6)
			break;
		
		polygon t = {D, E, F};
		point dir = C - A;
		double lo = 0.0, hi = 1e10;
		
		for(int i = 0; i < 100; i++){
			double mid = (lo + hi) / 2.0;
			point H = A + dir * mid;
			point G = B + dir * mid;
			
			polygon par = {A, B, G, H};
			
			if(abs(area2(par)) > abs(area2(t)))
				hi = mid;
			else
				lo = mid;
		}
		
		point H = A + dir * lo;
		point G = B + dir * lo;
		
		cout << setprecision(3) << fixed;
		cout << G.real() << " " << G.imag() << " " << H.real() << " " << H.imag() << endl;
		
	}
	

	return 0;
}