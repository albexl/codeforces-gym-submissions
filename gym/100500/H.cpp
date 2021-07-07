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

const int maxn = 1000 + 5;
const ll oo = 1e12;

int t, n, m;
ll dp[maxn][maxn], a[maxn][maxn];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j];
		
		for(int i = n - 1; i >= 0; i--){
			for(int j = m - 1; j >= 0; j--){
				if(i == n - 1 && j == m - 1)
					dp[i][j] = a[i][j];
				else if(i == n - 1)
					dp[i][j] = a[i][j] + dp[i][j + 1];
				else if(j == m - 1)
					dp[i][j] = a[i][j] + dp[i + 1][j];
				else
					dp[i][j] = a[i][j] + max(dp[i + 1][j], dp[i][j + 1]);
			}
		}

		cout << "Case " << cases << ": " << dp[0][0] << endl;
	}

	return 0;
}