#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> point;
#define F first
#define S second

const ll inf = numeric_limits<ll>::max();

struct query
{
	int a, b, k, t, id;
	ll ans;
};

void solve(int n, vector<vector<ll>> dp, vector<pair<int, int>> temp, vector<query> &q, int T)
{
	sort(temp.begin(), temp.end());
	auto ctemp = temp;
	temp.clear();

	map<int, int> mp;
	for (auto i : ctemp)
		mp[i.F] = i.S;

	for (auto i : mp)
		temp.push_back(i);

	vector<int> who(temp.size());
	for (auto &i : temp)
		who[&i-&temp[0]] = i.S;

	vector<vector<query*>> g(n);
	for (auto &i : q)
		if (i.t == T)
		{
			i.k = min(i.k, (int)temp.size());
			--i.k;
			g[who[i.k]].push_back(&i);
		}

	for (auto it : ctemp)
	{
		int k = it.S;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dp[i][k] != inf && dp[k][j] != inf && dp[i][k] + dp[k][j] < dp[i][j])
				{
					dp[i][j] = dp[i][k] + dp[k][j];
				}

		for (auto x : g[k])
		{
			x->ans = dp[x->a][x->b];
			if (x->ans == inf)
				x->ans = -1;
		}
	}
}

int main()
{
	#ifdef DGC
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> temp(n);
	for (auto &i : temp)
		cin >> i.F, i.S = &i-&temp[0];

	vector<vector<ll>> dp(n, vector<ll>(n, inf));
	for (int i = 0, u, v, w; i < m; ++i)
	{
		cin >> u >> v >> w;
		--u, --v;
		dp[u][v] = min(dp[u][v], (ll)w);
		swap(u, v);
		dp[u][v] = min(dp[u][v], (ll)w);
	}

	int Q;
	cin >> Q;
	vector<query> q(Q);
	for (auto &i : q)
	{
		cin >> i.a >> i.b >> i.k >> i.t;
		--i.a, --i.b;
		i.id = &i-&q[0];
	}

	solve(n, dp, temp, q, 0);
	for (auto &i : temp) i.F *= -1;
	solve(n, dp, temp, q, 1);

	vector<ll> ans(Q);
	for (auto i : q)
		ans[i.id] = i.ans;

	for (auto &i : ans)
		cout << i << "\n";

	return 0;
}