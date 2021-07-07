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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	
	string s;
	cin >> s;

	vector<int> dp(26);
	for(auto &c : s)
		dp[c - 'a']++;

	bool even = false, odd = false;

	for(int i = 0; i < 26; i++){
		if(dp[i]){
			even |= (dp[i] % 2 == 0);
			odd |= (dp[i] % 2 == 1);
		}
	}

	if(even && odd)
		cout << 2 << endl;
	else if(odd)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}