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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	string s;
	cin >> s;
	
	map<int, int> mp;
	for(auto &c : s)
		mp[c - 'a']++;
	
	int ans = 0, odds = 0;
	for(auto &el : mp)
		if(el.second % 2)
			odds++;

	if(odds > 1)
		ans += odds - 1;
	
	cout << ans << endl;

	return 0;
}