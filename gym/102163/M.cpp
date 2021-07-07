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

	int t;
	cin >> t;
	while(t--){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		
		if(a == 0){
			if(c == 0)
				cout << "Lazy" << endl;
			else
				cout << "Congrats" << endl;
			continue;
		}
		
		if(c == 0){
			cout << "HaHa" << endl;
			continue;
		}
		
		double t1 = 1.0 * b * log(a);
		double t2 = 1.0 * d * log(c);
		
		if(fabs(t1 - t2) < eps)
			cout << "Lazy" << endl;
		else if(t1 < t2)
			cout << "Congrats" << endl;
		else if(t1 > t2)
			cout << "HaHa" << endl;

	}

	return 0;
}