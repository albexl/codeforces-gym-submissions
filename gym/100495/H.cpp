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

const int oo = 1e9;
const int maxn = 100 + 1;

int dx[] = {1, -1, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0};

int dp[maxn][maxn][maxn];
char a[maxn][maxn][maxn], c;

int T[1000], X[1000], Y[1000];

bool valid(int x, int y){
	return x >= 0 && x < maxn && y >= 0 && y < maxn;
}

int solve(int t, int x, int y){
	
	if(t == maxn)
		return 0;
	
	if(dp[t][x][y] != -1)
		return dp[t][x][y];
	
	int add = 0;
	if(a[t][x][y] != '.'){
		if(a[t][x][y] == c)
			add = 1;
		else
			add = -oo;
	}
	
	int ans = 0;

	for(int i = 0; i < 5; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(valid(nx, ny))
			ans = max(ans, add + solve(t + 1, nx, ny));
	}
	
	return dp[t][x][y] = ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			for(int k = 0; k < maxn; k++)
				a[i][j][k] = '.';
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		cout << "Case #" << cases << ": ";
		
		int n;
		cin >> n;
		
		char v;
		for(int i = 0; i < n; i++){
			cin >> T[i] >> X[i] >> Y[i] >> v;
			a[T[i]][X[i]][Y[i]] = v;
		}
		
		memset(dp, -1, sizeof(dp));
		int s1 = 0;
		c = 'u';
		
		for(int i = 0; i <= 100; i++)
			for(int j = 0; j <= 100; j++)
				s1 = max(s1, solve(0, i, j));
		
		memset(dp, -1, sizeof(dp));
		int s2 = 0;
		c = 'a';
		
		for(int i = 0; i <= 100; i++)
			for(int j = 0; j <= 100; j++)
				s2 = max(s2, solve(0, i, j));
		
		cout << s1 << " " << s2 << endl;
		
		for(int i = 0; i < n; i++)
			a[T[i]][X[i]][Y[i]] = '.';
	}

	return 0;
}