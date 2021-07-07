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



int main()
{
	#ifdef DGC
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> val(n);
	for (auto &i : val)
		cin >> i;

	vector<int> go(n), p(n, -1);
	iota(go.begin(), go.end(), 0);

	function<void(int)> solve = [&](int u)
	{
		int v = go[u];
		if (p[v] != -1)
		{
			solve(v);
			val[u] = min(val[u], val[v]);
			go[u] = go[v];
		}
	};

	char op;
	for (int u, v; m--; )
	{
		cin >> op >> u;
		if (op == '?')
		{
			--u;
			solve(u);
			cout << val[u] << "\n";
		}
		else
		{
			cin >> v;
			--u, --v;

			go[v] = go[u];
			val[v] = min(val[v], val[u]);
			p[v] = u;
		}
	}

	return 0;
}