#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
const ll oo = 0x3f3f3f3f3f3f3f3f;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	ll k;

	cin >> s >> k;

	bool ok = true;
	for(int i = 0; i < s.length(); ++i)
	{
		if(s[i] != s[s.length() - i - 1])
			ok = false;
	}

	if(ok)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}