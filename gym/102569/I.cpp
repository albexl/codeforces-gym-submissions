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

bool sorted(vector<int> &v){
	for(int i = 1; i < v.size(); i++)
		if(v[i] < v[i - 1])
			return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	const int maxn = 2e5 + 5;
	
	vector<vector<int>> a(maxn);
	
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		a[y].push_back(x);
	}
	
	bool ok = true;
	for(int i = 0; i < maxn; i++)
		ok &= (sorted(a[i]));
	
	cout << (ok ? "YES" : "NO") << endl;

	return 0;
}