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
		int n, m, q;
		cin >> n >> m >> q;
		vector<pii> segs(n);
		
		for(int i = 0; i < n; i++)
			cin >> segs[i].first >> segs[i].second;
			
		if(n)
			sort(segs.begin(), segs.end());
		
		vector<pair<int, pii>> cool;
		
		
		for(int i = 0; i + 1 < n; i++){
			int lo = segs[i].second + 1;
			int hi = segs[i + 1].first - 1;
			
			int sz = hi - lo + 1;
			cool.push_back({sz, {lo, hi}});
		}
		
		if(n && segs[0].first != 1){
			int lo = 1;
			int hi = segs[0].first - 1;
			
			int sz = hi - lo + 1;
			cool.push_back({sz, {lo, hi}});
		}
		
		if(n && segs[n - 1].second != m){
			int lo = segs[n - 1].second + 1;
			int hi = m;
			
			int sz = hi - lo + 1;
			cool.push_back({sz, {lo, hi}});
		}
		
		if(!n)
			cool.push_back({m, {1, m}});

		sort(cool.begin(), cool.end());
		
		vector<pii> opt(m + 1, pii(-1, -1));
		
		for(int i = (int)cool.size() - 1; i >= 0; i--){
			int sz = cool[i].first;
			int l = cool[i].second.first;
			int r = cool[i].second.second;
			
			if(r > opt[sz].second){
				opt[sz].first = l;
				opt[sz].second = r;
			}
		}
		
		for(int i = m - 1; i >= 1; i--){
			if(opt[i + 1].second > opt[i].second){
				opt[i].first = opt[i + 1].first;
				opt[i].second = opt[i + 1].second;
			}
		}
		
		//for(int i = 1; i <= m; i++)
		//	cout << i << " " << opt[i].first << " " << opt[i].second << endl;
		//cout << endl;
		
		
		while(q--){
			int k;
			cin >> k;
			
			if(opt[k] == pii(-1, -1))
				cout << -1 << " " << -1 << endl;
			else{
				int r = opt[k].second;
				int l = r - k + 1;
				cout << l << " " << r << endl;
			}
			
		}
		
	}

	return 0;
}