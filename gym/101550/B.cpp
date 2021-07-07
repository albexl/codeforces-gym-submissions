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

const int maxn = 1e6 + 5;
const int oo = 0x3f3f3f3f;

int t[maxn][26];
int nxt[maxn], pos[maxn];
int idx = 1;

void insert(string s, int k){
	int node = 0;
	int n = (int)s.size();
	for(int i = 0; i < n; i++){
		int p = s[i] - 'a';
		if(!t[node][p])
			t[node][p] = idx++;
		node = t[node][p];
	}
	pos[node] = k;
	nxt[node] = node;
}

void dfs(int u){
	for(int i = 0; i < 26; i++){
		int v = t[u][i];
		if(v == 0)
			continue;
		dfs(v);
		if(pos[u] > pos[v]){
			pos[u] = pos[v];
			nxt[u] = nxt[v];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	memset(nxt, -1, sizeof(nxt));
	memset(pos, oo, sizeof(pos));
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		insert(s, i + 1);
	}
	
	dfs(0);
	
	vector<vector<int>> g(idx);
	vector<int> d(idx, -1);
	
	d[0] = 0;
	
	//cout << "edges" << endl;
		
	for(int i = 0; i < idx; i++){
		if(i && nxt[i] != -1 && nxt[i] != i){
			g[i].push_back(nxt[i]);
			//g[nxt[i]].push_back(i);
			
			//cout << i << " " << nxt[i] << endl;
			
		}
		for(int j = 0; j < 26; j++){
			int k = t[i][j];
			if(k){
				g[i].push_back(k);
				g[k].push_back(i);
				
				//cout << i << " " << k << endl;
			}
		}
	}
	
	//cout << "bfs" << endl;
	
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		
		//cout << u << " :" << endl;
	
		for(auto &v : g[u]){	
			if(d[v] == -1){
				d[v] = d[u] + 1;
				Q.push(v);
				
				//cout << v << " " << d[v] << endl;
				
			}
		}
	}
	
	//for(int i = 0; i < idx; i++)
	//	cout << i << " " << nxt[i] << " " << pos[i] << endl;
	
	while(m--){
		string s;
		cin >> s;
		
		int k = (int)s.size();
		int node = 0;
		int i = 0;
		
		for(; i < k; i++){
			int p = s[i] - 'a';
			if(t[node][p])
				node = t[node][p];
			else
				break;
		}
		
	//	cout << node << " " << d[node] << endl;
		
		int ans = d[node] + k - i;
		cout << ans << endl;
	}
	
	return 0;
}