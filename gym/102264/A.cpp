#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("dislodging_logs_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	const int oo = 1e9;

	int t;
	cin >> t;

	for(int cases = 1; cases <= t; cases++){
		
		int n, m;
		cin >> n >> m;

		vector<pair<pii, int>> edges(m);
		vector<vector<int>> g(n + 1, vector<int>(n + 1, oo));
		for(int i = 1; i <= n; i++)
			g[i][i] = 0;

		for(int i = 0; i < m; i++){
			int a, b, c;
			cin >> a >> b >> c;
			edges[i] = {{a, b}, c};
			g[a][b] = g[b][a] = c;
		}

		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

		bool ok = true;
		for(auto &e : edges){
			int a = e.first.first;
			int b = e.first.second;
			int c = e.second;

			if(g[a][b] != c)
				ok = false;
		}

		cout << "Case #" << cases << ": ";

		if(!ok){
			cout << "Impossible" << endl;
		}
		else{
			cout << m << endl;
			for(auto &e : edges){
				int a = e.first.first;
				int b = e.first.second;
				int c = e.second;

				cout << a << " " << b << " " << c << endl;
			}
		}
	}

	return 0;
}