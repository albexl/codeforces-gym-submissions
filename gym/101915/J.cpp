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

const int maxn = 1e3 + 5;

ll L[maxn], R[maxn], x[maxn], y[maxn], r[maxn], sz[maxn], pi[maxn];

void init(int n){
	for(int i = 1; i <= n; i++){
		sz[pi[i] = i] = 1;
		L[i] = x[i] - r[i];
		R[i] = x[i] + r[i];
	}
}

int set_of(int x){
	return x == pi[x] ? x : set_of(pi[x]);
}

void merge(int x, int y){
	x = set_of(x);
	y = set_of(y);
	if(x == y)
		return;
	if(sz[x] > sz[y])
		swap(x, y);
	sz[y] += sz[x];
	pi[x] = y;
	L[y] = min(L[y], L[x]);
	R[y] = max(R[y], R[x]);
}

ll sqr(ll x){
	return x * x;
}

bool touch(int i, int j){
	ll d = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
	return sqr(r[i] + r[j]) >= d;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n;
		ll h, w;
		
		cin >> n >> h >> w;
		for(int i = 1; i <= n; i++)
			cin >> x[i] >> y[i] >> r[i];
		
		init(n);
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				if(touch(i, j))
					merge(i, j);
		
		set<int> roots;
		for(int i = 1; i <= n; i++)
			roots.insert(set_of(i));
		
		int ans = 0;
		for(auto &p : roots)
			if(L[p] <= 0 && R[p] >= h)
				++ans;
		
		cout << ans << endl;
	}

	return 0;
}