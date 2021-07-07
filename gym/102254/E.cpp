#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	unordered_set<string> mp;

	int cnt = 0;
	string ans = "";

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;

		if((int)s.size() < 4)
			continue;

		if(mp.find(s) == mp.end())
			mp.insert(s);
		else
			ans += s + "\n", cnt++;
	}

	if(cnt == 0)
		cout << "SAFO" << "\n";
	else{
		cout << cnt << "\n" << ans;
	}

	return 0;
}