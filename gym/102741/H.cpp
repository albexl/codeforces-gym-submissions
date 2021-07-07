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

const int mod = 1e9 + 7;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a.begin(), a.end());
	ll ans = 0;
	while(m--){
		int x;
		cin >> x;

		int pos = lower_bound(a.begin(), a.end(), x) - a.begin();
		
		ll cur = 2e9;

		for(int i = pos - 1; i <= pos + 1; i++)
			if(i >= 0 && i < n)
				cur = min(cur, abs((ll)a[i] - x));
		
		ans += cur * cur;
		ans %= mod;
	}

	cout << ans << endl;

	return 0;
}