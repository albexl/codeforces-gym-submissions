#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define double ld
typedef complex<ll> point;
#define F first
#define S second
#define ii pair<int,int>
#define iii pair<int,ii>

struct rmq
{
    vector<vector<ii>> dp;

    rmq(vector<ii> &a)
    {
        int n = a.size(), lg = __lg(n);
        dp.resize(n, vector<ii>(lg+1));

        for (auto &i : a) dp[&i-&a[0]][0] = i;
        for (int j = 1; j <= lg; ++j)
            for (int i = 0; i+(1<<j) <= n; ++i)
                dp[i][j] = min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
    }

    ii query(int a, int b) // [a, b)
    {
        int l = __lg(b - a);
        return min(dp[a][l], dp[b-(1<<l)][l]);
    }
};

ll mod = 1e9 + 7;
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

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    const int MAXN = 2e6 + 6;
    vector<ll>fact(MAXN), inv(MAXN);
    fact[0] = inv[0] = 1;
    for(int i=1; i<MAXN; i++)
    {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = pot(fact[i], mod - 2);
    }
    auto comb = [&](int m, int n)
    {
        return fact[m] * inv[n] % mod * inv[m - n] % mod;
    };

    int n;
    cin>>n;

    vector<ii> v(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i].F;
        v[i].S = i;
    }

    rmq rm(v);

    ll ans = 1;
    queue<ii> q;
    q.push({0, n - 1});
    while(!q.empty())
    {
        int l = q.front().F;
        int r = q.front().S;
        q.pop();

        if(l >= r) continue;

        ii temp = rm.query(l, r + 1);

        q.push({l, temp.S - 1});
        l = temp.S + 1;
        int cant = 1;
        while(l <= r)
        {
            ii t = rm.query(l, r + 1);
            if(t.F != temp.F)
            {
                q.push({l, r});
                break;
            }

            ++cant;
            q.push({l, t.S - 1});
            l = t.S + 1;
        }

        ans = ans * comb(2 * cant, cant) % mod * pot(cant + 1, mod - 2) % mod;
    }

    cout<<ans<<'\n';

    return 0;
}