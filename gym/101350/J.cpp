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

const double pi = 2.0 * acos(0.0);

double convert(double x){
	return pi * x / 180.0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout << setprecision(6) << fixed;
	
	int t;
	cin >> t;
	
	while(t--){
		
		ll r;
		int a;
		
		cin >> r >> a;
		
		double angle = 1.0 * a;
		angle = convert(angle);
		
		double a1 = 1.0 * r * r * sin(angle) / 2.0;
		double a2 = 1.0 * r * r * angle / 2.0;
		
		cout << a2 - a1 << endl;
	}

	return 0;
}