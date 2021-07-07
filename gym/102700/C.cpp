#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...) 9999
#endif

typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second
#define ii pair<ll,ll>
template<typename G1, typename G2 = G1, typename G3 = G1>
struct triple{ G1 F; G2 S; G3 T;};
typedef triple<ll> iii;


const ll mod = 1e9 + 7;
ll pot(ll a, ll b)
{
    ll x = 1;
    for(; b>0; b>>=1)
    {
        if(b & 1) x = x * a % mod;
        a = a * a % mod;
    }
    return x;
}
ll sum(ll a, ll b)
{
    a += b;
    if(a >= mod) a -= mod;
    if(a < 0) a += mod;
    return a;
}

int main()
{
#ifdef Adrian
    //freopen("quarantine_input.txt", "r", stdin);
    //freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif


    int n, m;
    cin>>n>>m;
    vector<ll> ans(m + 1);
    ll ret = 0;
    for(int i=1; i<=m; i++)
    {
        ans[i] = sum(pot(n, i), ans[i]);
        ret = sum(ret, ans[i]);
        for(int j=2 * i; j<=m; j+=i)
            ans[j] = sum(-ans[i], ans[j]);
    }

    cout<<ret<<'\n';

    return 0;
}