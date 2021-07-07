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

int doms[20][2];
ll dp[1 << 18][18][2];
ll f[20];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	const ll mod = 1e9 + 7;
	
	f[0] = 1ll;
	for(int i = 1; i < 20; i++)
		f[i] = (f[i - 1] * 1ll * i) % mod;
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		for(int i = 0; i < n; i++)
			cin >> doms[i][0] >> doms[i][1];
		
		bool all_same = true;
		
		for(int i = 1; i < n; i++){
			if(doms[0][0] == doms[i][0] && doms[0][1] == doms[i][1])
				continue;
			if(doms[0][0] == doms[i][1] && doms[0][1] == doms[i][0])
				continue;
			all_same = false;
		}
			
		
		if(all_same){
			
			cout << f[n] << endl;
			continue;
		}
		
		for(int i = 0; i < (1 << n); i++)
			for(int j = 0; j < n; j++)
				for(int k = 0; k < 2; k++)
					dp[i][j][k] = 0;
		
		for(int i = 0; i < n; i++)
			dp[1 << i][i][0] = dp[1 << i][i][1] = 1;
		
		for(int i = 1; i < (1 << n); i++){
			if(__builtin_popcount(i) == 1)
				continue;
			
			for(int j = 0; j < n; j++){
				if(i & (1 << j)){
					
					int prv = i ^ (1 << j);
					
					for(int k = 0; k < n; k++){
						
						if(prv & (1 << k)){
							if(doms[k][0] == doms[j][1]){
								dp[i][j][0] += dp[prv][k][0];
								dp[i][j][0] %= mod;	
							}
							else if(doms[k][1] == doms[j][1]){
								dp[i][j][0] += dp[prv][k][1];
								dp[i][j][0] %= mod;
							}
							
							if(doms[k][0] == doms[j][0]){
								dp[i][j][1] += dp[prv][k][0];
								dp[i][j][1] %= mod;	
							}
							else if(doms[k][1] == doms[j][0]){
								dp[i][j][1] += dp[prv][k][1];
								dp[i][j][1] %= mod;
							}
						}
					}
				}
			}
		}
		
		ll ans = 0;
		
		for(int i = 0; i < n; i++){
			ans += dp[(1 << n) - 1][i][0];
			ans %= mod;
			
			if(doms[i][0] != doms[i][1]){
				ans += dp[(1 << n) - 1][i][1];
				ans %= mod;
			}
		}
		
		cout << ans << endl;
	}

	return 0;
}