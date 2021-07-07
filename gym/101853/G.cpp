#include <bits/stdc++.h>

using namespace std;

#ifdef MOG
#define WAIT
#else
#define WAIT cout<<flush, system("PAUSE")
#endif

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(s) ((int)((s).size()))
#define endl '\n'
#define MAX 500100
#define double long double

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<int, pii> tri;

typedef pii point;
typedef vector<point> polygon;

#define NEXT(i) (((i) + 1) % n)



typedef long long ll;

ll euler_phi(ll n)
{
	if (n == 0)
		return 0;
	ll ans = n;
	for (ll x = 2; x * x <= n; ++x)
		if (n % x == 0)
		{
			ans -= ans / x;
			while (n % x == 0)
				n /= x;
		}
	if (n > 1)
		ans -= ans / n;
	return ans;
}

ll pow(ll a, ll b, ll M)
{
	if ( b == 0 ) return 1;
	if ( b & 1LL  ) return (a * pow(a, b-1, M))%M;
	ll p = pow(a, b/2, M);
	return (p*p)%M;
}

map<ll, ll> _hash;

ll dlog(ll a, ll b, ll M)
{
	_hash.clear();
	ll n = euler_phi(M), k = sqrt(n);
	b %= M;
	a %= M;
	for(ll i = 0, t = 1; i < k; ++i)
	{
		_hash[t] = i;
		if(b == t) return i;
		t = (t * a) % M;
	}
	ll c = pow(a, n - k, M);
	for(ll i = 0; i * k < n; i++)
	{
		if(_hash.find(b) != _hash.end())
			return i * k + _hash[b];
		b = (b * c) % M;
	}
	return -1;
}

ll BF(ll a, ll b, ll M)
{
	ll i = 0, t = 1;
	for(;i*i <= M; ++i)
	{

		if(b == t) return i;
		t = (t * a) % M;
	}
	if(b == t) return i;
	return -1;
}


ll Solve(ll a, ll b, ll m)
{
	a %= m; b %= m;
	int s = -1;
	if(s == -1)
	{
		int s2 = dlog(a, b,m);
		if(pow(a, s2, m) == b) return s2;
		return -1;
	}
	return s;
}



int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--)
    {
		ll a, b, m;
		cin >> a >> b >> m;
		cout << Solve(a, b, m) << "\n";
    }

}