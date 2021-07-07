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
typedef pair<ll, vector<ll>> node;
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
		int n, k;
		cin >> n >> k;
		
		vector<ll> ans;
		
		vector<vector<ll>> a(n);
		
		for(int i = 0, sz; i < n; i++){
			cin >> sz;
			a[i].resize(sz);
			for(int j = 0; j < sz; j++)
				cin >> a[i][j];
			sort(a[i].begin(), a[i].end());
		}
		
		set<vector<ll>> visit;
		
		ll sum = 0;
		for(int i = 0; i < n; i++)
			sum += a[i][0];
		
		vector<ll> I(n, 0);
		
		visit.insert(I);
		
		priority_queue<node, vector<node>, greater<node>> pq;
		pq.push({sum, I});
		
		while(!pq.empty() && (int)ans.size() < k){
			node v = pq.top();
			pq.pop();
			
			ans.push_back(v.first);
			
			vector<ll> x = v.second;
			ll s = v.first;
			
			
			for(int i = 0; i < n; i++){
				if(x[i] + 1 < (ll)a[i].size()){
					
					ll ss = s - a[i][x[i]];
					x[i]++;
					ss += a[i][x[i]];
					
					if(visit.find(x) == visit.end()){
						pq.push({ss, x});
						visit.insert(x);
					}
						
					x[i]--;
				}
			}
		}
		
		sort(ans.begin(), ans.end());
		
		for(int i = 0; i < k; i++)
			cout << ans[i] << " \n"[i + 1 == k];		
	}

	return 0;
}