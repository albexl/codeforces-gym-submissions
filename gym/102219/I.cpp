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


	vector<string> v(3);

	for(int i = 0; i < 3; i++)
		cin >> v[i];

	int x = -1, y = -1;

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < v[i].size(); j++)
			if(v[i][j] == '=')
				x = i, y = j;

	while(y < v[x].size()){
		if(v[x][y] == 'T' || v[x][y] == 'H' || v[x][y] == 'P'){
			cout << v[x][y] << endl;
			return 0;
		}
		y++;
	}


	cout << "You shall pass!!!" << endl;
	

	return 0;
}