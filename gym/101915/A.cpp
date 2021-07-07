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

ll digits(ll x){
	if(x == 0) return 1;
	ll ans = 0;
	while(x){
		x /= 10;
		ans++;
	}
	return ans;
}

ll nxt(ll x){
	ll d = digits(x);
	ll ans = 1;
	for(ll i = 0; i < d; i++)
		ans *= 10;
	return ans - 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		ll n, x;
		cin >> n >> x;
		
		ll s = x;

		while(true){
			ll d = digits(x), y = nxt(x), cur = (y - x + 1) * d;

			if(cur >= n){
				ll lo = x, hi = y, ans = -1;
				while(lo <= hi){
					ll mid = (lo + hi) >> 1ll;
					ll cnt = (mid - x + 1) * d;
					if(cnt >= n){
						ans = mid;
						hi = mid - 1;
					}
					else lo = mid + 1;
				}
				
				ll cnt = (ans - x + 1) * d;
				cout << (cnt == n ? ans - s + 1 : -1) << endl;
				
				break;
			}
			else{
				n -= cur;
				x = y + 1;
			}
		}
	}

	return 0;
}