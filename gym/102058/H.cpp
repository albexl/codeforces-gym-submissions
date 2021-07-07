#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v(n);
	for(auto &el : v) cin >> el;

	vector<vector<int>> dp(2, vector<int>(n, 1));
	for(int i = n - 2; i >= 0; --i)
	{
		if(v[i] <= v[i + 1])
			dp[0][i] = 1 + dp[0][i + 1];
		else
			dp[1][i] = 1 + dp[1][i + 1];
	}

	vector<pii> ans(n + 1, {-1, -1});
	int q, x; cin >> q;
	while(q--)
	{
		cin >> x;
		if(ans[x].first == -1)
		{
			int p = 0, cs = 0, cb = 0;
			while(p < n)
			{
				int np = max(dp[0][p], dp[1][p]);
				if(np < x && p + np != n)
					cb += x - np, np = x;
				++cs;
				p += np;
			}

			ans[x] = {cs, cb};
		}

		cout << ans[x].first << " " << ans[x].second << endl;
	}

	return 0;
}