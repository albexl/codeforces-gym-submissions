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
	
	for(int cases = 1; cases <= t; cases++){
		
		int n;
		cin >> n;
		
		vector<int> t(n), h(n), sum(n), diff(n);
		
		map<int, int> mpsum, mpdiff;
		int idx = 0;
		
		set<int> sums, difs;
		
		for(int i = 0; i < n; i++)
			cin >> t[i];
		for(int i = 0; i < n; i++)
			cin >> h[i];
		
		for(int i = 0; i < n; i++){
			
			sum[i] = t[i] + h[i];
			diff[i] = t[i] - h[i];
			
			sums.insert(sum[i]);
			difs.insert(diff[i]);
		}
		
		for(auto &x : sums)
			mpsum[x] = idx++;
		for(auto &x : difs)
			mpdiff[x] = idx++;
		
		vector<vector<int>> g(idx);
		vector<int> d(idx, -1);
		queue<int> Q;
		
		for(int i = 0; i < n; i++){
			int a = mpsum[sum[i]];
			int b = mpdiff[diff[i]];
			g[a].push_back(b);
			g[b].push_back(a);
			if(!i){
				Q.push(a);
				Q.push(b);
				d[a] = d[b] = 0;
			}
		}
		
		while(!Q.empty()){
			int u = Q.front();Q.pop();
			for(auto &v : g[u]){
				if(d[v] == -1){
					d[v] = d[u] + 1;
					Q.push(v);
				}
			}
		}
		const int oo = 2e9;
		int ans = oo;
		
		int s1 = d[mpsum[sum[n - 1]]];
		int s2 = d[mpdiff[diff[n - 1]]];
		
		if(s1 != -1)
			ans = min(ans, s1);
		
		if(s2 != -1)
			ans = min(ans, s2);
		
		if(ans == oo)
			ans = -2;

		cout << "Field #" << cases << ": " << ans + 1 << endl << endl;
		
	}
	


	return 0;
}