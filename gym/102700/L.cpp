#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
// #define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

char opp(char c){
	if(c == 'D')
		return 'U';
	if(c == 'U')
		return 'D';
	if(c == 'L')
		return 'R';
	return 'L';
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, char>>> g(n * m);
	vector<string> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];

	char dir[] = {'D', 'U', 'R', 'L'};
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'X')
				continue;

			for(int k = 0; k < 4; k++){
				int ii = i + dx[k];
				int jj = j + dy[k];

				if(ii >= 0 && ii < n && jj >= 0 && jj < m && a[ii][jj] != 'X'){
					int u = i * m + j;
					int v = ii * m + jj;

					g[u].push_back({v, dir[k]});
					g[v].push_back({u, opp(dir[k])});
				}
			}
		}
	}

	for(int i = 0; i < n; i++){
		int last = -1;
		for(int j = 0; j < m; j++){
			if(a[i][j] != 'X'){
				if(last != -1 && last != j - 1){
					int u = i * m + j;
					int v = i * m + last;
					g[u].push_back({v, 'L'});
					g[v].push_back({u, 'R'});
				}
				last = j;
			}
		}
	}

	for(int j = 0; j < m; j++){
		int last = -1;
		for(int i = 0; i < n; i++){
			if(a[i][j] != 'X'){
				if(last != -1 && last != i - 1){
					int u = i * m + j;
					int v = last * m + j;
					g[u].push_back({v, 'U'});
					g[v].push_back({u, 'D'});
				}
				last = i;
			}
		}
	}

	int xo = -1, yo = -1, xi = -1, yi = -1;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			if(a[i][j] == 'S')
				xo = i, yo = j;
			else if(a[i][j] == 'E')
				xi = i, yi = j;
		}

	int s = xo * m + yo, e = xi * m + yi;
	vector<int> d(n * m, -1);
	queue<int> Q;
	Q.push(e);
	d[e] = 0;

	while(!Q.empty()){
		int u = Q.front();Q.pop();

		for(auto &e : g[u]){
			int v = e.first;
			if(d[v] == -1){
				d[v] = d[u] + 1;
				Q.push(v);
			}
		}
	}

	// cout << s << " " << e << endl;

	// for(int i = 0; i < n * m; i++)
	// 	cout << d[i] << " ";
	// cout << endl;

	// return 0;

	cout << d[s] << endl;
	if(d[s] != -1){
		string ans = "";
		// int it = 10;
		while(s != e){
			int nxt = -1;
			char choice = 'Z';
			// it--;

			// cerr << s << " cur" << endl;

			for(auto &e : g[s]){
				int v = e.first;
				char c = e.second;

				if(d[v] == d[s] - 1){
					if(c < choice){
						choice = c;
						nxt = v;
					}
				}
			}

			ans += choice;
			s = nxt;
		}

		cout << ans << endl;
	}

	return 0;
}