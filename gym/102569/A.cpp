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
	
	int n, q;
	cin >> n;
	
	vector<ll> v(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];
	
	vector<int> dp(n + 1), acum(n + 1);
	
	for(int i = n, val = 1; i >= 1; i--, val = 1 - val)
		dp[i] = val;
	
	for(int i = 1; i <= n; i++)
		acum[i] = acum[i - 1] + dp[i];
	
	ll hash = 0;
	for(int i = n, mul = 1; i >= 1; i--, mul *= -1)
		hash += 1ll * mul * v[i];
	
	cin >> q;
	while(q--){
		int l, r;
		ll val;
		
		cin >> l >> r >> val;
		
		int pos = acum[r] - acum[l - 1];
		int neg = r - l + 1 - pos;
		
		hash += 1ll * pos * val;
		hash -= 1ll * neg * val;
		
		cout << hash << endl;
		
	}
	

	return 0;
}