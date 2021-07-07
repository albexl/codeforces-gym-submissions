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
	
	
	map<int, char> mp;
	
	mp[191] = 'a';
	
	int cur = 188;
	
	for(char c = 'b'; c <= 'z'; c += 2){
		mp[cur] = c;
		cur -= 2;
	}
	
	cur = 189;
	for(char c = 'c'; c <= 'z'; c += 2){
		mp[cur] = c;
		cur -= 2;
	}
	
	int n;
	cin >> n;
	
	string s = "";
	
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		
		s += mp[x];
	}
	
	cout << s << endl;
	
	
	
	return 0;
}