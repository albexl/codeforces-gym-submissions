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
	
	string s;
	cin >> s;
	set<char> S;
	for(auto &c : s)
		S.insert(c);
	
	if(S.size() <= 2){
		cout << "YES" << endl;
		return 0;
	}
	
	vector<char> order = {'B', 'G', 'R'};
	
	do{
		
		
		
		int p1 = -1, p2 = -1;
		for(int i = 0; i < s.size(); i++)
			if(s[i] == order[0])
				p1 = i;
		
		for(int i = s.size() - 1; i >= 0; i--)
			if(s[i] == order[2])
				p2 = i;
		
		if(p2 < p1){
			bool ok = true;
			for(int i = p2 + 1; i < p1; i++)
				if(s[i] == order[1])
					ok = false;
			
			if(ok){
				cout << "YES" << endl;
				//cout << order[0] << " " << order[1] << " " << order[2] << endl;
				return 0;
			}
		}
		
		
	}while(next_permutation(order.begin(), order.end()));

	cout << "NO" << endl;

	return 0;
}