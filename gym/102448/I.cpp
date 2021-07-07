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

int n, m, s;
vector<vector<int>> v;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int get(int i, int j){
	return i * m + j;
}

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool ok(int t){
	
	int N = n * m;
	union_find ds(N);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(v[i][j] >= t){
				
				for(int k = 0; k < 4; k++){
					int ii = i + dx[k];
					int jj = j + dy[k];
					
					if(valid(ii, jj) && v[ii][jj] >= t){
						ds.join(get(i, j), get(ii, jj));
					}
				}	
			}
		}
	}
	
	int mx = 0;
	for(int i = 0; i < N; i++)
		mx = max(mx, -ds.p[ds.root(i)]);
	return mx >= s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cin >> s >> n >> m;
	
	v = vector<vector<int>>(n, vector<int>(m));
	int mx = -1;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> v[i][j];
			mx = max(mx, v[i][j]);
		}
	
	int lo = 1, hi = mx, ans = -1;
	
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(ok(mid)){
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	
	cout << ans << endl;

	return 0;
}