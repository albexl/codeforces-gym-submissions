#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> tri;

const int maxn = 1e4 + 5;

vector<int> g[maxn];

int d1[maxn], d2[maxn], n, cur = 1;

void dfs(int u, int p){

	for(int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if(v != p){

			if(p == 0){
				if(i != g[u].size() - 1)
					d1[v] = d1[u];
				else
					d1[v] = d2[u];
			}
			else
				d1[v] = d2[u];
			d2[v] = cur++;
		}
	}

	for(auto &v : g[u])
		if(v != p)
			dfs(v, u);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1, a, b; i < n; i++){
    	cin >> a >> b;
    	g[a].push_back(b);
    	g[b].push_back(a);
    }

    int root = 0;
    for(int i = 1; i <= n; i++)
    	if(g[i].size() > 1)
    		root = i;

    if(root == 0){
    	
    	d1[1] = d1[2] = 1;
    	d2[1] = d2[2] = 2;

    	for(int i = 1; i <= n; i++)
    		cout << d1[i] << " " << d2[i] << endl;

    	return 0;
    }

    d1[root] = 1;
    d2[root] = 2;
    cur = 3;
    dfs(root, 0);

    for(int i = 1; i <= n; i++)
    	cout << d1[i] << " " << d2[i] << endl;

    return 0;
}