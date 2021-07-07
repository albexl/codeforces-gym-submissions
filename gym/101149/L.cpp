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

const int maxn = 2e5 + 5;
const int oo = 1e9;

vector<int> g[maxn], gt[maxn];
int n, m, x, y;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> x >> y;
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		gt[b].push_back(a);
	}
	
	vector<int> d1(n + 1, -1), d2(n + 1, -1), d3(n + 1, -1);
	
	queue<int> Q;
	Q.push(0);
	d1[0] = 0;
	
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(auto &v : g[u]){
			if(d1[v] == -1){
				d1[v] = d1[u] + 1;
				Q.push(v);
			}
		}
	}
	
	Q.push(x);
	d2[x] = 0;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(auto &v : gt[u]){
			if(d2[v] == -1){
				d2[v] = d2[u] + 1;
				Q.push(v);
			}
		}
	}
	
	Q.push(y);
	d3[y] = 0;
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		for(auto &v : gt[u]){
			if(d3[v] == -1){
				d3[v] = d3[u] + 1;
				Q.push(v);
			}
		}
	}
	
	//for(int i = 0; i <= n; i++)
	//	cout << d1[i] << " \n"[i == n];
	//for(int i = 0; i <= n; i++)
	//	cout << d2[i] << " \n"[i == n];
	//for(int i = 0; i <= n; i++)
	//	cout << d3[i] << " \n"[i == n];
	
	int ans = oo;
	for(int i = 0; i <= n; i++)
		if(d1[i] != -1 && d2[i] != -1 && d3[i] != -1)
			ans = min(ans, d1[i] + d2[i] + d3[i]);
	
	cout << ans << endl;

	return 0;
}