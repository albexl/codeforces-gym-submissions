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
	
	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		
		cout << "Test case #" << cases << ":" << endl;
		
		set<pair<char, char>> mp;
		int p;
		cin >> p;
		while(p--){
			char a, b;
			cin >> a >> b;
			mp.insert({a, b});
			mp.insert({b, a});
		}
		
		int q;
		cin >> q;
		
		while(q--){
			string s;
			cin >> s;
			
			bool ok = true;
			int lo = 0, hi = s.size() - 1;
			while(lo <= hi){
				if(s[lo] == s[hi]){
					lo++;
					hi--;
					continue;
				}
				
				if(mp.find({s[lo], s[hi]}) == mp.end()){
					ok = false;
					break;
				}
				
				lo++;
				hi--;
			}
			
			cout << s << " " << (ok ? "YES" : "NO") << endl;
			
		}
		
		cout << endl;
		
	}

	return 0;
}