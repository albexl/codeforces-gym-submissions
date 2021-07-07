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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	ll ans = 0;

	map<string, int> mp;
	map<int, int> g;

	vector<string> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i];
		mp[v[i]]++;
		g[v[i][0] - 'A']++;
	}

	for(int i = 0; i < n; i++){
		ll total = g[v[i][0] - 'A'] - mp[v[i]];
		ans += total;
	}

	cout << ans << endl;


	return 0;
}