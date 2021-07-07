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

const int maxn = 1000 + 5, maxk = 10000 + 5;

pair<short, short> dp[maxn][maxk];
vector<pii> g[maxn];
int n, m, k, s, t;

void bfs(){
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= k; j++)
			dp[i][j] = {-1, -1};

	dp[s][0] = {0, 0};
	
	for(int i = 1; i <= k; i++){
		
		for(int j = 1; j <= n; j++){
			
			//if(dp[j][i].first == -1)
			//	continue;
			
			for(auto &e : g[j]){
				
				int v = e.first;
				int c = e.second;
				
				if(i - c < 0 || dp[v][i - c].first == -1 )
					continue;
				
				if(dp[j][i] == pair<short, short>(-1, -1))
					dp[j][i] = {v, c};
				
			}
		}
	}
	
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> k >> s >> t;
	
	for(int i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	
	bfs();
	
	//cout << dp[t][k].first << " " << dp[t][k].second << endl;
	//return 0;
	
	if(dp[t][k] == pair<short, short>(-1, -1)){
		cout << "Impossible" << endl;
		return 0;
	}
	
	vector<int> ans;
	
	while(true){
		
		
		ans.push_back(t);
		
		if(t == s && k == 0)
			break;
		
		int nt = dp[t][k].first;
		int nc = k - dp[t][k].second;
		t = nt;
		k = nc;
	}
	
	
	reverse(ans.begin(), ans.end());
	
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " \n"[i + 1 == (int)ans.size()];

	return 0;
}