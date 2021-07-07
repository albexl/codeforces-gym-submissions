#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> graph;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("jingles.in", "r", stdin);
	freopen("jingles.out", "w", stdout);
//
	const int oo = 1e9;

	int t;
	cin >> t;
	while(t--){

		string s;
		cin >> s;

		int n = s.size();

		map<int, int> M;

		vector<vector<int>> nxt(n, vector<int>(26, oo));
		vector<int> cur(26, oo);

		for(int i = n - 1; i >= 0; i--){

			for(int j = 0; j < 26; j++)
				nxt[i][j] = cur[j];

			cur[s[i] - 'a'] = i;
		}

		for(int i = 0; i < n; i++){

			sort(nxt[i].begin(), nxt[i].end());

			int mask = 0;
			mask |= (1 << (s[i] - 'a'));

			for(int j = 0; j < 26; j++){
				if(nxt[i][j] == oo)
					break;

				int pos = nxt[i][j];

				int n_mask = mask;
				n_mask |= (1 << (s[pos] - 'a'));

				if(n_mask != mask){
					M[mask] = max(M[mask], pos - i);
					mask = n_mask;
				}

			}

			M[mask] = max(M[mask], n - i);
		}

		ll s1 = (ll)M.size(), s2 = 0;

		for(auto &e : M){
			ll b = 1LL * __builtin_popcount(e.first);
			ll c = 1LL * e.second;
			s2 += b * c;
		}

		cout << s1 << " " << s2 << endl;

	}

	return 0;
}