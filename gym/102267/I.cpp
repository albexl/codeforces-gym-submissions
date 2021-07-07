#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

//#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int get_num(string s){
	if(s == "")
		return -1;
	int num = 0;
	for(int i = 0; i < s.size(); i++)
		num = num * 10 + (s[i] - '0');
	return num;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	vector<int> ans(n + 1, 0);
	
	stack<int> st;
	
	string cur = "";
	int pos = 0;
	while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9'){
		cur += s[pos];
		pos++;
	}
	
	int root = get_num(cur);
	st.push(root);
	
	while(pos < s.size()){
		
		//cout << pos << " :" << endl;
		
		if(s[pos] == '('){
			pos++;
			cur = "";
			while(pos < s.size() && s[pos] >= '0' && s[pos] <= '9'){
				cur += s[pos];
				pos++;
			}
			
			int child = get_num(cur);
			ans[child] = st.top();
			
			st.push(child);
			
		}
		else if(s[pos] == ')'){
			st.pop();
			pos++;
		}
	}
	
	
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];

	return 0;
}