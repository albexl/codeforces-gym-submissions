#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
 
typedef long long ll;
typedef pair<ll, ll> pii;
 
const double oo = 1e16;
 
 
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
 
bool intersectSS(const segment &s, const segment &t)
{
	return ccw(s.p, s.q, t.p) * ccw(s.p, s.q, t.q) <= 0
			&& ccw(t.p, t.q, s.p) * ccw(t.p, t.q, s.q) <= 0;
}
 
point projection(const line &l, const point &p)
{
	double t = dot(p - l.p, l.p - l.q) / norm(l.p - l.q);
	return l.p + t * (l.p - l.q);
}
 
double distanceSP(const segment &s, const point &p)
{
	const point r = projection(s, p);
	if (intersectSP(s, r)) return abs(r - p);
	return min(abs(s.p - p), abs(s.q - p));
}
 
double distanceSS(const segment &s, const segment &t)
{
	if (intersectSS(s, t)) return 0;
	return min(min(distanceSP(s, t.p), distanceSP(s, t.q)),
			min(distanceSP(t, s.p), distanceSP(t, s.q)));
}
 
 
 double solve(vector<point> &p, int m, int k){

 	int n = (int)p.size();
 	double ans = oo;

 	// cout << "-----------order" << endl;
 	// for(auto &pp : p)
 	// 	cout << pp << endl;
 	// cout << "-----------" << endl;
 
 
	for(int i = 0; i < n; i++){
 
		segment s1 = {p[i], p[(i + 1) % n]};
 
		// seg to seg
		for(int j = i + 1; j < n; j++){
			if(i != j){
 
				segment s2 = {p[j], p[(j + 1) % n]};
 
				int cnt1 = 3 + j - i - 1;
				int cnt2 = n - (j - (i + 1)) - 2 + 3;
 
				if((cnt1 == k && cnt2 == m) || (cnt1 == m && cnt2 == k))
					ans = min(ans, distanceSS(s1, s2));
 
			}
		}
 
		//seg to point
		for(int j = i + 2; j < n; j++){
			if(j != i && j != (i + 1) % n){
 
				int cnt1 = 2 + j - i - 1;
				int cnt2 = n - (j - (i + 1)) - 1 + 2;

				// cout << p[i] << endl;
				// cout << p[(i + 1) % n] << endl;
				// cout << p[j] << endl;
 
				if((cnt1 == k && cnt2 == m) || (cnt1 == m && cnt2 == k))
					ans = min(ans, distanceSP(s1, p[j]));
 
			}
		}
 
		//point to point
		for(int j = i + 2; j < n; j++){
			if(i != j){
 
				int cnt1 = j - i + 1;
				int cnt2 = n - (j - i) + 1;
 
				if((cnt1 == k && cnt2 == m) || (cnt1 == m && cnt2 == k))
					ans = min(ans, abs(p[i] - p[j]));
 
			}
		}
	}

	return ans;
 }
 
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
 
	cout << setprecision(3) << fixed;
 
	
	int n, m, k;
	cin >> n >> m >> k;
 
	vector<point> p(n);
 
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		p[i] = point(1.0 * x, 1.0 * y);
	}
 
	double ans = oo;
	ans = min(ans, solve(p, m, k));
	
	vector<point> PP;

	reverse(p.begin(), p.end());

	p.insert(p.begin(), p.back());
	p.pop_back();

	ans = min(ans, solve(p, m, k));
 	

	if(ans >= oo - 10.0)
		cout << -1 << endl;
	else
		cout << ans << endl;
	
 
	return 0;
}