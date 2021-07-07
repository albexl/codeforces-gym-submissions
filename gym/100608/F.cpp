#include <bits/stdc++.h>
using namespace std;

//#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> graph;

vector<int> col;
int dfs(int u, int p, graph &g)
{
	if(col[u]) return u;

	int y = -1;
	for(auto &v : g[u])
		if(v != p)
		{
			int x = dfs(v, u, g);
			if(x != -1)
			{
				if(y == -1) y = x;
				else return u;
			}
		}
	return y;
}

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);

	int n;
	cin >> n;

	graph g(n + 1);
	for(int i = 1, x, y; i < n; ++i)
		cin >> x >> y, g[x].push_back(y), g[y].push_back(x);

	auto print = [](int x, int y)
	{
		cout << x << " " << y << endl;
		cout.flush();
	};

	col = vector<int>(n + 1);
	col[1] = 1;
	print(1, 1);

	auto min_c = [&](int u)
	{
		vector<int> c(4 + 1);
		for(auto &v : g[u])
			++c[col[v]];
		for(int i = 1; i <= 4; ++i)	if(!c[i]) return i;
		return 0;
	};

	do
	{
		int x, c; cin >> x >> c;

		if(x == -1 && c == -1) break;

		int nxt = dfs(x, -1, g);
		col[x] = c;

		if(col[nxt])
		{
			bool ok = false;
			for(int i = 1; i <= n && !ok; ++i)
				if(!col[i])
					for(auto &e : g[i])
						if(col[e])
							ok = true, nxt = i;
		}

		col[nxt] = min_c(nxt);
		print(nxt, col[nxt]);

	}while(true);

	return 0;
}