#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("coffee.in", "r", stdin);

	int c;
	cin >> c;

	for(; c > 0; --c)
	{
		int n, q;
		cin >> n >> q;

		map<string, int> M;
		vector<vector<int>> v(n);

		for(int i = 0; i < n; ++i)
		{
			string s; cin >> s;
			M[s] = i;

			for(int j = 0, a; j < 3; ++j)
				cin >> a, v[i].emplace_back(a);
		}

		int fee = 100 / q;
		string s, t, ty;
		for(; q > 0; --q)
		{
			cin >> s >> ty >> t;

			int p = M[t], w;

			if(ty == "small") w = 0;
			else if(ty == "medium") w = 1;
			else w = 2;

			int cost = fee + v[p][w];
			if(cost % 5 == 1) --cost;
			if(cost % 5 == 4) ++cost;

			cout << s << " " << cost << endl;
		}
	}

	return 0;
}