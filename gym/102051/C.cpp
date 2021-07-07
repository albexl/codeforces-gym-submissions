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

int n, m, k;
vector<int> g[maxn];
bool used[maxn];
map<string, int> M;
int idx = 0;

int dfs(int u){
	used[u] = true;
	int ans = 1;
	
	for(auto &v : g[u])
		if(!used[v])
			ans += dfs(v);
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		string a, b;
		cin >> a >> b;
		if(M.find(a) == M.end())
			M[a] = idx++;
		if(M.find(b) == M.end())
			M[b] = idx++;
		int x = M[a], y = M[b];
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	vector<int> comps;
	
	for(int i = 0; i < n; i++)
		if(!used[i])
			comps.push_back(dfs(i));
	
	int ans = 0;
	sort(comps.rbegin(), comps.rend());
	for(int i = 0; i < min(k, (int)comps.size()); i++)
		ans += comps[i];
	
	cout << ans << endl;

	return 0;
}