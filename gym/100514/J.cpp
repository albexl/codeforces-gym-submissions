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
	
	map<char, char> mp;
	
	
	vector<string> a = {"wbpctfb", "ghnxfuv", "jjy", "lvevavsvcz", "mkojrpcf", "qcvhcvyginfnf", "djfa"};
	vector<string> b = {"charzeh", "yousefi", "mmt", "bikinigirl", "djvmware", "priorityqueue", "xmen"};
	
	for(int i = 0; i < a.size(); i++){
		for(int j = 0; j < a[i].size(); j++)
			mp[ a[i][j] ] = b[i][j];
	}
	
	//cout << mp.size() << endl;
	
	string s;
	cin >> s;
	
	string ans = "";
	
	for(auto &c : s)
		ans += mp[c];
	
	cout << ans << endl;
	

	return 0;
}