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



int main()
{
#ifdef Adrian
    //freopen("quarantine_input.txt", "r", stdin);
    //freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif


    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)
        cin>>i;

    vector<int> l(n);
    stack<int> s;
    for(int i=0; i<n; i++)
    {
        int in = i;
        while(!s.empty() && v[i] >= v[s.top()])
        {
            if(v[s.top()] == v[i])
                in = s.top();
            s.pop();
        }
        if(s.empty()) l[i] = -1;
        else l[i] = s.top();

        s.push(in);
    }

    vector<int> r(n);
    while(!s.empty()) s.pop();
    for(int i=n-1; i>=0; i--)
    {
        int in = i;
        while(!s.empty() && v[i] >= v[s.top()])
        {
            if(v[s.top()] == v[i])
                in = s.top();
            s.pop();
        }
        if(s.empty()) r[i] = n;
        else r[i] = s.top();

        s.push(in);
    }

    vector<ii> w;
    for(int i=0; i<n; i++)
        w.push_back({v[i], i});

    sort(w.rbegin(), w.rend());

    vector<ll> ans(n);
    for(int i=0; i<n; i++)
    {
        int p = w[i].S;
        if(l[p] != -1)
            ans[p] = max(ans[p], ans[l[p]] + p - l[p]);
        if(r[p] != n)
            ans[p] = max(ans[p], ans[r[p]] + r[p] - p);
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<" \n"[i == n - 1];


    return 0;
}