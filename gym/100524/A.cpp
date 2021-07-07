#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> tri;
typedef vector<vector<int>> graph;

ll dist(pii &a, pii &b)
{
	return (a.first - b.first) * (a.first - b.first) +
		   (a.second - b.second) * (a.second - b.second);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("astronomy.in", "r", stdin);
	freopen("astronomy.out", "w", stdout);

	int n;
	while(cin >> n && n)
	{
		vector<pii> v(n);
		for(ll i = 0, x, y; i < n; ++i)
		{
			cin >> x >> y;
			v[i] = {x, y};
		}

		int m; cin >> m;
		map<tri, int> M;
		vector<tri> W(m);
		vector<int> ans(m);

		for(int i = 1; i <= m; ++i)
		{
			ll a, b, c; cin >> a >> b >> c;
			W[i - 1] = {{a, b}, c};
			M[W[i - 1]] = i;
		}

		pii z = {0, 0};
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < i; ++j)
			{
				ll a = dist(z, v[i]);
				ll b = dist(z, v[j]);
				ll c = dist(v[i], v[j]);

				int p = M[{{a, b}, c}];
				if(p)
					++ans[p - 1];

				if(a != b)
				{
					p = M[{{b, a}, c}];
					if(p)
						++ans[p - 1];
				}
			}

		for(int i = 0; i < m; ++i)
			cout << ans[M[W[i]] - 1] << endl;
	}

	return 0;
}