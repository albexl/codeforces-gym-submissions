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

ll lcm(ll a, ll b){
	ll g = __gcd(a, b);
	return a * b / g;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;
	
	ll s1 = 1, s2 = 0;
	for(int i = 0; i < n; i++){
		ll a, b;
		cin >> a >> b;
		s1 = lcm(s1, a);
		s2 = __gcd(s2, b);
	}
	
	cout << s1 << " " << s2 << endl;
	

	return 0;
}