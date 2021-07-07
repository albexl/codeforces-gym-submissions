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
 
	//freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	const int oo = 1e9;
	
	int t;
	cin >> t;

	while(t--){
		int n, m, ans = 0;
		cin >> n >> m;

		vector<vector<int>> g(n + 1, vector<int>(n + 1, oo));

		for(int i = 1; i <= n; i++)
			g[i][i] = 0;

		while(m--){
			int a, b;
			cin >> a >> b;
			g[a][b] = g[b][a] = 1;

			if(a == b)
				ans = 1;
		}

		for(int k = 1; k <= n; k++)
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				ans = max(ans, g[i][j]);

		cout << ans << endl;
	}

	return 0;
}