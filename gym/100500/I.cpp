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
	
	int t;
	cin >> t;
	
	for(int cases = 1; cases <= t; cases++){
		
		string s;
		
		vector<pii> v(26);
		for(int i = 0; i < 26; i++)
			v[i].second = i;
		
		while(cin >> s && s != "*"){
			for(auto &c : s){
				c = tolower(c);
				v[c - 'a'].first++;
			}
		}
		
		sort(v.rbegin(), v.rend());
		int sum = 0;
		for(int i = 0; i < 5; i++)
			if(v[i].first)
				sum += v[i].second;
		
		//for(int i = 0; i < 26; i++)
		//	cout << v[i].second << " " << v[i].first << endl;
		
		cout << "Case " << cases << ": ";
		if(sum > 62)
			cout << "Effective" << endl;
		else
			cout << "Ineffective" << endl;
		
	}

	return 0;
}