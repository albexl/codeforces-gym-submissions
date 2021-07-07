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

const int maxn = 4000 + 5;
const int oo = 1e9;

vector<int> C[maxn];
int dp[maxn][maxn], comp;
int n, m;

int solve(int c, int ones){
	if(c == comp){
		int zeros = n - ones;
		return dp[c][ones] = abs(zeros - ones);
	}

	if(dp[c][ones] != oo)
		return dp[c][ones];

	int ans = oo, sz = C[c].size();
	ans = min(ans, solve(c + 1, ones));
	ans = min(ans, solve(c + 1, ones + sz));

	return dp[c][ones] = ans;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("dislodging_logs_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int t;
	cin >> t;

	for(int cases = 1; cases <= t; cases++){
		
		cin >> n >> m;

		comp = 0;
		for(int i = 0; i < n; i++){
			C[i].clear();
			for(int j = 0; j < n + 5; j++)
				dp[i][j] = oo;
		}

		vector<vector<int>> g(n);
		vector<bool> seen(n);

		for(int i = 0; i < m; i++){
			int l, r;
			cin >> l >> r;

			l--, r--;

			while(l <= r){
				g[l].push_back(r);
				g[r].push_back(l);
				l++;
				r--;
			}
		}

		for(int i = 0; i < n; i++){
			if(seen[i])
				continue;

			queue<int> Q;
			Q.push(i);
			seen[i] = true;
			while(!Q.empty()){
				int u = Q.front();Q.pop();
				C[comp].push_back(u);
				for(auto &v : g[u]){
					if(!seen[v]){
						seen[v] = true;
						Q.push(v);
					}
				}
			}
			comp++;
		}

		string ans = string(n, '*');
		solve(0, 0);

		int ones = 0;
		for(int i = 0; i < comp; i++){
			int sz = C[i].size(), val = -1;
			
 		// 	cerr << "HERE" << endl;
			// cerr << i << " " << ones << endl;
			// cerr << dp[i + 1][ones + sz] << " " << dp[i + 1][ones] << endl;

			if(dp[i + 1][ones + sz] < dp[i + 1][ones]){
				val = 1;
				ones += sz;
			}
			else
				val = 0;

			// cerr << val << endl;

			for(auto &p : C[i])
				ans[p] = (char)(val + '0');
		}

		cout << "Case #" << cases << ": " << ans << endl;
	}

	return 0;
}