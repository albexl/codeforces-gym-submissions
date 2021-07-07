#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<pii>> g(n);
	vector<int> indeg(n), dp(n);

	for(int i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back({b, c});
		indeg[b]++;
	}

	vector<int> order;
	queue<int> Q;

	for(int i = 0; i < n; i++)
		if(!indeg[i])
			Q.push(i);

	while(!Q.empty()){
		int x = Q.front();Q.pop();
		order.push_back(x);
		for(auto &y : g[x]){
			indeg[y.first]--;
			if(!indeg[y.first]){
				Q.push(y.first);
			}
		}
	}

	int ans = 0;

	for(int i = n - 1; i >= 0; i--){
		int x = order[i];
		dp[x] = 0;
		for(auto &e : g[x]){
			int cost = dp[e.first] + e.second;
			dp[x] = max(dp[x], cost);
		}
		ans = max(ans, dp[x]);
	}

	cout << ans << endl;


	return 0;
}