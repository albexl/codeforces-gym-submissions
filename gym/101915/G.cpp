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
typedef pair<pii, int> tri;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 5;
vector<pii> g[maxn];
vector<tri> segs;

void dfs(int u, int p, int lo, int hi){
	int l = lo, r = hi;
	int sz = (int)g[u].size();
	for(int i = 0; i < sz; i++){
		
		int v = g[u][i].second;
		int c = g[u][i].first;
		
		if(v == p)
			continue;
		
		r = min(r, c);
		int nxt = -1;
		
		for(int j = i + 1; j < sz; j++){
			if(g[u][j].second == p) continue;
			nxt = g[u][j].first;
			break;
		}
			
		
		if(nxt == -1)
			nxt = hi;
		
		dfs(v, u, c + 1, nxt);
	}
	segs.push_back({{l, r}, u});
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		
		int n, m;
		cin >> n >> m;
		
		for(int i = 0; i < n; i++)
			g[i].clear();
		segs.clear();
		
		for(int i = 1, a, b, c; i < n; i++){
			cin >> a >> b >> c;
			a--;
			b--;
			g[a].push_back({c, b});
			g[b].push_back({c, a});
		}
		for(int i = 0; i < n; i++)
			sort(g[i].begin(), g[i].end());
		
		dfs(0, -1, 1, 1e9);
		
		sort(segs.begin(), segs.end());

		ll ans = 0;
		
		for(int i = 0, x; i < m; i++){
			cin >> x;
			int lo = 0, hi = (int)segs.size() - 1, pos = -1;
		
			while(lo <= hi){
				int mid = (lo + hi) >> 1;

				if(segs[mid].first.first > x)
					hi = mid - 1;
				else if(segs[mid].first.second < x)
					lo = mid + 1;
				else{
					pos = mid;
					break;
				}
			}
			
			ans += 1ll * segs[pos].second + 1ll;
		}
		
		cout << ans << endl;
	}

	return 0;
}