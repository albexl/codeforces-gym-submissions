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
vector<int> g[maxn], v;
int n, root;

void dfs(int u, int p){
	bool leaf = true;
	for(auto &v : g[u]){
		if(v != p){
			leaf = false;
			dfs(v, u);
		}
	}
	
	if(leaf)
		v.push_back(u);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> root;
	
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	for(int i = 0; i < n; i++)
		sort(g[i].begin(), g[i].end());
	
	dfs(root, -1);
	
	int sz = (int)v.size();
	vector<bool> used(sz);
	
	vector<pii> ans;
	
	for(int i = 0; i + 1 < sz; i++){
		if(used[i])
			break;
		int lo = i, hi = lo + sz / 2;
		used[lo] = used[hi] = true;
		ans.push_back({v[lo], v[hi]});
	}
	
	if(!used[sz - 1])
		ans.push_back({v[sz - 1], root});
	
	cout << ans.size() << endl;
	for(auto &e : ans)
		cout << e.first << " " << e.second << endl;

	return 0;
}