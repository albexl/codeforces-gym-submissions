#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<pii, ll> tri;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const int maxn = 3e5 + 5;

vector<int> g[maxn];
int n;

pii bfs(int u){
	queue<int> Q;
	Q.push(u);

	vector<int> d(n + 1, -1);
	d[u] = 0;

	int x = u;

	while(!Q.empty()){
		u = Q.front();Q.pop();
		x = u;
		for(auto &v : g[u]){
			if(d[v] == -1){
				d[v] = d[u] + 1;
				Q.push(v);
			}
		}
	}

	return {x, d[x]};
}

int find(){
	pii a = bfs(1);
	pii b = bfs(a.first);
	return b.second;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("perimetric_chapter_1_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n;

	for(int i = 1; i < n; i++){
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int diam = find();
	cout << diam * 3 << endl;

	return 0;
}