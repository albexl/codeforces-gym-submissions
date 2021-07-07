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
	
	int n;
	cin >> n;
	
	vector<string> v;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		v.push_back(s);
		v.push_back(" ");
	}
	
	v.pop_back();
	
	int m;
	cin >> m;
	
	stack<string> st;
	
	bool lower = true;
	
	for(int i = 0; i < m; i++){
		string s;
		cin >> s;
		if(s == "CapsLock")
			lower = !lower;
		else if(s == "Backspace"){
			if(!st.empty())
				st.pop();
		}
		else if(s == "Space")
			st.push(" ");
		else{
			
			string k = "";
			if(lower)
				k += tolower(s[0]);
			else
				k += toupper(s[0]);
			st.push(k);
		}
	}
	
	string a = "", b = "";
	
	for(int i = 0; i < v.size(); i++)
		a += v[i];
	
	while(!st.empty()){
		//cout << st.top() << " top" << endl;
		b += st.top();
		st.pop();
	}
	
	reverse(b.begin(), b.end());
	
	//cout << a << endl;
	//cout << b << endl;
	
	if(a == b)
		cout << "Correct" << endl;
	else
		cout << "Incorrect" << endl;
	
	

	return 0;
}