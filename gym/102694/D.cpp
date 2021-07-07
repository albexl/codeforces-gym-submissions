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
typedef pair<pii, ll> tri;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

const int maxn = 3e5 + 5;
const int maxp = 22;
const int oo = 2e9;

int n, m;
int A[maxn][maxp], dst[maxn], M[maxn][maxp];
vector<pii> g[maxn];

void dfs(int u, int p){
    A[u][0] = p;
    for(auto &v : g[u])
        if(v.first != p){

            M[v.first][0] = v.second;
            dst[v.first] = 1 + dst[u]; 
            dfs(v.first, u);
        }
}

void compute(){

    for(int k = 1; k < maxp; k++){
        for(int i = 0; i < n; i++){
            if(A[i][k - 1] != -1){
                A[i][k] = A[A[i][k - 1]][k - 1];
                M[i][k] = min(M[i][k - 1], M[A[i][k - 1]][k - 1]);
            }
            else A[i][k] = M[i][k] = -1;
        }
    }
}

int query(int u, int v){
    if(dst[u] < dst[v])
        swap(u, v);
    
    int d = dst[u] - dst[v];
    int ans = oo;

    for(int i = 0; i < maxp; i++){
        if(d & (1 << i)){
            ans = min(ans, M[u][i]);
            u = A[u][i];
            d ^= (1 << i);
        }
    }

    if(u == v)
        return ans;
    
    for(int i = maxp - 1; i >= 0; i--){
        if(A[u][i] != A[v][i]){
            ans = min(ans, min(M[u][i], M[v][i]));
            u = A[u][i];
            v = A[v][i];
        }
    }

    ans = min(ans, min(M[u][0], M[v][0]));
    return ans;
}

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("perimetric_chapter_1_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	memset(A, -1, sizeof(A));

	cin >> n >> m;
	for(int i = 0, a, b, c; i < m; i++){
		cin >> a >> b >> c;
		a--, b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}

	dfs(0, -1);
	compute();

	cin >> m;
	while(m--){
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << query(a, b) << endl;
	}

	return 0;
}