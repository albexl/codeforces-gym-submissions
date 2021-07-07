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

int calc(vector<string> &a, vector<string> &b){
	int ans = 0;
	for(int i = 0; i < a.size(); i++)
		if(a[i] != b[i])
			ans++;
	
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	string line;
	getline(cin, line);
	
	int n;
	cin >> n;
	
	vector<vector<string>> lines(n);
	getline(cin, line);
	for(int i = 0; i < n; i++){
		getline(cin, line);
		string cur = "";
		for(int j = 0; j < line.size(); j++){
			if(line[j] == ','){
				lines[i].push_back(cur);
				cur = "";
			}
			else
				cur += line[j];
		}
		lines[i].push_back(cur);
	}
	
	int mn = 1e9;
	vector<vector<string>> ans;
	for(int i = 0; i < n; i++){
		
		int mx = -1;
		for(int j = 0; j < n; j++){
			if(i != j){
				int cnt = calc(lines[i], lines[j]);
				mx = max(mx, cnt);
			}
		}
		
		if(mx < mn){
			ans.clear();
			ans.push_back(lines[i]);
			mn = mx;
		}
		else if(mx == mn)
			ans.push_back(lines[i]);
		
	}
	
	for(auto &l : ans){
		for(int j = 0; j < l.size(); j++){
			cout << l[j];
			if(j + 1 != (int)l.size())
				cout << ",";
		}
		cout << endl;
	}

	return 0;
}