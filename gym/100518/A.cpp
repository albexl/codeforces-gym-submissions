#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<vector<pii>> graph;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("approximate.in", "r", stdin);
	freopen("approximate.out", "w", stdout);

	ll n, r;
	while(cin >> n >> r && n + r)
	{
		vector<ll> x(n);
		vector<ll> y(n);

		for(int i = 0; i < n; ++i)
			cin >> x[i] >> y[i];

		sort(x.begin(), x.end());
		sort(y.begin(), y.end());

		cout << (x.back() - x[0] + r + r) * (y.back() - y[0] + r + r)  << endl;
	}

	return 0;
}