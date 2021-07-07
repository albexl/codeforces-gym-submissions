#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    string a,b;
    cin>>a>>b;

    int sz=b.size();

    for(int i=0; i<sz; i++)
    {
        int t=sz-i;
        if(t*100<99*sz)break;
        int pos=0;
        for(int j=0; j<sz; j++)
        {
            if(a[i+pos]==b[j])
                ++pos;
            if(pos*100>=99*sz)
            {
                cout<<"Long lost brothers D:";
                return 0;
            }
            if(i+pos==sz)break;
        }
    }
    cout<<"Not brothers :(";

    return 0;
}