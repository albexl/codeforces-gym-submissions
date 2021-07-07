#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<vector<ll>> g(n, vector<ll>(n));
	
	for(int i = 0; i < n * (n - 1) / 2; i++){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		a--, b--;
		g[a][b] = c;
		g[b][a] = c;
	}
	
	ll ans = 0;
	
	for(int i = 0; i < n; i++){
		vector<ll> v;
		for(int j = 0; j < n; j++)
			if(i != j)
				v.push_back(g[i][j]);
		
		sort(v.begin(), v.end());
		for(int i = 1; i < v.size(); i += 2)
			ans += v[i];
	}
	
	cout << ans << endl;

	return 0;
}