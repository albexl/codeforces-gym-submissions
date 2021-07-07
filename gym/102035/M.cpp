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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll x1, x2, x3, x4, h;
	cin >> x1 >> x2 >> x3 >> x4 >> h;
	
	ll xl = max(x1, x3);
	ll xr = min(x2, x4);
	
	if(xl >= xr)
		cout << 0 << endl;
	else{
		cout << (xr - xl) * h << endl;
	}

	return 0;
}