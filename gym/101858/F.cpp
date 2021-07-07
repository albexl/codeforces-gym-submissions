#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int n, m, comps;
vector<pii> edges;
vector<int> pi, sz;

int set_of(int x){
	return x == pi[x] ? x : set_of(pi[x]);
}

void merge(int x, int y){
	x = set_of(x), y = set_of(y);
	if(x == y)
		return;
	comps--;
	if(sz[x] > sz[y])
		swap(x, y);
	sz[y] += sz[x];
	pi[x] = y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m;
	for(int i = 0, a, b; i < m; i++){
		cin >> a >> b;
		edges.push_back({a, b});
	}
	
	comps = n;
	pi.resize(n + 1);
	sz.resize(n + 1);
	
	for(int i = 1; i <= n; i++)
		sz[pi[i] = i] = 1;
	
	vector<int> order(m);
	for(int i = 0; i < m; i++)
		cin >> order[i], order[i]--;
	reverse(order.begin(), order.end());
	
	vector<int> ans;
	
	for(auto &r : order){
		ans.push_back(comps);
		merge(edges[r].first, edges[r].second);
	}
	
	reverse(ans.begin(), ans.end());
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << endl;
	
	return 0;
}