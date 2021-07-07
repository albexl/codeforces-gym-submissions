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
	
	const ll mod = 1e9 + 7;
	const ll b = 31;
	
	int n;
	cin >> n;
	
	vector<ll> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	
	string s = "";
	
	s += (char)(v[0]);
	
	for(int i = 1; i < n; i++){
		
		ll x = v[i - 1] * b % mod;
		ll y = (v[i] - x + mod) % mod;
		
		s += (char)(y);
		
	}
	
	cout << s << endl;
	
	return 0;
}