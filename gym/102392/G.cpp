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

    int n, m, h;
    cin>>n>>m>>h;

    vector<string> a(n);
    for(auto &i:a)
        cin>>i;

    vector<string>b(n);
    for(auto &i:b)
        cin>>i;

    vector<iii>mn, mx;
    auto generate = [&](vector<int> &x, vector<int> &y, int z)
    {
        int p = x.size(), q = y.size();
        mx.clear();
        for(int i=0; i<p; i++)
            for(int j=0; j<q; j++)
                mx.push_back({z, {x[i], y[j]}});

        mn.clear();
        int p1 = 0, p2 = 0;
        while(p - p1  > q)
            mn.push_back({z, {x[p1++], y[0]}});
        while(q - p2 > p)
            mn.push_back({z, {x[0], y[p2++]}});
        while(p1 < p && p2 < q)
            mn.push_back({z, {x[p1++], y[p2++]}});
    };

    vector<iii> Ans, ans;
    for(int i=0; i<n; i++)
    {
        vector<int> x, y;
        for(int j=0; j<m; j++)
            if(a[i][j] == '1')
                x.push_back(j);
        for(int j=0; j<h; j++)
            if(b[i][j] == '1')
                y.push_back(j);

        if(x.size() == 0 && y.size() == 0) continue;
        if((x.size() > 0 && y.size() == 0) || (x.size() == 0 && y.size() > 0))
        {
            cout<<"-1\n";
            return 0;
        }
        generate(x, y, i);
        for(auto &j:mx)
            Ans.push_back(j);
        for(auto &j:mn)
            ans.push_back(j);
    }

    sort(Ans.begin(), Ans.end());
    sort(ans.begin(), ans.end());

    cout<<Ans.size()<<'\n';
    for(auto &i:Ans)
        cout<<i.F<<" "<<i.S.F<<" "<<i.S.S<<'\n';

    cout<<ans.size()<<'\n';
    for(auto &i:ans)
        cout<<i.F<<" "<<i.S.F<<" "<<i.S.S<<'\n';

    return 0;
}