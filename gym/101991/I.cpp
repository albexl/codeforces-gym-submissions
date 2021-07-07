#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("icecream.in", "r", stdin);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		map<int, vector<int>> m;

		vector<int> a(n), b(n);

		for(int i = 0; i < n; i++)
			cin >> a[i];

		for(int i = 0; i < n; i++)
			cin >> b[i];

		for(int i = 0; i < n; i++)
			m[a[i]].push_back(b[i]);

		vector<pii> v;

		int cnt = 0;
		for(auto &p : m){

			for(auto &x : p.second)
				v.push_back({x, p.first});

			int sz = p.second.size();

			if(cnt + sz >= k)
				break;
			cnt += sz;
		}

		sort(v.rbegin(), v.rend());

		int s1 = 0;
		ll s2 = 0;

		for(int i = 0; i < k; i++){
			s1 = max(s1, v[i].second);
			s2 += 1ll * v[i].first;
		}

		cout << s1 << " " << s2 << endl;
	}


	return 0;
}