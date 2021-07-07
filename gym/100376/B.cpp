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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		int n, m, xo, yo, xi, yi;
		cin >> n >> m >> xo >> yo >> xi >> yi;
		
		ll area = 1ll * n * m;
		int up = min(xo - 1, xi - 1);
		int down = min(n - xo, n - xi);
		int left = min(yo - 1, yi - 1);
		int right = min(m - yo, m - yi);
		
		int u1 = xo - up, u2 = xi - up;
		int d1 = xo + down, d2 = xi + down;
		int l1 = yo - left, l2 = yi - left;
		int r1 = yo + right, r2 = yi + right;
		
		int L = max(l1, l2);
		int R = min(r1, r2);
		int U = max(u1, u2);
		int D = min(d1, d2);
		
		ll area1 = 1ll * (d1 - u1 + 1) * (r1 - l1 + 1);
		ll area2 = 1ll * (d2 - u2 + 1) * (r2 - l2 + 1);
		
		ll area3 = 0;
		
		//cout << u1 << " " << l1 << " " << d1 << " " << r1 << endl;
		//cout << u2 << " " << l2 << " " << d2 << " " << r2 << endl;
		
		
		if(L <= R && U <= D)
			area3 = 1ll * (R - L + 1) * (D - U + 1);
		
		//cout << L << " " << R << " " << U << " " << D << endl;	
		
		cout << area - area1 - area2 + area3 << endl;
		
	}

	return 0;
}