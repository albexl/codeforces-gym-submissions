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
typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };

const double eps = 1e-6;

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

point projection(const line &l, const point &p)
{
	double t = dot(p - l.p, l.p - l.q) / norm(l.p - l.q);
	return l.p + t * (l.p - l.q);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		
		int n;
		cin >> n;
		
		int ans = 0;
		
		vector<point> p(n);
		for(int i = 0; i < n; i++){
			double x, y;
			cin >> x >> y;
			p[i] = point(x, y);
		}
		
		random_shuffle(p.begin(), p.end());
		
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				for(int k = 0; k < n; k++){
					
					if(k == i || k == j)
						continue;
					
					line l = {p[i], p[j]};
					point proj = projection(l, p[k]);
					
					double d1 = abs(p[i] - p[j]);
					double d2 = abs(p[k] - proj);
					double d3 = abs(p[i] - proj);
					double d4 = abs(p[j] - proj);
					
					if(abs(d1 - d2) < eps && abs(d3 - d4) < eps){
						for(int m = 0; m < n; m++){
							if(m != i && m != j && m != k && abs(proj - p[m]) < eps){
								ans++;
								break;
							}
						}
					}
						
				}
			}
		}
		
		cout << "Set #" << cases << ": " << ans << endl << endl;
	}
	
	return 0;
}