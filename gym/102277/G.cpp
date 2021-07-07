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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


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



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<pii> p1(n), p2(n);

	for(int i = 0; i < n; i++)
		cin >> p1[i].first >> p1[i].second;
	for(int i = 0; i < n; i++)
		cin >> p2[i].first >> p2[i].second;

	vector<vector<int>> g(n);
	vector<int> d(n, -1);

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){

			bool ok = true;
			segment s = {point(1.0 * p1[i].first, 1.0 * p1[i].second), point(1.0 * p1[j].first, 1.0 * p1[j].second)};

			for(int k = 0; k < n; k++)
				if(k != i && k != j)
					ok &= !intersectSP(s, point(1.0 * p1[k].first, 1.0 * p1[k].second));

			for(int k = 0; k < n; k++)
				ok &= !intersectSP(s, point(1.0 * p2[k].first, 1.0 * p2[k].second));

			if(ok){
				g[j].push_back(i);
				g[i].push_back(j);
			}
		}
	}

	d[0] = 0;
	queue<int> Q;
	Q.push(0);

	while(!Q.empty()){
		int x = Q.front();Q.pop();

		for(auto &y : g[x]){
			if(d[y] == -1){
				d[y] = d[x] + 1;
				Q.push(y);
			}
		}
	}

	cout << d[n - 1] << endl;




	return 0;
}