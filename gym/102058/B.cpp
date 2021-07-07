#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int n, m;
	cin >> n >> m;

	vector<set<int>> g(n);

	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		a--, b--;
		g[a].insert(b);
		g[b].insert(a);
	}


	set<int> active;

	for(int i = 0; i < n; i++)
		if(g[i].size() == 2)
			active.insert(i);

	while(active.size()){

		int u = *(active.begin());
		active.erase(u);

		auto it = g[u].begin();

		int v1 = *it;
		it++;

		int v2 = *it;

		g[v1].erase(u);
		g[v2].erase(u);

		g[v1].insert(v2);
		g[v2].insert(v1);

		if(g[v1].size() == 2)
			active.insert(v1);
		else
			active.erase(v1);


		if(g[v2].size() == 2)
			active.insert(v2);
		else
			active.erase(v2);

		g[u].clear();

	}

	int cnt = 0;
	bool ok = true;

	for(int i = 0; i < n; i++){
		cnt += g[i].size();

		if(g[i].size() > 1)
			ok = false;

		if(g[i].size() == 1){
			int x = *(g[i].begin());
			if(g[x].find(i) == g[x].end())
				ok = false;

		}
	}

	if(cnt != 2)
		ok = false;

	cout << (ok ? "Yes" : "No") << endl;


	return 0;
}