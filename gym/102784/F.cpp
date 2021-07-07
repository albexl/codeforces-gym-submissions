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
// typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// template<typename T>
// static T randint(T lo, T hi){
// 	return uniform_int_distribution<T>(lo, hi)(rng);
// }



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	ll a, b;
	cin >> a >> b;

	ll ans = 0, num = 0;
	for(ll i = 62; i >= 0; i--){
		ll b1 = (a & (1ll << i)) != 0;
		if(b1)
			ans += (1ll << i);
		else{
			ll n_num = num | (1ll << i);
			if(n_num <= b){
				num += (1ll << i);
				ans += (1ll << i);
			}
		}
	}

	cout << ans << endl;

	return 0;
}