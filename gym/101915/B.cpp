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

const double eps = 1e-9;

// fix comparations on doubles with this two functions
int sign(double x) { return x < -eps ? -1 : x > eps; }

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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		
		vector<circle> a(n);
		vector<int> s(n);
		
		for(int i = 0, x, y, r; i < n; i++){
			cin >> x >> y >> r >> s[i];
			a[i] = {point(1.0 * x, 1.0 * y), 1.0 * r};
		}
		
		vector<point> cands;
		for(int i = 0; i < n; i++)
			cands.push_back(a[i].p);
		
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++){
				vector<point> I = intersect(a[i], a[j]);
				for(auto &p : I)
					cands.push_back(p);
			}

		int ans = 0;
		for(auto &p : cands){
			vector<int> S;
			for(int i = 0; i < n; i++){
				double d = abs(a[i].p - p);
				if(d < a[i].r + eps)
					S.push_back(s[i]);
			}
			
			int cur = 0;
			sort(S.rbegin(), S.rend());
			
			for(int i = 0; i < min(m, (int)S.size()); i++)
				cur += S[i];
			
			ans = max(ans, cur);
		}
		
		cout << ans << endl;
	}

	return 0;
}