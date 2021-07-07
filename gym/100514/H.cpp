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
	
	vector<int> f(26);
	
	int n = 0;
	
	for(int i = 0; i < 26; i++){
		cin >> f[i];
		n += f[i];
	}
	
	string s(n, '.');
	
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < f[i]; j++){
			int p;
			cin >> p;
			p--;
			s[p] = (char)(i + 'a');
		}
	}
	
	cout << s << endl;
	
	

	return 0;
}