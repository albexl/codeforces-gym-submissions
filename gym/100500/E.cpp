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

const int maxn = 55;

int dp[maxn][maxn];
int solve(int n, int k){
	
	if(k > n)
		return dp[n][k] = 0;
	
	if(dp[n][k] != -1)
		return dp[n][k];
	
	set<int> s;
	for(int i = 1; i + k - 1 <= n; i++)
		s.insert(solve(i - 1, k) ^ solve(n - (i + k) + 1, k));
	
	int mx = 0;
	while(s.find(mx) != s.end())
		mx++;
	
	return dp[n][k] = mx;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	memset(dp, -1, sizeof(dp));
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		cout << "Case " << cases << ": ";
		int n, k;
		cin >> n >> k;
		
		int ans = solve(n, k);
		if(ans == 0)
			cout << "Losing" << endl;
		else
			cout << "Winning" << endl;
		
	}

	return 0;
}