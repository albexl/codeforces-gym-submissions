#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
const ll oo = 0x3f3f3f3f3f3f3f3f;

map<ll, int> M;
vector<pii> ans;

void solve(ll n)
{
	if(M.find(n) != M.end()) return;

	if(n == 1)
	{
		M[n] = ans.size();
		ans.emplace_back(-1, -1);
		return;
	}

	ll m = n >> 1;
	solve(m), solve(n - m);

	M[n] = ans.size();
	ans.emplace_back(M[n - m], M[m]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int c;
	cin >> c;

	while(c--)
	{
		ll n; cin >> n;
		M.clear(), ans.clear();
		solve(n);

		cout << ans.size() << endl;
		for(auto &e : ans)
			cout << e.first << " " << e.second << endl;
		cout << ans.size() - 1 << endl;
	}
}