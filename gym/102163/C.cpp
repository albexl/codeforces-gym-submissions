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

const ll mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll> v(n + 1), dp(n + 1), lis(n + 1);
		for(int i = 1; i <= n; i++) cin >> v[i];
		
		for(int i = 1; i <= n; i++){
			dp[i] = lis[i] = 1;
			for(int j = 1; j < i; j++){
				if(v[i] > v[j]){
					if(lis[i] < lis[j] + 1)
						dp[i] = dp[j], lis[i] = lis[j] + 1;
					else if(lis[i] == lis[j] + 1)
						dp[i] += dp[j], dp[i] %= mod;
				}
			}
		}
		
		ll opt = 0;
		for(int i = 1; i <= n; i++)
			if(lis[i] > opt)
				opt = lis[i];
		ll ans = 0;
		for(int i = 1; i <= n; i++)
			if(lis[i] == opt)
				ans += dp[i], ans %= mod;
		
		cout << opt << " " << ans << endl;
		
	}

	return 0;
}