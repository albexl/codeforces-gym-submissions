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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	double ans = 0.0, den = 0.0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			double p = 1.0 * (n - i + 1) * (m - j + 1);
			den += p;
			ans += 2.0 * (i + j) * p;
		}
	}

	cout << setprecision(0) << fixed;
	cout << ans / den << endl;

	return 0;
}