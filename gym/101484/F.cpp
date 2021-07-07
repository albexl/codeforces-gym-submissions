#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

const int maxn = 1e5 + 5;
const int maxp = 21;

int n, m;
ll sum[maxn][maxp], val[maxn];
vector<int> g[maxn];

void dfs(int u, int p, int d){
	sum[u][d] += val[u];
	for(auto &v : g[u]){
		if(v != p){
			dfs(v, u, d + 1);
			for(int i = 0; i < maxp; i++)
				sum[u][i] += sum[v][i];
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> val[1];

    for(int i = 1; i < n; i++){
    	int u, v;
    	cin >> u >> v;
    	cin >> val[u];
    	g[v].push_back(u);
    }

    dfs(1, 0, 0);

    while(m--){
    	int u;
    	cin >> u;

    	ll ans = 0;
    	for(int i = 0; i < maxp; i++)
    		ans = max(ans, sum[1][i] - sum[u][i]);

    	cout << ans << endl;
    }

    return 0;
}