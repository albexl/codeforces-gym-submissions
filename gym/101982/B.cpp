#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(short I = A;I < B;++I)
#define WAIT cout << flush,system("PAUSE");
#define sz(s) ((int)((s).size()))
#define endl '\n'
#define MAX 10000005

typedef long long ll;
typedef pair<short, short> pii;
typedef vector<int> vi;

const int maxn = 1e7 + 5;

std::vector <int> prime;
bool is_composite[maxn];
int mo[maxn];

void sieve (int n = maxn)
{
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i)
	{
		if (!is_composite[i])
		{
			prime.push_back (i);
			mo[i] = -1;
		}
		for (int j = 0; j < (int)prime.size(); ++j)
		{
			int x = i * prime[j];

			if(x >= maxn) break;
			is_composite[x] = true;

			if (i % prime[j] == 0)
			{
				mo[x] = 0;
				break;
			}
			else
				mo[x] = -mo[i];
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll mx = min(b, d) + 1;

    sieve();

    --a, --c;
    ll ans = (b - a) * (d - c);
    for(int i = 2; i < mx; ++i)
    	if(mo[i])
    		ans += mo[i] * (b / i - a / i) * (d / i - c / i);

    cout << ans << endl;

    return 0;
}