#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

bool ok(ll x, ll base, ll lower){
	vector<ll> num;
	while(x){
		ll rem = x % base;
		if(rem > 9)
			return false;
		num.push_back(rem);
		x /= base;
	}
	reverse(num.begin(), num.end());
	ll N = 0;
	for(int i = 0; i < (int)num.size(); i++)
		N = N * 10LL + num[i];
	return N >= lower;
}

const ll BASE = 1e6;

pair<ll, ll> get_rep(ll x){
	return {x / BASE, x % BASE};
}

ll get_base(ll x, ll y){
	ll lo = 100001, hi = y - 1;
	ll ans = -1, c_ans = -1, r_ans = -1;
	
	vector<ll> d;
	while(x > 0){
		d.push_back(x % 10);
		x /= 10;
	}
	
	reverse(d.begin(), d.end());
	
	pair<ll, ll> rep = get_rep(y);
	
	while(lo <= hi){
		ll mid = (lo + hi) >> 1LL;
		ll c = 0, r = 0;
		for(int i = 0; i < (int)d.size(); i++){
			r = r * mid;
			if(r > BASE)
				c++, r %= BASE;
			r = r + d[i];
			if(r > BASE)
				c++, r %= BASE;
		}
		if(c > rep.first || (c == rep.first && r >= rep.second)){
			ans = mid;
			c_ans = c;
			r_ans = r;
			hi = mid - 1;
		}
		else lo = mid + 1;
	}
	
	
	if(c_ans != rep.first || r_ans != rep.second)
		ans = -1;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	
	ll x, l;
	cin >> x >> l;
	
	ll ans = 0;
	for(ll b = 2; b <= 100000; b++)
		if(ok(x, b, l))
			ans = b;

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			for(int m = 0; m < 10; m++){
				for(int n = 0; n < 10; n++){
					ll y = 1000LL * i + 100LL * j + 10LL * m + 1LL * n;
					if(y >= l){
						ll cand = get_base(y, x);
						if(cand != -1)
							ans = max(ans, cand);
					}
				}
			}	
		}
	}
	
	cout << ans << endl;

	return 0;
}