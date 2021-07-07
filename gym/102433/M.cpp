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

struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};

const int maxn = 1000 + 5;

char a[maxn][maxn];
int n, m;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool valid(int x, int y){
	return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}

int get(int x, int y){
	return (m + 2) * x + y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	
	for(int i = 0; i <= n + 1; i++)
		a[i][0] = a[i][m + 1] = '.';
	
	for(int j = 0; j <= m + 1; j++)
		a[0][j] = a[n + 1][j] = '.';
		
	int sz = (n + 2) * (m + 2);
	union_find ds(sz);
	
	int cnt = 0;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] == '/' && a[i][j + 1] == '\\' && a[i + 1][j] == '\\' && a[i + 1][j + 1] == '/')
				cnt++;
	
	for(int i = 0; i <= n + 1; i++){
		for(int j = 0; j <= m + 1; j++){
			if(a[i][j] == '.'){
				for(int k = 0; k < 4; k++){
					int ii = i + dx[k];
					int jj = j + dy[k];
					
					if(valid(ii, jj) && a[ii][jj] == '.')
						ds.join(get(i, j), get(ii, jj));	
				}
				
				int nx = i - 1, ny = j + 1;
				if(valid(nx, ny) && a[nx][ny] == '.' && a[i - 1][j] != '\\' && a[i][j + 1] != '\\')
					ds.join(get(i, j), get(nx, ny));
				
				nx = i + 1, ny = j - 1;
				if(valid(nx, ny) && a[nx][ny] == '.' && a[i][j - 1] != '\\' && a[i + 1][j] != '\\')
					ds.join(get(i, j), get(nx, ny));
				
				nx = i + 1, ny = j + 1;
				if(valid(nx, ny) && a[nx][ny] == '.' && a[i + 1][j] != '/' && a[i][j + 1] != '/')
					ds.join(get(i, j), get(nx, ny));
				
				nx = i - 1, ny = j - 1;
				if(valid(nx, ny) && a[nx][ny] == '.' && a[i - 1][j] != '/' && a[i][j - 1] != '/')
					ds.join(get(i, j), get(nx, ny));
			} 
		}
	}
		
	set<int> roots;
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j <= m + 1; j++)
			if(a[i][j] == '.')
				roots.insert(ds.root(get(i, j)));
	
	cnt += (int)roots.size() - 1;
	cout << cnt << endl;

	return 0;
}