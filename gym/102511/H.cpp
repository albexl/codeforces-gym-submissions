#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;

vector<vector<int>> g, gr, depth;
vector<int> ans, path;
vector<bool> on, vis;
int n, k, cnt;

pii find_edge(int u){
	while(!vis[g[u][0]]){
		vis[u] = true;
		u = g[u][0];
	}
	return {g[u][0], u};
}

void solve(int u, pii e){
	if(path.size() >= k + 1){
		int d = (int)path.size() - k - 1;
		int v = path[d];
		ans[v]--;
	}

	ans[u]++;
	path.push_back(u);

	for(auto &v : gr[u]){
		if(u == e.first && v == e.second)
			continue;
		solve(v, e);
		ans[u] += ans[v];
	}

	path.pop_back();
}

void prepare(int u, int dist, pii e){
	if(dist > k)
		return;
	depth[dist].push_back(u);
	on[u] = true;
	cnt++;
	for(auto &v : gr[u]){
		if(u == e.first && v == e.second)
			continue;
		prepare(v, dist + 1, e);
	}
}

void remove(int u, pii e){
	if(!on[u])
		return;
	on[u] = false;
	cnt--;
	for(auto &v : gr[u]){
		if(u == e.first && v == e.second)
			continue;
		remove(v, e);
	}
}

void repair(int u, pii e){
	for(int d = 0; d <= k && u != e.second; d++, u = g[u][0]){
		remove(u, e);

		for(auto &v : depth[k - d])
			if(on[v]){
				cnt--;
				on[v] = false;
			}

		ans[u] += cnt;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;

	g = vector<vector<int>>(n);
	gr = vector<vector<int>>(n);

	for(int i = 0, x; i < n; i++){
		cin >> x;
		x--;
		g[i].push_back(x);
		gr[x].push_back(i);
	}

	ans = vector<int>(n);
	vis = on = vector<bool>(n);
	depth = vector<vector<int>>(k + 1);

	for(int i = 0; i < n; i++){
		if(!ans[i]){
			pii e = find_edge(i);
			solve(e.second, e);

			cnt = 0;
			for(int j = 0; j <= k && !depth[j].empty(); j++)
				depth[j].clear();
			prepare(e.second, 0, e);
			repair(e.first, e);
		}
	}

	for(int i = 0; i < n; i++)
		cout << ans[i] << endl;

	return 0;
}