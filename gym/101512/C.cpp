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


typedef complex<ll> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };

const double eps = 1e-9;

// fix comparations on doubles with this two functions
int sign(double x) { return x < -eps ? -1 : x > eps; }

int dblcmp(double x, double y) { return sign(x - y); }

ll dot(point a, point b) { return real(conj(a) * b); }

ll cross(point a, point b) { return imag(conj(a) * b); }

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

ll area2(const polygon &P)
{
	ll A = 0;
	for (int i = 0, n = P.size(); i < n; ++i)
		A += cross(P[i], P[NEXT(i)]);
	return A;
}

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

polygon convex_hull(vector<point> &P)
{
	int n = P.size(), k = 0;
	vector<point> h(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; h[k++] = P[i++])
		while (k >= 2 && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	for (int i = n - 2, t = k + 1; i >= 0; h[k++] = P[i--])
		while (k >= t && area2(h[k - 2], h[k - 1], P[i]) <= 0) --k;
	return polygon(h.begin(), h.begin() + k - (k > 1));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	while(tc--){
		
		int n;
		cin >> n;
		
		polygon p(n);
		
		for(int i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			p[i] = point(x, y);
		}
		
		polygon CH = convex_hull(p);
		
		n = (int)CH.size();
		
		vector<vector<ll>> D(n, vector<ll>(n, 0));
		
		ll ans = 0;
		
		if((int)CH.size() == 3)
			ans = area2(CH[0], CH[1], CH[2]);
		else{
			for(int i = 0; i < n; i++){
				vector<point> v;
				v.push_back(CH[i]);
				v.push_back(CH[(i + 1) % n]);
				
				int pos = (i + 2) % n;
				while((int)v.size() < n){
					v.push_back(CH[pos]);
					
					if((int)v.size() == 3)
						D[i][pos] = max(D[i][pos], abs(area2(v[0], v[1], v[2])));
					else{
						int lo = 1, hi = (int)v.size() - 3, opt = (int)v.size() - 2;
						while(lo <= hi){
							int mid = (lo + hi) >> 1;
							
							ll a1 = abs(area2(v[0], v[mid], v.back()));
							ll a2 = abs(area2(v[0], v[mid + 1], v.back()));
												
							if(a1 >= a2){
								opt = mid;
								hi = mid - 1;
							}
							else{
								lo = mid + 1;
							}
						}
						
						D[i][pos] = max(D[i][pos], abs(area2(v[0], v[opt], v.back())));
					}
					
					pos = (pos + 1) % n;
				}
				
			}
		}
				
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				if(D[i][j] + D[j][i] > ans)
					ans = D[i][j] + D[j][i];

		cout << ans / 2;
		if(ans & 1)
			cout << ".5";
			
		cout << endl;
		
	}

	return 0;
}