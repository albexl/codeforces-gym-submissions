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

const int maxn = 10000 + 5;
const int maxt = 50;

int n, T;
int dp[maxn][maxt];
pii a[maxn];

int solve(int pos, int t){
	if(t == T)
		return 0;
	if(pos == n)
		return 0;
	if(dp[pos][t] != -1)
		return dp[pos][t];
	
	int ans = 0;
	ans = max(ans, solve(pos + 1, t));
	if(a[pos].first >= t)
		ans = max(ans, solve(pos + 1, t + 1) + a[pos].second);
	
	return dp[pos][t] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));

	cin >> n >> T;
	for(int i = 0; i < n; i++)
		cin >> a[i].second >> a[i].first;
	
	sort(a, a + n);
	memset(dp, -1, sizeof(dp));
	
	cout << solve(0, 0) << endl;

	return 0;
}