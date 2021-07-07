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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}





int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	const ll maxn = 1e9;

	vector<ll> lucky;
	queue<ll> Q;
	Q.push(3);
	Q.push(8);

	while(!Q.empty()){
		ll x = Q.front();Q.pop();
		// cerr << x << endl;
		lucky.push_back(x);

		ll y = x * 10 + 3;
		if(y <= maxn)
			Q.push(y);

		y = x * 10 + 8;
		if(y <= maxn)
			Q.push(y);
	}

	ll ans = 0;
	ll l, r;
	cin >> l >> r;

	int p = 0;
	for(ll i = l; i <= r; i++){
		while(lucky[p] < i)
			p++;
		ans += lucky[p];
	}

	cout << ans << endl;
	
	return 0;
}