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

const int maxn = 1e5 + 5;

vector<int> g[maxn];
int dp[maxn];

void dfs(int u, int p){
	if(g[u].size() == 1 && u != 1){
		dp[u] = 1;
		return;
	}
	
	for(auto &v : g[u]){
		if(v != p){
			dfs(v, u);
			dp[u] += dp[v];
		}
	}
	
	if(dp[u] == 0)
		dp[u]++;
	else
		dp[u]--;
		
} 

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	dfs(1, 0);
	
//	for(int i = 1; i <= n; i++)
//		cout << dp[i] << endl;
	
	if(dp[1] > 0)
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;

	return 0;
}