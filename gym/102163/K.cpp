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
		
		int n;
		ll x;
		cin >> n >> x;
		
		vector<ll> v(n + 1);
		for(int i = 1; i <= n; i++)
			cin >> v[i], v[i] += v[i - 1];
		
		ll ans = 0;
		for(int i = 1; i <= n; i++){
			int lo = i, hi = n, pos = -1;
			while(lo <= hi){
				int mid = (lo + hi) >> 1;
				ll sum = v[mid] - v[i - 1];
				if(sum < x){
					pos = mid;
					lo = mid + 1;
				}
				else hi = mid - 1;
			}
			
			if(pos != -1)
				ans += 1ll * (pos - i + 1);
		}
		
		cout << ans << endl;
		
	}

	return 0;
}