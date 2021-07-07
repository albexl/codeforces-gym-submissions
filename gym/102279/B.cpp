#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

//#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 5;
vector<int> adj[maxn];
bool mk[maxn];
int q[maxn], p[maxn], sz[maxn], mc[maxn];

int centroid(int c){
	int b = 0, e = 0;
	q[e++] = c,	p[c] = -1, sz[c] = 1, mc[c] = 0;

	while (b < e){
		int u = q[b++];
		for (auto v : adj[u]) if (v != p[u] && !mk[v])
				p[v] = u, sz[v] = 1, mc[v] = 0, q[e++] = v;
	}

	for (int i = e - 1; ~i; --i){
		int u = q[i];
		int bc = max(e - sz[u], mc[u]);
		if (2 * bc <= e) return u;
		sz[p[u]] += sz[u], mc[p[u]] = max(mc[p[u]], sz[u]);
	}

	assert(false);
	return -1;
}

void solve(int u){
	int c = centroid(u);
	
	cout << "? " << 1 << " " << c << endl;
	int ans;
	cin >> ans;
	
	if(ans == 0){
		cout << "! " << c << endl;
		exit(0);
	}
	
	cout << "? " << 2 << " " << c << endl;
	cin >> ans;
	
	mk[c] = true;
	solve(ans);
	
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	for(int i = 0, a, b; i < n - 1; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	solve(1);

	return 0;
}