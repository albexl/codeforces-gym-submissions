#include<bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;

const int maxn = 2e5 + 5;
const int maxp = 20;

int n;
int A[maxn][maxp], dst[maxn];
vector<vector<int>> g;

void dfs(int u, int p){
    A[u][0] = p;
    for(auto &v : g[u])
        if(v != p){
            dst[v] = 1 + dst[u]; 
            dfs(v, u);
        }
}

void compute(){

    for(int k = 1; k < maxp; k++){
        for(int i = 0; i < n; i++){
            if(A[i][k - 1] != -1)
                A[i][k] = A[A[i][k - 1]][k - 1];
            else 
				A[i][k] = -1;
        }
    }
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

    cin >> n;
    
    g.resize(n);
    
    for(int i = 1, a, b; i < n; i++){
        cin >> a >> b;
        a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
    }


    dfs(0, -1);
    compute();

	int q;
	cin >> q;
	while(q--){
		int s1, s2;
		cin >> s1 >> s2;
		
		int u = -1, v = -1;
		
		vector<int> reds, blues;
		
		for(int i = 0, x; i < s1; i++){
			cin >> x;
			x--;
			if(u == -1)
				u = x;
			else
				u = query(u, x);
			blues.push_back(x);
		}
		
		for(int i = 0, x; i < s2; i++){
			cin >> x;
			x--;
			if(v == -1)
				v = x;
			else
				v = query(v, x);
			reds.push_back(x);
		}
		
		int lca = query(u, v);
		if(lca != u && lca != v){
			cout << "YES" << endl;
			continue;
		}
		
		bool ok = true;
		
		if(lca == v){
			for(auto &r : reds){
				int anc = query(r, u);
				if(anc == u)
					ok = false;
			}
		}
		else if(lca == u){
			for(auto &b : blues){
				int anc = query(b, v);
				if(anc == v)
					ok = false;
			}
		}
		
		cout << (ok ? "YES" : "NO") << endl;
	}

    return 0;
}