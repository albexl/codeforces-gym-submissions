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

const int maxn = 1000 + 5, oo = 2e9;

int dp[maxn][105][105], t[3], n, v[maxn];

int solve(int pos, int t1, int t2){
	
	//cout << pos << " " << t1 << " " << t2 << endl;
	
	if(pos == n + 1)
		return 0;
		
	if(dp[pos][t1][t2] != -1)
		return dp[pos][t1][t2];
	
	int ans = oo;
	int diff = v[pos] - v[pos - 1];
	
	int tt1 = max(0, t1 - diff);
	int tt2 = max(0, t2 - diff);
	
	ans = min(ans, 1 + solve(pos + 1, tt1, tt2));
	
	if(tt1 == 0 && t[0] != oo)
		ans = min(ans, solve(pos + 1, t[0], tt2));
	if(tt2 == 0 && t[1] != oo)
		ans = min(ans, solve(pos + 1, tt1, t[1]));
	return dp[pos][t1][t2] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		
		cin >> n;
		
		for(int i = 1; i <= n; i++)
			cin >> v[i];
		
		sort(v, v + n + 1);
		
		t[0] = t[1] = oo;
		
		int k;
		cin >> k;
		
		for(int i = 0; i < k; i++)
			cin >> t[i];
		
		memset(dp, -1, sizeof(dp));
		cout << "Mission #" << cases << ": " << solve(1, 0, 0) << endl << endl;
	}
	
	return 0;
}