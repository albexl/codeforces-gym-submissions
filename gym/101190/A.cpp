#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'


typedef long long ll;
typedef pair<int, int> pii;

bool is_cap(string s){
	
	if(s.size() <= 1)
		return false;

	if(s[0] >= 'a' && s[0] <= 'z')
		return false;

	for(int i = 1; i < s.size(); i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			return false;

	return true;
}

void solve(vector<string> &v){
	if(v.empty())
		return;

	if(v.size() == 1){
		cout << v[0];
		return;
	}

	string pref = "";
	for(auto &w : v)
		if(w != " ")
			pref += w[0];

	cout << pref << " (";
	for(auto &w : v)
		cout << w;
	cout << ")";

}

 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("abbreviation.in", "r", stdin);
	freopen("abbreviation.out", "w", stdout);

	string s;


	while(getline(cin, s)){

		vector<string> tokens;

		string cur = "";

		for(int i = 0; i < (int)s.size(); i++){
			if(s[i] == '.' || s[i] == ',' || s[i] == ' '){
				if(cur != "")
					tokens.push_back(cur);
				cur = "";
				string nxt = "";
				nxt += s[i];
				tokens.push_back(nxt);
			}
			else{
				cur += s[i];
			}
		}

		if(cur != "")
			tokens.push_back(cur);


		vector<string> st;

		for(auto &tok : tokens){

			if(is_cap(tok))
				st.push_back(tok);
			else if(tok == " "){
				if(!st.empty() && st.back() != " ")
					st.push_back(tok);
				else if(!st.empty() && st.back() == " "){
					st.pop_back();
					solve(st);
					st.clear();
					cout << "  ";
				}
				else
					cout << tok;
			}
			else{
				if(!st.empty() && st.back() == " "){
					st.pop_back();
					solve(st);
					st.clear();
					cout << " ";
					cout << tok;
				}
				else if(!st.empty()){
					solve(st);
					st.clear();
					cout << tok;
				}
				else{
					cout << tok;
				}
			}
		}

		solve(st);

		cout << endl;


	}


	return 0;
}