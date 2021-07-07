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

int n, m;

vector<vector<ll>> v;

int get(int i, int j){
	return i * m + j;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m;
	v.resize(n, vector<ll>(m));
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> v[i][j];
	
	int N = n * m;
	
	vector<ll> dp(N + 2);
	vector<ll> val(N + 2);
	vector<vector<int>> g(N + 2);
	vector<int> indeg(N + 2);
	
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			val[get(i, j)] = max(0ll, v[i][j]);
	
	int s = N, t = N + 1;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			
			if(i - 1 >= 0 && j + 1 < m){
				g[get(i, j)].push_back(get(i - 1, j + 1));
				indeg[get(i - 1, j + 1)]++;
			}
				
			if(j + 1 < m){
				g[get(i, j)].push_back(get(i, j + 1));
				indeg[get(i, j + 1)]++;
			}
			
			if(i + 1 < n && j + 1 < m){
				g[get(i, j)].push_back(get(i + 1, j + 1));
				indeg[get(i + 1, j + 1)]++;
			}
			
			if(j == 0){
				g[s].push_back(get(i, j));
				indeg[get(i, j)]++;
			}
			
			if(j + 1 == m){
				g[get(i, j)].push_back(t);
				indeg[t]++;
			}
		}
	}
	
	queue<int> Q;
	vector<int> order;
	
	Q.push(s);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		order.push_back(u);
		for(auto &v : g[u]){
			indeg[v]--;
			if(!indeg[v])
				Q.push(v);
		}
	}

	reverse(order.begin(), order.end());
	for(auto &u : order){
		dp[u] = val[u];
		for(auto &v : g[u])
			dp[u] = max(dp[u], val[u] + dp[v]);
	}
	
	cout << dp[s] << endl;

	return 0;
}