#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n, l;
	cin >> n >> l;
	
	vector<pii> a;
	
	map<pii, int> M;
	
	for(int i = 0, x, y; i < n; i++){
		cin >> x >> y;
		a.push_back({x, y});
	}
	
	a.push_back({0, 0});
	a.push_back({l, 0});
	
	sort(a.begin(), a.end());
	
	n = (int)a.size();
	
	for(int i = 0; i < n; i++){
		int x = a[i].first, y = a[i].second;
		M[pii(x, y)] = i;
	}

	vector<int> dp(n), indeg(n), order;
	vector<vector<int>> g(n);
	
	for(int i = 0; i < n; i++){
		int x = a[i].first;
		int y = a[i].second;
		
		for(int xo = x + 1; xo <= x + 10; xo++)
			for(int yo = y - 10; yo <= y + 10; yo++)
				if(M.find({xo, yo}) != M.end() && abs(xo - x) + abs(yo - y) <= 5){
					int pos = M[pii(xo, yo)];
					g[i].push_back(pos);
					indeg[pos]++;
				}
	}
	
	queue<int> Q;
	for(int i = 0; i < n; i++)
		if(indeg[i] == 0)
			Q.push(i);
	
	while(!Q.empty()){
		int x = Q.front();Q.pop();
		order.push_back(x);
		for(auto &v : g[x]){
			indeg[v]--;
			if(indeg[v] == 0)
				Q.push(v);
		}
	}

	for(int i = n - 2; i >= 0; i--){
		int x = order[i];
		for(auto &y : g[x])
			dp[x] = max(dp[x], dp[y]);
		dp[x]++;
	}
	
	cout << dp[0] - 1 << endl;

	return 0;
}