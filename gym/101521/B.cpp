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

const double eps = 1e-9;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	double a, b, c;
	cin >> a >> b >> c;
	
	//cout << 100.0 / a << " " << 100.0 / b << " " << 100.0 / c << endl;
	//cout << 100.0 / a + 100.0 / b + 100.0 / c << endl;
	
	if(100.0 / a + 100.0 / b + 100.0 / c + eps < 100.0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}