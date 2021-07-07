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
	
	map<string, string> mp, rmp;
	
	while(cin >> s){
		if(s[0] == '-')
			break;
		
		string s1, s2, s3;
		cin >> s1 >> s2 >> s3;
		
		mp[s1] = s3;
		rmp[s3] = s1;
	}
	
	set<string> names;
	
	while(cin >> s){
		if(s == "END")
			break;
		
		if(s == "UNION"){
			cout << names.size() << endl;
		}
		else if(s == "FIND"){
			string s1, s2;
			cin >> s1 >> s2;
			string cur;
			if(s1 == "the")
				cur = rmp[s2];
			else
				cur = s2;
			
			if(names.count(cur))
				cout << "FOUND" << endl;
			else
				cout << "404" << endl;
		}
		else{
			string s1, s2;
			cin >> s1 >> s2;
			
			string cur;
			if(s1 == "the")
				cur = rmp[s2];
			else
				cur = s2;
			
			if(s == "+")
				names.insert(cur);
			else
				names.erase(cur);
		}
	}

	return 0;
}