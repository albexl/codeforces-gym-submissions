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
// typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// template<typename T>
// static T randint(T lo, T hi){
// 	return uniform_int_distribution<T>(lo, hi)(rng);
// }

const int maxn = 500 + 5;

int pi[maxn * maxn], idx[maxn][maxn], n;
ll mn[maxn * maxn], sz[maxn * maxn], a[maxn][maxn];
ll ans = 0, cnt = 0;

bool valid(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

int root(int x){
	return pi[x] == x ? x : root(pi[x]);
}

void merge(int a, int b){
	a = root(a), b = root(b);
	if(a == b)
		return;

	if(sz[a] > sz[b])
		swap(a, b);

	sz[b] += sz[a];
	mn[b] = min(mn[b], mn[a]);
	pi[a] = b;

	ll val = mn[b] * sz[b];
	if(val > ans || (val == ans && sz[b] > cnt)){
		ans = val;
		cnt = sz[b];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	cin >> n;
	int pos = 0;
	vector<pair<ll, pii>> spots;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			cin >> a[i][j];
			idx[i][j] = pos;
			sz[pos] = 1;
			mn[pos] = a[i][j];
			pi[pos] = pos;
			pos++;
			spots.push_back({a[i][j], {i, j}});
		}

	vector<int> dx = {1, -1, 0, 0};
	vector<int> dy = {0, 0, 1, -1};

	sort(spots.rbegin(), spots.rend());
	for(auto &p : spots){
		ll val = p.first;
		int x = p.second.first;
		int y = p.second.second;

		if(val > ans || (val == ans && 1 > cnt)){
			ans = val;
			cnt = 1;
		}

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(valid(nx, ny) && a[nx][ny] >= val)
				merge(idx[x][y], idx[nx][ny]);
		}
	}


	cout << ans << " " << cnt << endl;

	return 0;
}