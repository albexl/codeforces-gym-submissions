#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);

    string s;
    cin>>s;
    int sz=s.size();
    int mn=1e9;
    vector<char> l,r;
    for(int i=0; i<sz; i++)l.push_back(s[i]);
    while(true)
    {
        bool pal=true;
        int pos=0;
        for(; pos<r.size(); pos++)
            if(r[pos]!=l[pos])pal=false;

        for(int i=0; pos+i<sz-i-1; i++)
            if(l[pos+i]!=l[sz-i-1])pal=false;

        if(pal)break;
        int temp=r.size();
        r.push_back(l[temp]);
    }
    cout<<s;
    for(int i=r.size()-1; i>=0; i--)
        cout<<r[i];

    return 0;
}