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

const double oo = 1e18;

double sqr(int x){
	return 1.0 * x * x;
}

double dist(int xo, int yo, int xi, int yi){
	return sqrt(sqr(xo - xi) + sqr(yo - yi));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	while(true){
		int n;
		cin >> n;
		
		if(n == 0)
			break;
		
		n += 2;
		vector<int> x(n), y(n), p(n);
		for(int i = 1; i + 1 < n; i++)
			cin >> x[i] >> y[i] >> p[i];
		
		x[n - 1] = y[n - 1] = 100;
		
		vector<double> dp(n, oo);
		dp[n - 1] = 0.0;
		
		for(int i = n - 2; i >= 0; i--){
			double sum = 0.0;
			for(int j = i + 1; j < n; j++){
				dp[i] = min(dp[i], dp[j] + sum + dist(x[i], y[i], x[j], y[j]) + 1.0);
				sum += 1.0 * p[j];
			}
		}
			
		cout << setprecision(3) << fixed;
		cout << dp[0] << endl;
 	}
	
	return 0;
}