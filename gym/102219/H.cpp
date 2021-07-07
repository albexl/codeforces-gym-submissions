#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;


typedef complex<ll> point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)

struct circle { point p; double r; };
struct line { point p, q; };
using segment = line;

const double eps = 1e-9;

// fix comparations on doubles with this two functions
int sign(double x) { return x < -eps ? -1 : x > eps; }

int dblcmp(double x, double y) { return sign(x - y); }

ll dot(point a, point b) { return real(conj(a) * b); }

ll cross(point a, point b) { return imag(conj(a) * b); }

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

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


	int t;
	cin >> t;

	int cases = 1;
	while(t--){

		cout << "Case " << cases++ << endl;

		int n, m;
		cin >> n >> m;

		polygon p1(n), p2(m);

		for(int i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			p1[i] = point(x, y);
		}
		for(int i = 0; i < m; i++){
			ll x, y;
			cin >> x >> y;
			p2[i] = point(x, y);
		}

		auto CH = convex_hull(p1);

		int idx = 0;
		for(int i = 1; i < CH.size(); i++)
			if(CH[i] < CH[idx])
				idx = i;

		int cnt = 0;
		for(int i = idx; cnt < CH.size(); i = (i + 1) % (CH.size()) ){
			cout << CH[i].real() << " " << CH[i].imag() << endl;
			cnt++;
		}
		cout << CH[idx].real() << " " << CH[idx].imag() << endl;

		for(auto &el : p2){
			int ans = contains(CH, el);

			cout << el.real() << " " << el.imag() << " is ";
			if(ans == ON || ans == OUT)
				cout << "safe!" << endl;
			else
				cout << "unsafe!" << endl;
		}
		
		if(t)
		    cout << endl;

	}
	
	

	return 0;
}