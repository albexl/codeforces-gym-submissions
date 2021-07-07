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

ll solve(ll n, ll m){
	m++;
	
	ll c1 = (m + 1) / 2;
	ll c2 = m - c1;
	
	ll s1 = (n + 1) / 2;
	ll s2 = n - s1;
	
	return min(s1 * c1 + s2 * c2, s1 * c2 + s2 * c1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	
	int t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
	
		ll s1 = solve(n, m);
		ll s2 = solve(m, n);
	
		cout << min(s1, s2) << endl;
	}
	
	return 0;
}