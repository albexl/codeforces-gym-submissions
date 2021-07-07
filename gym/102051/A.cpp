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
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<int> f(26);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		for(auto &c : s)
			f[c - 'a']++;
	}
	
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		for(auto &c : s){
			int pos = c - 'a';
			pos += k;
			pos %= 26;
			f[pos]--;
		}
	}
	
	for(int i = 0; i < 26; i++){
		if(f[i] < 0){
			cout << "It is gonna be daijoubu." << endl;
			return 0;
		}
	}
	
	cout << "Make her kokoro go doki-doki!" << endl;

	return 0;
}