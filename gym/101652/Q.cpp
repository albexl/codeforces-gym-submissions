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

ll sum(ll x){
	return x * (x + 1) >> 1LL;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll n;
	cin >> n;
	ll total = sum(n - 1);
	ll half = (total + 1) >> 1LL;
	
	ll lo = 1, hi = n;
	while(lo < hi){
		ll mid = (lo + hi) >> 1LL;
		ll cant = sum(n - 1) - sum(n - mid - 1);
		if(cant >= half)
			hi = mid;
		else
			lo = mid + 1;
	}
	
	cout << lo << endl;

	return 0;
}