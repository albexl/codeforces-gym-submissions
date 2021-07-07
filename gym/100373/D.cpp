#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, s, m;
	cin >> n >> s >> m;

	vector<int> v(4);
	for(int i = 0, x; i < m; ++i)
		cin >> x, ++v[x];

	int ans = 0;
	while(v[1] + 2 * v[2] + 3 * v[3] >= s)
	{
		int acc = 0;

		int t3 = min(v[3], (s - acc) / 3);
		acc += 3 * t3, v[3] -= t3;

		if(acc == s) { ++ans; continue; }

		if(s - acc == 1)
		{
			if(v[1]) { --v[1]; ++ans; continue; }
			if(t3 && v[2] >= 2) { v[2] -= 2; ++v[3]; ++ans; continue; }
			if(v[2]) { --v[2]; ++ans; continue; }
			if(v[3]) { --v[3]; ++ans; continue; }
		}
		else if(s - acc == 2)
		{
			if(v[2]) { --v[2]; ++ans; continue; }
			if(v[1] >= 2) { v[1] -= 2; ++ans; continue; }
			if(v[3]) { --v[3]; ++ans; continue; }
		}
		else
		{
			int t2 = min(v[2], (s - acc) / 2);
			acc += 2 * t2, v[2] -= t2;

			if(acc == s) { ++ans; continue; }
			if(s - acc == 1)
			{
				if(v[1]) { --v[1]; ++ans; continue; }
				if(v[2]) { --v[2]; ++ans; continue; }
			}
			else
			{
				int t1 = min(v[1], (s - acc) / 1);
				acc += 1 * t1, v[1] -= t1;

				if(acc == s) { ++ans; continue; }
			}
		}
	}

	cout << min(ans, n) << endl;

	return 0;
}