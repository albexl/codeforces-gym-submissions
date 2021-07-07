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

const int maxn = 5e4 + 5;
const int oo = 2e9;

int s, d[maxn], n, k, dp[maxn][2];
vector<pii> g[maxn];
bool light[maxn];

void dfs(int u, int p, int dst){
	if(dst <= 0){
		if(light[u]){
			dp[u][0] = oo;
			dp[u][1] = 0;
		}
		else{
			dp[u][0] = 0;
			dp[u][1] = 1;
		}
		return;
	}
	
	for(auto &e : g[u]){
		int v = e.first;
		int cost = e.second;
		if(v != p){
			dfs(v, u, dst - cost);
			dp[u][0] += dp[v][1];
			dp[u][1] += min(dp[v][0], dp[v][1]);
		}
	}
	
	if(light[u])
		dp[u][0] = oo;
	else
		dp[u][1]++;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));

	cin >> n >> s;
	
	for(int i = 1, a, b, c; i < n; i++){
		cin >> a >> b >> c;
		g[a].push_back({b, 2 * c});
		g[b].push_back({a, 2 * c});
	}
	
	cin >> k;
	for(int i = 0, u; i < k; i++){
		cin >> u;
		light[u] = true;
	}
	
	dfs(1, 0, s);
			
	cout << min(dp[1][0], dp[1][1]) << endl;

	return 0;
}