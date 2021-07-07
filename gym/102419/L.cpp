#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

bool sum(string &s){
	for(auto &c : s)
		if(c == '+')
			return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("dislodging_logs_input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	vector<pair<string, vector<string>>> opA, opB;
	map<string, string> mp;

	string line;
	
	getline(cin, line);	
	for(int i = 0; i < n; i++){
		getline(cin, line);
		string op = "", var = "";
		vector<string> vars;

		if(sum(line)){
			op = "sum";
			int pos = 0;
			while(pos < line.size() && line[pos] != '='){
				var += line[pos];
				pos++;
			}
			vars.push_back(var);
			pos++;
			var = "";
			while(pos < line.size() && line[pos] != '+'){
				var += line[pos];
				pos++;
			}
			vars.push_back(var);
			pos++;
			var = "";
			while(pos < line.size()){
				var += line[pos];
				pos++;
			}
			vars.push_back(var);
		}
		else{
			int pos = 0;
			while(pos < line.size() && line[pos] != ' '){
				op += line[pos];
				pos++;
			}

			pos++;
			while(pos < line.size()){
				var += line[pos];
				pos++;
			}

			vars.push_back(var);
		}

		opA.push_back({op, vars});
	}

	int m;
	cin >> m;

	getline(cin, line);
	for(int i = 0; i < m; i++){
		getline(cin, line);
		string op = "", var = "";
		vector<string> vars;

		if(sum(line)){
			op = "sum";
			int pos = 0;
			while(pos < line.size() && line[pos] != '='){
				var += line[pos];
				pos++;
			}
			vars.push_back(var);
			pos++;
			var = "";
			while(pos < line.size() && line[pos] != '+'){
				var += line[pos];
				pos++;
			}
			vars.push_back(var);
			pos++;
			var = "";
			while(pos < line.size()){
				var += line[pos];
				pos++;
			}
			vars.push_back(var);
		}
		else{
			int pos = 0;
			while(pos < line.size() && line[pos] != ' '){
				op += line[pos];
				pos++;
			}

			pos++;
			while(pos < line.size()){
				var += line[pos];
				pos++;
			}

			vars.push_back(var);
		}

		opB.push_back({op, vars});
	}
	
	if(n != m){
		cout << "NO" << endl;
		return 0;
	}

	for(int i = 0; i < n; i++){
		if(opA[i].first != opB[i].first){
			cout << "NO" << endl;
			return 0;
		}

		if(opA[i].first == "define")
			mp[opA[i].second[0]] = opB[i].second[0];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < opA[i].second.size(); j++){
			if(mp[opA[i].second[j]] != opB[i].second[j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;

	return 0;
}