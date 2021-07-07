#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	const int maxn = 1e6 + 5;

	vector<int> f;
	f.push_back(1);
	f.push_back(1);

	while(f.back() < maxn){

		int x = f[(int)f.size() - 1] + f[(int)f.size() - 2];
		f.push_back(x);
	}

	f.pop_back();

	vector<bool> fibs(maxn);
	vector<vector<int>> idx(maxn);

	for(auto &x : f)
		fibs[x] = true;

	int n;
	cin >> n;

	for(int i = 1, x; i <= n; i++){
		cin >> x;
		if(fibs[x])
			idx[x].push_back(i);
	}

	if((int)idx[1].size() > 1){
		cout << idx[1][0] << " " << idx[1][1] << endl;
		return 0;
	}

	for(int i = 1; i < (int)f.size() - 1; i++){
		int x = f[i];
		int y = f[i + 1];

		if((int)idx[x].size() && (int)idx[y].size()){
			cout << idx[x][0] << " " << idx[y][0] << endl;
			return 0;
		}
	}


	cout << "impossible" << endl;

	return 0;
}