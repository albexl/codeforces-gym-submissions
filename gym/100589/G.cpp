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

int n, k;
ll dp[15][1 << 15];

ll solve(int last, int mask){
	if(mask == (1 << n) - 1)
		return 1ll;
	
	if(dp[last][mask] != -1)
		return dp[last][mask];
	
	ll ans = 0;
	
	for(int j = 0; j < n; j++){
		if(mask & (1 << j))
			continue;
		if(abs(j - last) > k)
			continue;
		ans += solve(j, mask | (1 << j));
	}
	
	return dp[last][mask] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	int t;
	cin >> t;
	
	while(t--){
		cin >> n >> k;
		
		memset(dp, -1, sizeof(dp));
		ll ans = 0;
		for(int i = 0; i < n; i++)
			ans += solve(i, 1 << i);
		
		cout << ans << endl;
	}
	

	return 0;
}