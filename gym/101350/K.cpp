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
		
		ll a, b, n;
		cin >> a >> b >> n;
		
		set<ll> s;
		
		for(ll x = 1; x <= n; x++){
			ll y = a * x * x + b * x;
			if(y <= n)
				s.insert(y);
		}
		
		if(s.empty())
			cout << -1 << endl;
		else{
			vector<ll> ans(10);
			for(auto &x : s){
				ll val = x;
				vector<ll> f(10);
				
				ll mx = 0;
				
				while(val){
					f[val % 10]++;
					mx = max(mx, f[val % 10]);
					val /= 10;
				}
				
				for(ll i = 0; i < 10; i++)
					if(f[i] == mx)
						ans[i]++;
			}
			
			ll opt = -1, mx = 0;
			for(ll i = 0; i < 10; i++)
				if(ans[i] > mx){
					mx = ans[i];
					opt = i;
				}
			
			cout << opt << endl;
			
		}	
	}

	return 0;
}