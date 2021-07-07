#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
const ll oo = 0x3f3f3f3f3f3f3f3f;

const int maxn = 5000 + 5;

int g[maxn];

int grundy(int x){

	if(x == 1 || x == 0)
		return 0;

	if(x == 2)
		return 1;

	if(g[x] != -1)
		return g[x];

	set<int> S;

	for(int i = 0; i <= x - 2; i++)
		S.insert(grundy(i) ^ grundy(x - i - 2));

	int mx = 0;
	while(S.find(mx) != S.end())
		mx++;

	return g[x] = mx;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(g, -1, sizeof(g));

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		n = grundy(n);
		cout << (n ? "First" : "Second") << endl;
	}


	return 0;
}