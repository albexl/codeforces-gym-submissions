#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715;
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second

int mov[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int main()
{
	#ifdef DGC
		//freopen("a.in", "r", stdin);
		//freopen("b.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (auto &i : a) cin >> i;

		vector<vector<int>> fire(n, vector<int>(m, 1<<30));

		queue<pair<int, int>> q;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == 'F')
				{
					fire[i][j] = 0;
					q.push({ i, j });
				}

		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int nx = x + mov[k][0];
				int ny = y + mov[k][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && fire[nx][ny] == 1<<30)
				{
					fire[nx][ny] = fire[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}

		vector<vector<int>> walk(n, vector<int>(m, 1<<30));

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == 'S' && fire[i][j] > 0)
				{
					walk[i][j] = 0;
					q.push({ i, j });
				}

		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();

			for (int k = 0; k < 4; ++k)
			{
				int nx = x + mov[k][0];
				int ny = y + mov[k][1];
				if (nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] != '#' && walk[nx][ny] == 1<<30 && walk[x][y] + 1 < fire[nx][ny])
				{
					walk[nx][ny] = walk[x][y] + 1;
					q.push({ nx, ny });
				}
			}
		}

		bool ok = false;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j] == 'E' && walk[i][j] != 1<<30)
					ok = true;

		cout << "NY"[ok] << "\n";
	}

	return 0;
}