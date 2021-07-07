#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

ll cant(ll d, ll a, ll b){
	a--;
	return b / d - a / d;
}

ll f(ll x){
	return x * (x + 1LL) >> 1LL;
}

ll sum(ll a, ll b){
	if(a > b)
		return 0;
	return f(b) - f(a - 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout << setprecision(0) << fixed;
	
	ll a, b;
	cin >> a >> b;
	long double ans = 0;
	ll m = (ll)sqrt(b);
	for(ll d = 1; d <= m; d++)
		ans += d * cant(d, a, b) + sum(max(m, (a - 1) / d) + 1, max(m, b / d));
	
	cout << ans << endl;

	return 0;
}