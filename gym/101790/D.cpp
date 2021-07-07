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
	
	vector<vector<int>> g(n + 1);
	for(int i = 0, a, b; i < m; ++i){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int t;
	cin >> t;
	
	vector<int> kills(t + 1);
	for(int i = 1; i <= t; i++)
		cin >> kills[i];
	
	vector<int> cnt(n + 1), amount(n + 1);
	vector<bool> dead(n + 1);
	
	set<pii> s;
	
	for(int i = 1; i <= n; i++)
		s.insert({0, i});
	
	for(int i = 1; i <= t; i++){
		int x = kills[i];
		
		dead[x] = true;
		s.erase(pii(cnt[x], x));
		
		for(auto &y : g[x]){
			if(dead[y])
				continue;
			s.erase(pii(cnt[y], y));
			cnt[y]++;
			s.insert(pii(cnt[y], y));
		}
		
		if(s.size() == 1){
			auto val = *(s.begin());
			cout << i << " " << val.second << endl;
			return 0;
		}
		
		auto it = s.end();
		it = prev(it);
		
		auto mx = *it;
		it = prev(it);
		
		auto smx = *it;
		
		if(mx.first == smx.first)
			continue;
		
		cout << i << " " << mx.second << endl;
		return 0;
		
	}	
	
	
	cout << -1 << endl;

	return 0;
}