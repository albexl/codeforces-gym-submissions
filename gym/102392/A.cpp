#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
//typedef complex<ll> point;
#define F first
#define S second
#define ii pair<int,int>
#define iii pair<int,ii>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    //freopen("/home/adrian/CLionProjects/ICPC/test.txt", "r", stdin);

    int n, m;
    cin>>n>>m;

    vector<int> w(m + 1);
    vector<int> v(n);
    for(auto &i:v)
    {
        cin>>i;
        ++w[i];
    }

    vector<int> ac(m + 10);
    for(int i=0; i<n; i++)
    {
        int x = v[i], y = v[(i + 1) % n];
        if(x > y) swap(x, y);
        if(y - x > 1)
        {
            ++ac[x + 1];
            --ac[y];
        }
    }
    for(int i=0; i<n; i++)
    {
        int x = v[i], y =max(v[(i + n - 1) % n], v[(i + 1) % n]);
        if(x > y + 1)
        {
            --ac[y + 1];
            ++ac[x];
        }
    }

    for(int i=1; i<ac.size(); i++)
        ac[i] += ac[i - 1];

    for(int i=1; i<=m; i++)
        cout<<(w[i] == 0 ? -1 : n - w[i] + ac[i])<<" \n"[i == m];


    return 0;
}