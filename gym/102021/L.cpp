#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int dx[] = {-1, -1, -1, 0, 0, 0, +1, +1, +1};
int dy[] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	n += 2, m += 2;
	vector<vector<int>> v(n, vector<int>(m));

	for(auto &ve : v)
		for(auto &e : ve)
			cin >> e;

	vector<vector<bool>> mk(n, vector<bool>(m));
	for(int i = 0; i + 2 < n; ++i)
		for(int j = 0; j + 2 < m; ++j)
		{
			if(v[i][j] < 0 || v[i][j] > 1)
			{
				cout << "impossible" << endl;
				return 0;
			}

			if(v[i][j] == 1)
			{
				mk[i + 1][j + 1] = true;
				for(int k = 0; k < 9; ++k)
					--v[i + 1 + dx[k]][j + 1 + dy[k]];
			}
		}

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(v[i][j])
			{
				cout << "impossible" << endl;
				return 0;
			}

	for(int i = 1; i + 1 < n; ++i)
		for(int j = 1; j + 1 < m; ++j)
		{
			cout << (mk[i][j] ? 'X' : '.');
			if(j + 2 == m) cout << endl;
		}

	return 0;
}