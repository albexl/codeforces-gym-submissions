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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	const ll mod = 1e9 + 7;
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		vector<ll> v(n + 1), L(n + 2, 1), R(n + 2, 1);
		
		for(int i = 1; i <= n; i++)
			cin >> v[i];
		
		for(int i = 1; i <= n; i++)
			L[i] = (L[i - 1] * v[i]) % mod;
		for(int i = n; i >= 1; i--)
			R[i] = (R[i + 1] * v[i]) % mod;
		
		ll ans = 0;
		
		for(int i = 1; i <= n; i++){
			ll x = (v[i] + mod - 1) % mod;
			x = (x * L[i - 1]) % mod;
			x = (x * R[i + 1]) % mod;
			ans = (ans + x) % mod;
		}
		
		cout << ans << endl;
		
	}

	return 0;
}