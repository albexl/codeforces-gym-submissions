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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const int maxn = 500 + 5;
const int oo = 1e9;

char a[maxn][maxn];
int n, m, k, dp[1 << 8][8];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

vector<vector<int>> bfs(pii u){
	queue<pii> Q;
	Q.push(u);
	vector<vector<int>> d(n, vector<int>(m, -1));
	d[u.first][u.second] = 0;
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(valid(nx, ny) && a[nx][ny] != '*' && d[nx][ny] == -1){
				d[nx][ny] = d[x][y] + 1;
				Q.push({nx, ny});
			}
		}
	}

	return d;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	cin >> n >> m >> k;
	k++;

	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 0; i < (1 << k); i++)
		for(int j = 0; j < k; j++)
			dp[i][j] = oo;

	vector<pii> sites;
	vector<vector<int>> d(k, vector<int>(k, oo));
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(a[i][j] == 'X' || a[i][j] == 'S')
				sites.push_back({i, j});

	int s = -1;
	for(int i = 0; i < k; i++){
		auto dist = bfs(sites[i]);
		for(int j = 0; j < k; j++){
			int x = sites[j].first;
			int y = sites[j].second;
			d[i][j] = dist[x][y];
		}

		if(a[sites[i].first][sites[i].second] == 'S')
			s = i;
	}

	// cerr << "here" << endl;

	dp[1 << s][s] = 0;
	for(int mask = 1; mask < (1 << k); mask++){
		for(int i = 0; i < k; i++){
			if(mask & (1 << i)){
				int prv = mask ^ (1 << i);
				for(int j = 0; j < k; j++)
					if(prv & (1 << j))
						dp[mask][i] = min(dp[mask][i], dp[prv][j] + d[j][i]);
			}
		}
	}

	int ans = oo;
	for(int i = 0; i < k; i++)
		ans = min(ans, dp[(1 << k) - 1][i]);

	cout << ans << endl;
	
	return 0;
}