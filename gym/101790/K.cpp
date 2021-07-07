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
	
	int x;
	cin >> x;
	
	x *= 60;
	
	int a, b;
	cin >> a >> b;
	
	int pos = a + b, ans = 0;
	
	if(b >= a){
		for(int i = pos; i <= x; i += b)
			ans++;
	}
	else{
		for(int i = pos; i <= x; i += (a - b) + b)
			ans++;
	}
	
	cout << ans << endl;

	return 0;
}