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

const double oo = 1e10;

double f(double x, ll a, ll b, ll c){
	return -1.0 * a * x * x + b * x + c;
}

double calc(ll a, ll b, ll c){
	double lo = -oo, hi = oo;
	
	for(int i = 0; i < 100; i++){
		double third = (hi - lo) / 3.0;
		double p1 = lo + third;
		double p2 = hi - third;
		
		if(f(p1, a, b, c) > f(p2, a, b, c))
			hi = p2;
		else
			lo = p1;
	}
	
	return f(lo, a, b, c);
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
		cin >> n;
		
		double ans = 0.0;
		int opt = -1;
		
		for(int i = 0; i < n; i++){
			ll a, b, c;
			cin >> a >> b >> c;
			double torque = calc(a, b, c);
			if(torque > ans){
				ans = torque;
				opt = i + 1;
			}
			//cout << i << " " << torque << endl;
		}
		
		cout << opt << endl;
		//cout << ans << endl;
	}

	return 0;
}