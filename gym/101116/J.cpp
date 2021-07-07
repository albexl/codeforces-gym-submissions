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
	
	const ll oo = 0x3f3f3f3f3f3f3f3f;
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		
		vector<pii> p(n);
		
		for(int i = 0; i < n; ++i)
			cin >> p[i].first >> p[i].second;
		
		if(n == 1){
			cout << 0 << endl;
			continue;
		}
		
		sort(p.begin(), p.end());
		
		int sz = n / 2 + 1;
		
		ll ans = oo;
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				
				int yo = min(p[i].second, p[j].second);
				int yi = max(p[i].second, p[j].second);
				
				vector<int> x;
				for(int k = 0; k < n; k++)
					if(p[k].second >= yo && p[k].second <= yi)
						x.push_back(p[k].first);
				
				for(int k = 0; k + sz - 1 < x.size(); k++)
					ans = min(ans, 1ll * (yi - yo) * (x[k + sz - 1] - x[k]));
			}
		}
		
		cout << ans << endl;
	}

	return 0;
}