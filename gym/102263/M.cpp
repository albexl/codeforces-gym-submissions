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
	
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	
	stack<char> st;
	
	string ans = "";
	
	for(int i = 0; i < s.size(); i++){
		if(st.empty() || st.top() != s[i])
			st.push(s[i]);
		else{
			if(s[i] == 'z')
				st.push(s[i]);
			else{
				
				st.pop();
				st.push((char)(s[i] + 1));
				
				while(st.size() > 1 && st.top() != 'z'){
					char x = st.top();
					st.pop();
					char y = st.top();
					st.pop();
					if(x == y)
						st.push(x + 1);
					else
					{
						st.push(y);
						st.push(x);
						break;
					}
				}
			}
		}
	}
	
	while(!st.empty()){
		ans += st.top();
		st.pop();
	}

	reverse(ans.begin(), ans.end());
	
	cout << ans << endl;

	return 0;
}