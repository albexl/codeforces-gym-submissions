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

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


typedef complex<double> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };

const double eps = 1e-4;

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

vector<point> intersect(circle C, circle D)
{
	double d = abs(C.p - D.p);
	if (sign(d - C.r - D.r) > 0) return {};      // too far
	if (sign(d - abs(C.r - D.r)) < 0) return {}; // too close
	double a = (C.r*C.r - D.r*D.r + d*d) / (2*d);
	double h = sqrt(C.r*C.r - a*a);
	point v = (D.p - C.p) / d;
	if (sign(h) == 0) return {C.p + v*a};         // touch
	return {C.p + v*a + point(0,1)*v*h,           // intersect
			C.p + v*a - point(0,1)*v*h};
}

struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("circles.in", "r", stdin);
	freopen("circles.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<circle> v;
	
	vector<int> X(n), Y(n), R(n);
	set<pair<pii, int>> S;
	
	for(int i = 0; i < n; i++){
		int x, y, r;
		cin >> x >> y >> r;
		X[i] = x, Y[i] = y, R[i] = r;
		circle c = {point(1.0 * x, 1.0 * y), 1.0 * r};
		
		pair<pii, int> cur = {{x, y}, r};
		
		if(S.find(cur) == S.end()){
			v.push_back(c);
			S.insert(cur);
		}
	}
	
	n = v.size();
	
	union_find ds(n);
	vector<vector<point>> verts(n);
	set<point> total;
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			auto I = intersect(v[i], v[j]);
			if(!I.empty())
				ds.join(i, j);
			
			for(auto &p : I){
				verts[i].push_back(p);
				verts[j].push_back(p);
				
				bool ok = true;
				for(auto &el : total)
					if(abs(el - p) < eps)
						ok = false;
				
				if(ok)
					total.insert(p);
			}
		}
	}
	
	int V = 0, E = 0, C = 0;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < verts[i].size(); j++){
			bool ok = true;
			for(int k = 0; k < j; k++){
				if(abs(verts[i][j] - verts[i][k]) < eps)
					ok = false;
			}
			E += ok;
		}
	}
	
	V = (int)total.size();
	
	set<int> roots;
	for(int i = 0; i < n; i++)
		roots.insert(ds.root(i));
	
	C = (int)roots.size();
		
	cout << C + E - V + 1 << endl;
	
	return 0;
}