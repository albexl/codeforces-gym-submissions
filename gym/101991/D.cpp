#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define double long double

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("dull.in", "r", stdin);

	int c;
	cin >> c;

	while(c--)
	{
		ll n, m, k;
		cin >> n >> m >> k;

		vector<pii> v(k);
		for(int i = 0, a, b; i < k; ++i)
			cin >> a >> b, v[i] = {a, b};
		v.emplace_back(n + 1, m);

		sort(v.begin(), v.end());
		ll odd = 0;

		int p = 0, p1 = 0;
		set<int> S;
		while(p1 <= k)
		{
			if(v[p1].first == v[p].first)
			{
				if(S.find(v[p1].second) == S.end())
					S.insert(v[p1].second);
				else
					S.erase(v[p1].second);
				++p1;
			}
			else
			{
				ll d = v[p1].first - v[p].first, l = 1, par = 0;
				for(auto &el : S)
				{
					odd += d * par * (el - l);

					par = 1 - par;
					l = el;
				}

//				cout << d << " " << l << " " << par << " " << p << " " << p1 << endl;
				odd += d * (m - l + 1) * par;

				p = p1;
			}
		}

		cout << odd << " " << n * m - odd << endl;
	}

	return 0;
}