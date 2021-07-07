#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(x) (int)((x).size())
#define MAX 10000005
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	ios_base :: sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	vector<ll> solve;

	vector<bool> flag(MAX, false);

	flag[0] = flag[1] = 1;

	for(ll i = 2;i < MAX;++i){
		if(flag[i]) continue;
		solve.push_back(i);
		for(ll j = 2*i;j < MAX; j += i)
			flag[j] = 1;
	}

	cerr << "asdasd\n";

	for(int i = 0;i < 50;++i)
		random_shuffle(solve.begin(), solve.end());

	REP(i, 0, n){
		cout << solve[i] << " \n"[i == n - 1];
	}
}