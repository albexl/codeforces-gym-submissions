#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ll> point;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define point pii
#define real() first
#define imag() second

struct fraction{

	ll num, den;
	fraction(ll _num, ll _den) : num(_num), den(_den){
		ll g = __gcd(abs(num), abs(den));
		num /= g;
		den /= g;

		if(num < 0 && den < 0)
			num *= -1, den *= -1;
		else if(den < 0 || num < 0)
			num = -abs(num), den = abs(den);
	}

	bool operator<(const fraction &f) const{
		return make_pair(num, den) < make_pair(f.num, f.den);
	}

};

ll cross(point a, point b) { return a.first * b.second - a.second * b.first; }

ll area2(point &a, point &b, point &c) { return cross({b.first - a.first, b.second - a.second}, {c.first - a.first, c.second - a.second}); }


int getR(point &p1, point &p2, ll L, ll R, vector<point> &p, int my_pos){
	
	int lo = my_pos + 1;
	int hi = (int)p.size() - 1;

	int far = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(abs(area2(p1, p2, p[mid])) <= R){
			far = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}

	if(far == -1)
		return 0;

	lo = my_pos + 1, hi = (int)p.size() - 1;
	int close = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(abs(area2(p1, p2, p[mid])) >= L){
			close = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	if(close == -1)
		return 0;

	return far - close + 1;
}

int getL(point &p1, point &p2, ll L, ll R, vector<point> &p, int my_pos){
	
	int lo = 0;
	int hi = my_pos - 1;

	int far = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(abs(area2(p1, p2, p[mid])) <= R){
			far = mid;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}

	if(far == -1)
		return 0;

	lo = 0, hi = my_pos - 1;
	int close = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(abs(area2(p1, p2, p[mid])) >= L){
			close = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}

	if(close == -1)
		return 0;

	return close - far + 1;
}

int get(point &p1, point &p2, ll L, ll R, vector<point> &p){

	int my_pos = lower_bound(p.begin(), p.end(), p2) - p.begin();

	int s1 = getR(p1, p2, L, R, p, my_pos);
	int s2 = getL(p1, p2, L, R, p, my_pos);
	
	return s1 + s2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	freopen("points.in", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	while(t--){

		int n;
		ll L, R;
		cin >> n >> L >> R;

		L *= 2;
		R *= 2;

		map<pair<fraction, fraction>, vector<point>> mp;
		map<ll, vector<point>> mpx, mpy;

		vector<point> v(n);
		for(int i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			v[i] = point(x, y);
		}

		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){

				if(v[i].real() == v[j].real()){
					mpx[v[i].real()].push_back(v[j]);
					mpx[v[i].real()].push_back(v[i]);
				}
				else if(v[i].imag() == v[j].imag()){
					mpy[v[i].imag()].push_back(v[j]);
					mpy[v[i].imag()].push_back(v[i]);
				}
				else{
					ll a = v[i].real() - v[j].real();
					ll b = v[i].imag() - v[j].imag();

					fraction slope(a, b);

					ll c = b * v[i].imag() - a * v[i].real();
					ll d = b;

					fraction inter(c, d);

					mp[{slope, inter}].push_back(v[i]);
					mp[{slope, inter}].push_back(v[j]);

				}
			}
		}

		for(auto &el : mp){
			sort(el.second.begin(), el.second.end());
			el.second.resize(unique(el.second.begin(), el.second.end()) - el.second.begin());
		}

		for(auto &el : mpx){
			sort(el.second.begin(), el.second.end());
			el.second.resize(unique(el.second.begin(), el.second.end()) - el.second.begin());
		}

		for(auto &el : mpy){
			sort(el.second.begin(), el.second.end());
			el.second.resize(unique(el.second.begin(), el.second.end()) - el.second.begin());
		}

		ll ans = 0;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == j)
					continue;
				
				if(v[i].real() == v[j].real()){

					auto &vec = mpy[v[j].imag()];
					ans += get(v[i], v[j], L, R, vec);
				}
				else if(v[i].imag() == v[j].imag()){
					auto &vec = mpx[v[j].real()];
					ans += get(v[i], v[j], L, R, vec);
				}
				else{
					ll a = v[i].real() - v[j].real();
					ll b = v[i].imag() - v[j].imag();

					fraction slope(a, b);

					ll c = b * v[i].imag() - a * v[i].real();
					ll d = b;

					fraction inter(c, d);

					ll f = -b;
					ll g = a;

					fraction opp_slope(f, g);

					ll h = g * v[j].imag() - f * v[j].real();
					ll k = g;

					fraction opp_inter(h, k);

					if(mp.find({opp_slope, opp_inter}) == mp.end())
						continue;

					auto &vec = mp[{opp_slope, opp_inter}];
					ans += get(v[i], v[j], L, R, vec);
				}
			}
		}

		cout << ans / 2 << endl;
	}


	return 0;
			
}