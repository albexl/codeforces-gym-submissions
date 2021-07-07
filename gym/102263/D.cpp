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
	
	int n, m;
	cin >> n >> m;
	
	vector<ll> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	set<ll> rems;
	
	ll g = 0;
	for(int i = 0; i < m; i++){
		ll x;
		cin >> x;
		g = __gcd(g, x);
	}
	
	for(int i = 0; i < n; i++)
		rems.insert(v[i] % g);
	
	if(rems.size() == 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	

	return 0;
}