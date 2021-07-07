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

typedef vector<point> polygon;
#define NEXT(i) (((i) + 1) % n)
ll cross(point a, point b) { return imag(conj(a) * b); }

ll area2(const polygon &P)
{
    ll A = 0;
    for (int i = 0, n = P.size(); i < n; ++i)
        A += cross(P[i], P[NEXT(i)]);
    return A;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    int n;
    cin>>n;

    ll ans = 0;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;

        polygon pol;
        for(int i=0; i<k; i++)
        {
            int x, y;
            cin>>x>>y;
            pol.push_back({x, y});
        }

        ans += abs(area2(pol));
    }

    cout<<ans / 2<<'\n';

    return 0;
}