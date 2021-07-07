#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<int> point;
typedef pair<int, int> pii;
#define F first
#define S second


const int maxp = 22;
const int maxn = 10 + 5;

char a[maxn][maxn];
bool flags[maxn][maxn];

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

int dp[50000000];
int idx = 0, n;
int id[maxn][maxn], num[maxn][maxn];

vector<pii> pos;

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool ok(int x, int y, int color){

	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(valid(nx, ny) && a[nx][ny] == '*' && num[nx][ny] == color)
			return true;
	}
	return false;
}

void dfs(int x, int y, int color){
	flags[x][y] = true;
	pos.push_back({x, y});
	id[x][y] = idx++;

	for(int i = 0; i < 8; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(valid(nx, ny) && !flags[nx][ny] && a[nx][ny] == '.' && ok(nx, ny, color)){
			dfs(nx, ny, color);
		}
	}
}

int grundy(int mask){

	if(dp[mask] != -1)
		return dp[mask];

	set<int> s;

	for(int i = 0; i < idx; i++){
		if(!(mask & (1 << i))){

			int x = pos[i].first;
			int y = pos[i].second;
			bool ok = true;


			for(int j = 0; j < 4 && ok; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];

				if(valid(nx, ny) && id[nx][ny] != -1){
					if(mask & (1 << id[nx][ny]))
						ok = false;
				}
			}

			if(ok)
				s.insert(grundy(mask | (1 << i)));
		}
	}

	int mx = 0;
	while(s.count(mx))
		++mx;

	return dp[mask] = mx;
}

void flood(int x, int y, int P){
	num[x][y] = P;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(valid(nx, ny) && a[nx][ny] == '*' && num[nx][ny] == -1)
			flood(nx, ny, P);
	}
}

int main()
{
	#ifdef NeverBeRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	memset(num, -1, sizeof(num));
	int P = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] == '*' && num[i][j] == -1){
				flood(i, j, P);
				P++;
			}

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] == '*'){

				for(int l = 0; l < 4; l++){
					int nx = i + dx[l];
					int ny = j + dy[l];

					if(valid(nx, ny) && !flags[nx][ny] && a[nx][ny] == '.'){

						idx = 0;
						pos.clear();
						memset(id, -1, sizeof(id));

						dfs(nx, ny, num[i][j]);

						for(int k = 0; k < (1 << idx); k++)
							dp[k] = -1;

						ans ^= grundy(0);
					}
				}
			}
		}
	}

	if(ans)
		cout << "First";
	else
		cout << "Second";

	cout << " player will win\n";

	return 0;
}