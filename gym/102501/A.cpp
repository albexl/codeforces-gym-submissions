#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef complex<int> point;
#define F first
#define S second

const int oo = 1e9;

int sqr(int x){
	return x * x;
}

int dist(int xo, int yo, int xi, int yi){
	return round(ceil( sqrt( sqr( xo - xi ) + sqr( yo - yi ) ) ));
}

int main()
{
	#ifdef NeverBeRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int xs, ys, xe, ye;
	cin >> xs >> ys >> xe >> ye;


	int b, c0;
	cin >> b >> c0;

	int t;
	cin >> t;

	vector<int> c(t + 5);
	c[0] = c0;
	for(int i = 1; i <= t; i++)
		cin >> c[i];

	int n;
	cin >> n;

	vector<int> x(n + 5), y(n + 5);

	vector<vector<pair<int, pii>>> g(n + 5);
	x[n] = xs, y[n] = ys;
	x[n + 1] = xe, y[n + 1] = ye;

	vector<pair<int, pii>> edges;

	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
		int k;
		cin >> k;

		while(k--){
			int v, p;
			cin >> v >> p;
			edges.push_back({p, {i, v}});
		}

		//home
		int d = dist(x[i], y[i], x[n], y[n]);
		int w = d * c[0];
		g[n].push_back({i, {d, w}});

		//dest
		d = dist(x[i], y[i], x[n + 1], y[n + 1]);
		w = d * c[0];
		g[i].push_back({n + 1, {d, w}});
	}

	//home - dest
	int d = dist(x[n], y[n], x[n + 1], y[n + 1]);
	int w = d * c[0];
	g[n].push_back({n + 1, {d, w}});

	for(auto &e : edges){
		int p = e.first;
		int u = e.second.first;
		int v = e.second.second;

		int d = dist(x[u], y[u], x[v], y[v]);
		int w = c[p] * d;
		g[u].push_back({v, {d, w}});
		g[v].push_back({u, {d, w}});
	}

	vector<vector<int>> dp(n + 5, vector<int>(b + 5, oo));
	dp[n][0] = 0;

	for(int k = 0; k <= b; k++){
		for(int u = 0; u <= n + 1; u++){
			for(auto &e : g[u]){
				int v = e.first;
				int d = e.second.first;
				int w = e.second.second;

				if(k + d <= b)
					dp[v][k + d] = min(dp[v][k + d], dp[u][k] + w);

			}
		}
	}

	int ans = oo;
	for(int k = 0; k <= b; k++)
		ans = min(ans, dp[n + 1][k]);

	if(ans == oo)
		ans = -1;

	cout << ans << "\n";

	return 0;
}