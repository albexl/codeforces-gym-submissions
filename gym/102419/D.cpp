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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const int maxn = 3e5 + 5;

int n, m, a[maxn], color[maxn];
vector<int> g[maxn];
set<int> S;
 
int find_mex(){
	int ans = 1;
	while(S.count(ans))
		++ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("dislodging_logs_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		if(a[u] == a[v]){
			g[v].push_back(u);
			g[u].push_back(v);
		}
		else
			S.insert(a[u] ^ a[v]);
	}

	int val = find_mex();
	memset(color, -1, sizeof(color));

	vector<int> ans;

	for(int i = 1; i <= n; i++){
		if(color[i] == -1){
			queue<int> Q;
			Q.push(i);
			color[i] = 0;
			while(!Q.empty()){
				int u = Q.front();Q.pop();

				if(color[u] == 1)
					ans.push_back(u);

				for(auto &v : g[u]){
					if(color[v] == -1){
						color[v] = 1 - color[u];
						Q.push(v);
					}
					else if(color[v] == color[u]){
						cout << -1 << endl;
						return 0;
					}
				}
			}
 		}
	}

	cout << (int)ans.size() << " " << val << endl;
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << " \n"[i + 1 == (int)ans.size()];

	return 0;
}