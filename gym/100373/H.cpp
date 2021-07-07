#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<pii>> graph;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;


	map<int, int> M;
	for(int i = 0, x; i < n; ++i)
	{
		cin >> x, ++M[x];
		if(M[x] == k) M.erase(x);
	}

	for(auto &e : M)
		if(e.second < k)
			cout << e.first << endl;

	return 0;
}