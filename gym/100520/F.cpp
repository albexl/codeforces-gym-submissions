#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("flights.in", "r", stdin);
	freopen("flights.out", "w", stdout);

	int n, m;
	while(cin >> n >> m && (n + m)){

		vector<pair<int, pii>> edges(m);
		vector<int> sol(m);
		map<pii, int> M;

		for(int i = 0, a, b; i < m; i++){
			cin >> a >> b;
			edges[i] = {i, {a, b}};
			M[{min(a, b), max(a, b)}] = i;
		}

		int pos = 1;

		vector<pii> degree(n);

		for(int i = 0; i < n; i++)
			degree[i] = {0, i + 1};

		for(auto &e : edges){
			if(e.second.second != 1 && e.second.first != 1){
				degree[e.second.second - 1].first += pos;
				degree[e.second.first - 1].first += pos;
				sol[e.first] = pos++;
			}
		}

		sort(degree.begin(), degree.end());
		for(int i = 0; i < n; i++){
			if(degree[i].second == 1)
				continue;
			int idx = M[{1, degree[i].second}];
			sol[idx] = pos++;
		}

		cout << "Yes" << endl;
		for(int i = 0; i < m; i++)
			cout << sol[i] << " \n"[i + 1 == m];

	}



	return 0;
}