#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

int similar(vector<int> &a, vector<int> &b){

	int ans = 0;
	for(int i = 0, j = 0; i < (int)a.size() && j < (int)b.size();){

		if(a[i] == b[j]){
			++ans;
			i++;
			j++;
		}
		else if(a[i] < b[j])
			i++;
		else
			j++;
	}
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("detect.in", "r", stdin);
	freopen("detect.out", "w", stdout);


	int n;
	cin >> n;

	vector<string> a(n);

	string dummy;
	getline(cin, dummy);

	for(int i = 0; i < n; i++)
		getline(cin, a[i]);


	vector<vector<int>> hashes(n);

	int m = a[0].size();

	for(int i = 0; i < n; i++){

		vector<int> block;

		for(int j = 0; j < m; j++){

			block.push_back(a[i][j] - 32);
			if(j % 4 == 3){
				sort(block.begin(), block.end());
				int num = block[0];
				num *= 100;
				num += block[1];
				num *= 100;
				num += block[2];
				num *= 100;
				num += block[3];
				hashes[i].push_back(num);
				block.clear();
			}
		}

		sort(hashes[i].begin(), hashes[i].end());

	}

	vector<pair<int, pii>> edges;

	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++){
			edges.push_back({similar(hashes[i], hashes[j]), {i, j}});
//			cout << i << " " << j << " " << similar(hashes[i], hashes[j]) << endl;
		}
	sort(edges.rbegin(), edges.rend());

	vector<bool> rands(n, false);
	int cnt = 0;

	for(int i = 0; i < (int)edges.size(); i++){
		int x = edges[i].second.first;
		int y = edges[i].second.second;

		if(!rands[x]){
			rands[x] = true;
			cnt++;
			if(cnt == n / 2)
				break;
		}

		if(!rands[y]){
			rands[y] = true;
			cnt++;
			if(cnt == n / 2)
				break;
		}
	}


	for(int i = 0; i < n; i++)
		cout << (rands[i] ? "block" : "random") << endl;


	return 0;
}