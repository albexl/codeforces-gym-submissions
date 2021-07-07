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

const int maxn = 200000 + 5;
const int maxp = 20;

int A[maxn][maxp], dst[maxn];
vector<int> g[maxn];
int n;

void dfs(int u, int p){
	A[u][0] = p;
	for(auto &v : g[u]){
		if(v != p){
			dst[v] = dst[u] + 1;
			dfs(v, u);
		}
	}
}

void compute(){
	for(int k = 1; k < maxp; k++)
		for(int i = 1; i <= n; i++)
			if(A[i][k - 1] != -1)
				A[i][k] = A[A[i][k - 1]][k - 1];
}

int query(int u, int v){
    if(dst[u] < dst[v])
        swap(u, v);
    
    int d = dst[u] - dst[v];

    for(int i = 0; i <= 19; i++){
        if(d & (1 << i)){
            u = A[u][i];
            d ^= (1 << i);
        }
    }

    if(u == v)
        return u;
    
    for(int i = 19; i >= 0; i--){
        if(A[u][i] != A[v][i]){
            u = A[u][i];
            v = A[v][i];
        }
    }

    return A[u][0];
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	memset(A, -1, sizeof(A));
	dfs(0, -1);
	compute();
	
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		a--, b--;
		
		int l = query(a, b);
		int d = dst[a] + dst[b] - 2 * dst[l];
		d++;
		d -= 2;
		cout << d << endl;
		
	}

	return 0;
}