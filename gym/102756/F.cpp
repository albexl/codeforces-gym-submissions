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
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e4 + 5;

char a[3][maxn];
int n, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

bool valid(int x, int y){
	return x >= 0 && x < 3 && y >= 0 && y < n && a[x][y] == '0';
}

vector<vector<bool>> bfs(int x, int y){
	vector<vector<bool>> d(3, vector<bool>(n, false));
	d[x][y] = true;
	queue<pii> Q;
	Q.push({x, y});
	while(!Q.empty()){
		tie(x, y) = Q.front();Q.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(valid(nx, ny) && !d[nx][ny]){
				d[nx][ny] = true;
				Q.push({nx, ny});
			}
		}
	}

	return d;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> n;
	for(int i = 0; i < 3; i++)
		cin >> a[i];

	for(int i = 0; i < 3; i++){

		if(a[i][0] == '1')
			continue;

		auto d = bfs(i, 0);
		if(d[0][n - 1] || d[1][n - 1] || d[2][n - 2]){
			cout << "Solvable!" << endl;
			return 0;
		}
	}

	cout << "Unsolvable!" << endl;
	return 0;
}