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
	
	int t;
	cin >> t;
	
	while(t--){
		
		ll n, x;
		cin >> x >> n;
		
		if(n == 1){
			cout << x << endl;
			continue;
		}
		
		ll cnt = n + n - 2;
		ll q = x / cnt;
		
		vector<ll> ans(n);
		for(ll i = 0; i < n; i++){
			ans[i] = q;
			if(i + 1 != n && i != 0)
				ans[i] += q;
		}
		
		ll r = x % cnt;
		
		for(ll i = 0; i < n && r; i++, r--)
			ans[i]++;
		
		for(ll i = n - 2; i >= 1 && r; i--, r--)
			ans[i]++;
		
		for(ll i = 0; i < n; i++)
			cout << ans[i] << " \n"[i + 1 == n];
		
		
	}

	return 0;
}