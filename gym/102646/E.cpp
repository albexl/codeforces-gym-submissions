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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


const int maxn = 1e5 + 5;

int sz[maxn], pi[maxn];
int n, m, k;

int root(int x){
	return pi[x] == x ? x : root(pi[x]);
}

bool merge(int a, int b){
	a = root(a), b = root(b);
	if(a == b)
		return false;

	if(sz[a] > sz[b])
		swap(a, b);

	sz[b] += sz[a];
	pi[a] = b;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n >> m >> k;

	for(int i = 1; i <= n; i++)
		sz[pi[i] = i] = 1;

	vector<int> ans;
	for(int i = 0; i < m && (int)ans.size() < k; i++){
		int a, b;
		cin >> a >> b;
		if(merge(a, b))
			ans.push_back(i + 1);
	}

	cout << n << endl;
	for(int i = 0; i < k; i++)
		cout << ans[i] << " \n"[i + 1 == k];
 
	return 0;
}