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

typedef vector<vector<int>> graph;

const int maxn = 5e5;
int n;
int t[2 * maxn];

void build() {
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void update(int p, ll value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

vector<pair<pii, int>> edges;
set<pii> order;

graph G;

int heavy[maxn], root[maxn], depth[maxn];
int pos[maxn], ipos[maxn], parent[maxn];

int dfs(int s, int f){
    parent[s] = f, heavy[s] = -1;
    int size = 1, maxSubtree = 0;

    for (auto u : G[s]) if (u != f){
    	order.insert(pii(s, u));
        depth[u] = depth[s] + 1;
        int subtree = dfs(u, s);

        if (subtree > maxSubtree)
            heavy[s] = u, maxSubtree = subtree;

        size += subtree;
    }

    return size;
}

void go(int ROOT=0){

    depth[ROOT] = 0;
    dfs(ROOT, -1);

    for (int i = 0, currentPos = 0; i < n; ++i)
        if (parent[i] == -1 || heavy[parent[i]] != i)
            for (int u = i; u != -1; u = heavy[u], currentPos++)
                root[u] = i, pos[u] = currentPos, ipos[currentPos] = u;
}

int path_query(int u, int v){
    int ans = 0;
    for (; root[u] != root[v]; v = parent[root[v]]) {
        if (depth[root[u]] > depth[root[v]]) swap(u, v);
        ans += query(pos[root[v]], pos[v] + 1);
    }
    if (depth[u] > depth[v]) swap(u, v);
    ans += query(pos[u], pos[v] + 1);
	ans -= query(pos[u], pos[u] + 1);
    // LCA at u
    return ans;
}

void tree_update(int u, int val){
	update(pos[u], val);
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	
	G.resize(n);
	
	for(int i = 1; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		edges.push_back({{a, b}, c});
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	go();
	
	for(auto &e : edges){
		int cost = e.second;
		
		if(order.find(e.first) == order.end())
			swap(e.first.first, e.first.second);
		
		int u = e.first.second;
		t[pos[u] + n] = cost;
	}
	
	build();

	int q;
	cin >> q;
	while(q--){
		
		int t;
		cin >> t;
		
		if(t == 1){
			int u, v;
			cin >> u >> v;
			u--, v--;
			int sum = path_query(u, v);
			
			//cout << sum << endl;
						
			if(sum & 1)
				cout << "WE NEED BLACK PANDA" << endl;
			else
				cout << "JAKANDA FOREVER" << endl;
		}
		else{
			int pos;
			int val;
			cin >> pos >> val;
			
			auto &e = edges[pos - 1];
			int u = e.first.second;

			tree_update(u, val & 1);
			
		}
		
	}

	return 0;
}