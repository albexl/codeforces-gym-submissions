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
	
	ll p, n;
	cin >> p >> n;
	
	vector<bool> flags(p);
	
	for(ll i = 0; i <= min(2 * p, n); i++){
		ll x = i * (i + 1) >> 1ll;
		flags[x % p] = true;
	}
	
	int ans = 0;
	for(int i = 0; i < p; i++)
		ans += flags[i];
	
	cout << ans << endl;
	
	return 0;
}