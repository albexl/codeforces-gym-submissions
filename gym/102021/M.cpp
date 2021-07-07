#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

vector<int> ans;

struct disjoint_set
{
	vector<int> p;
	vector<set<int>> S;

	disjoint_set(int n) : p(n, -1), S(n) { }

	int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

	void merge(int x, int y, int d)
	{
		if((x = root(x)) == (y = root(y))) return;

		if(S[x].size() < S[y].size()) swap(x, y);

		for(auto &el : S[y])
		{
			if(S[x].find(el) != S[x].end())
				ans[el] = d;
			else
				S[x].insert(el);
		}

		p[x] += p[y];
		p[y] = x;
	}
};

int n, m;

inline int conv(int x, int y)
{
	return x * m + y;
}

inline pii iconv(int x)
{
	return {x / m, x % m};
}

bool inside(int x, int y)
{
	return 0 <= x && x < n && 0 <= y && y < m;
}


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> n >> m >> q;
	ans = vector<int>(q);

	vector<pii> ord(n * m);
	vector<vector<int>> v(n, vector<int>(m));
	for(int i = 0, idx = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
		{
			cin >> v[i][j];
			ord[idx] = {v[i][j], idx};
			++idx;
		}

	disjoint_set ds(n * m);
	for(int i = 0, a, b, c, d; i < q; ++i)
	{
		cin >> a >> b >> c >> d;
		--a, --b, --c, --d;

		if(a == c && b == d)
			ans[i] = v[a][b];
		else
		{
			ds.S[conv(a, b)].insert(i);
			ds.S[conv(c, d)].insert(i);
		}
	}

	sort(ord.begin(), ord.end());

	for(auto &el : ord)
	{
		pii p = iconv(el.second);
		for(int k = 0; k < 4; ++k)
		{
			pii np = {p.first + dx[k], p.second + dy[k]};
			if(!inside(np.first, np.second)) continue;

			if(v[np.first][np.second] <= el.first)
				ds.merge(el.second, conv(np.first, np.second), el.first);
		}
	}
	for(auto &a : ans)
		cout << a << endl;

	return 0;
}