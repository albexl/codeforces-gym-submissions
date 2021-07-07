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

int n, m;
int A[maxn][maxp], dst[maxn];

vector<int> g[maxn];

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

int find_kth(int u, int d){

    for(int i = 0; i < maxp; i++){
        if(d & (1 << i)){
            u = A[u][i];
            d ^= (1 << i);
        }
    }

    return u;
}

int query(int u, int v){
    if(dst[u] < dst[v])
        swap(u, v);
    
    int d = dst[u] - dst[v];

    u = find_kth(u, d);

    if(u == v)
        return u;
    
    for(int i = maxp - 1; i >= 0; i--){
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
 
	// freopen("perimetric_chapter_1_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	memset(A, -1, sizeof(A));

	cin >> n;
	for(int i = 1, a, b; i < n; i++){
		cin >> a >> b;
		a--, b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	dfs(0, -1);
	compute();

	cin >> m;
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;

		int v = query(a, b);

		int d = dst[a] - dst[v];

		if(c >= d){
			c -= d;
			d = dst[b] - dst[v];

			if(c >= d){
				cout << b + 1 << endl;
			}
			else{
				cout << find_kth(b, d - c) + 1 << endl;
			}
		}
		else{
			cout << find_kth(a, c) + 1 << endl;
		}
	}

	return 0;
}