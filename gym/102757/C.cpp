#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'

typedef complex<double> point;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef vector<ll> vec;
typedef vector<vec> mat;

bool leap(ll x){
	return (x % 4 == 0 && x % 100 != 0) || (x % 400 == 0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	double ans = 0.0;

	int x, y;
	cin >> x >> y;

	point p(1.0 * x, 1.0 * y);
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		ans = max(ans, abs(p - point(1.0 * x, 1.0 * y)));
	}


	cout << setprecision(10) << fixed;
	cout << ans << endl;

	return 0;
}