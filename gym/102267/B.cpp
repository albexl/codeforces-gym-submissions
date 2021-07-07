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

const int maxn = 1e7 + 5;

bool f[maxn];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	f[0] = f[1] = true;
	for(int i = 2; i < maxn; i++){
		if(!f[i]){
			for(ll j = (ll)i * i; j < maxn; j += i)
				f[j] = true;
		}
	}
	
	int n;
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		int a = i;
		int b = n - i;
		if(!f[a] && !f[b]){
			cout << a << " " << b << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;

	return 0;
}