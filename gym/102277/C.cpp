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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool ok(int x, vector<bool> &f){
	if(x == 0){
		if(f[x])
			return false;
	}

	while(x){
		int y = x % 10;
		if(f[y])
			return false;
		x /= 10;
	}

	return true;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	const int oo = 1e9;

	
	int n;
	cin >> n;

	vector<int> d(n);
	vector<bool> flags(11);
	for(int i = 0; i < n; i++)
		cin >> d[i], flags[d[i]] = true;

	int num;
	cin >> num;

	int ans = oo;

	for(int i = 0; i <= 999; i++){
		
		if(ok(i, flags))
			ans = min(ans, abs(i - num));

	}

	cout << ans << endl;

	return 0;
}