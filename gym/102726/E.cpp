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

	int n;
	cin >> n;

	int cnt = 0;
	double x = 0, y = 0;
	for(int i = 0; i < n; i++){
		int xo, yo, k;
		cin >> xo >> yo >> k;
		x += 1.0 * xo * k;
		y += 1.0 * yo * k;
		cnt += k;
	}

	cout << setprecision(10) << fixed;
	cout << x / cnt << " " << y / cnt << endl;
	
	return 0;
}