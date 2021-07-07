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

const int maxn = 1e5 + 5;

int sz[maxn], pi[maxn];

void init(int n){
	for(int i = 1; i <= n; i++)
		sz[pi[i] = i] = 1;
}

int root(int x){
	return x == pi[x] ? x : root(pi[x]);
}

void merge(int x, int y){
	x = root(x);
	y = root(y);
	if(x == y)
		return;
	if(rand() & 1)
		swap(x, y);
	pi[x] = y;
	sz[y] += sz[x];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, q;
		cin >> n >> m >> q;
		init(n);
		
		for(int i = 0, a, b; i < m; ++i){
			cin >> a >> b;
			merge(a, b);
		}
		
		int a, b;
		while(q--){
			cin >> a >> b;
			if(root(a) == root(b))
				cout << "1";
			else
				cout << "0";
		}
		
		cout << endl;
		
	}

	return 0;
}