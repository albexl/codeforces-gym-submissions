#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef pair<int, int> pii;
typedef long long ll;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);



	vector<vector<int>> g(5);
	vector<int> indeg(5);

	for(int i = 0; i < 5; i++){
		string op;
		cin >> op;

		int x = op[0] - 'A';
		int y = op[2] - 'A';

		if(op[1] == '>')
			g[y].push_back(x), indeg[x]++;
		else
			g[x].push_back(y), indeg[y]++;
	}

	vector<char> order;
	queue<int> Q;

	for(int i = 0; i < 5; i++)
		if(indeg[i] == 0)
			Q.push(i);

	while(!Q.empty()){
		int x = Q.front();Q.pop();

		order.push_back((char)(x + 'A'));

		for(auto &y : g[x]){
			indeg[y]--;
			if(indeg[y] == 0){
				Q.push(y);
			}
		}
	}

	if(order.size() == 5){
		for(auto &el : order)
			cout << el;
		cout << endl;
	}
	else{
		cout << "impossible" << endl;
	}
	

	return 0;
}