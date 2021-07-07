#include <bits/stdc++.h>

using namespace std;

#ifdef DGC
#include "debug.h"
#else
#define debug(...)
#endif
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second
#define endl '\n'

bool vowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' || c == 'w';
}

int main()
{

	//#ifdef DGC
		freopen("consonant.in", "r", stdin);
		freopen("consonant.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	vector<int> idx(30);
	vector<vector<int>> f(30, vector<int>(30));
	int pos = 0;

	for(char c = 'a'; c <= 'z'; c++)
		if(!vowel(c))
			idx[c - 'a'] = pos++;


	string s;
	cin >> s;

	int n = (int)s.size();

	for(int i = 1; i < n; i++){
		if(!vowel(s[i - 1]) && !vowel(s[i])){
			int u = idx[s[i - 1] - 'a'];
			int v = idx[s[i] - 'a'];

			f[u][v]++;
			f[v][u]++;
		}
	}

	int ans = 0, mask = 0;

	for(int i = 1; i < (1 << pos); i++){

		int cur = 0;

		for(int j = 0; j < pos; j++)
			for(int k = j + 1; k < pos; k++){

				int b1 = (i & (1 << j)) == 0;
				int b2 = (i & (1 << k)) == 0;

				if(b1 != b2)
					cur += f[j][k];
			}

//		cout << i << " " << cur << endl;

		if(cur > ans){
			ans = cur;
			mask = i;
		}
	}
//
//	cout << ans << endl;
//	cout << mask << endl;

	for(int i = 0; i < n; i++){
		if(vowel(s[i]))
			cout << s[i];
		else{
			int u = idx[s[i] - 'a'];
			if(mask & (1 << u))
				cout << (char)toupper(s[i]);
			else
				cout << s[i];
		}
	}

	cout << endl;

	return 0;
}