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


const int maxn = 500 + 2;
int a[maxn][maxn], n, m, tc, d[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool ok(int t){
	
	queue<pii> Q;
	Q.push({0, 0});
	if(a[0][0] < t)
		return false;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			d[i][j] = -1;
	d[0][0] = 0;
	
	while(!Q.empty()){
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(valid(nx, ny) && a[nx][ny] - d[x][y] - 1 >= t && d[nx][ny] == -1){
				Q.push({nx, ny});
				d[nx][ny] = d[x][y] + 1;
			}
		}
	}	
	
	return d[n - 1][m - 1] != -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> tc;
	while(tc--){
		
		cin >> n >> m;
		
		int mx = 0;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> a[i][j], mx = max(mx, a[i][j]);
		
		int lo = 1, hi = mx, ans = -1;
		while(lo <= hi){
			int mid = (lo + hi) >> 1;
			if(ok(mid)){
				ans = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		
		if(ans == -1)
			cout << "impossible" << endl;
		else
			cout << ans << endl;
	}
	
	return 0;
}