#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> mat;

const int oo = 1e6;
const int maxn = 20000 + 5;
vector<int> g[maxn];

int x[maxn], y[maxn], r[maxn];

int dfs(int u, int p, int start){

	int len = 0;

	for(auto &v : g[u]){

		if(v != p){

			len += 2;
			len += dfs(v, u, start + len);
		}

	}

	len += 2;

	r[u] = len / 2;
	x[u] = start + r[u];
	y[u] = 0;

	return len;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int root = -1;

	for(int i = 1; i <= n; i++){
		int p;
		cin >> p;
		if(p == -1)
			root = i;
		else
			g[p].push_back(i);
	}

	dfs(root, -1, -oo + 10);

	for(int i = 1; i <= n; i++)
		cout << x[i] << " " << y[i] << " " << r[i] << endl;



	return 0;
}