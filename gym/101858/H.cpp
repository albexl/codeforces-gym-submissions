#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

map<pii, double> dp;

int n, a;
double p;

double solve(int pos, int fight){
	if(fight == a)
		return 1.0 * pos;
	
	if(dp.find(pii(pos, fight)) != dp.end())
		return dp[pii(pos, fight)];
		
	double ans = 0.0;
	
	ans += p * solve(pos + 1, fight + 1);
	ans += (1.0 - p) * solve(pos - 1, fight + 1);
	
	dp[pii(pos, fight)] = ans;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cout << setprecision(10) << fixed;

	cin >> n >> a;
	a = min(a, 2000);
	
	int x;
	cin >> x;
	p = 1.0 * x / 100.0;
	
	cout << solve(n, 0) << endl;

	return 0;
}