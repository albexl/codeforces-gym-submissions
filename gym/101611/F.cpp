#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;

struct team{

	string name;
	int acc;
	int last_acc;
	int penalty;

	team(string s){
		name = s;
		acc = 0;
		last_acc = 0;
		penalty = 0;
	}

};

bool cmp(team a, team b){
	if(a.acc != b.acc)
		return a.acc > b.acc;
	if(a.penalty != b.penalty)
		return a.penalty < b.penalty;
	if(a.last_acc != b.last_acc)
		return a.last_acc < b.last_acc;
	return a.name < b.name;
}
 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	vector<team> frozen;

	for(int i = 0; i < m; i++){
		string name;
		cin >> name;

		team cur(name);

		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			int a, t;
			cin >> a >> t;

			if(c == '+')
				cur.acc++, cur.last_acc = max(cur.last_acc, t), cur.penalty += 20 * (a - 1) + t;

		}

		frozen.push_back(cur);
	}

	vector<team> leak;
	for(int i = 0; i < k; i++){
		string name;
		cin >> name;

		team cur(name);

		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			int a, t;
			cin >> a >> t;

			if(c == '+')
				cur.acc++, cur.last_acc = max(cur.last_acc, t), cur.penalty += 20 * (a - 1) + t;

		}

		leak.push_back(cur);
	}

	vector<team> real;

	for(int i = 0; i < m; i++){
		bool found = false;
		for(int j = 0; j < k; j++){
			if(leak[j].name == frozen[i].name){
				found = true;
				real.push_back(leak[j]);
				break;
			}
		}

		if(!found)
			real.push_back(frozen[i]);
	}

	sort(real.begin(), real.end(), cmp);

	// cout << "-----------------" << endl;
	// for(auto &t : real)
	// 	cout << t.name << " " << t.acc << " " << t.penalty << " " << t.last_acc << endl;
	// cout << "-----------------" << endl;

	bool ok = true;
	int cnt = 0;
	for(int i = 0; i < (int)real.size(); i++){
		if(real[i].name == leak[0].name){

			for(int j = i; cnt < k && j < (int)real.size(); j++, cnt++){

				if(real[j].name != leak[cnt].name){
					ok = false;
					break;
				}
			}
		}
	}

	if(cnt < k)
		ok = false;

	cout << (ok ? "Leaked" : "Fake") << endl;


	return 0;
}