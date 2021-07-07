#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex<ll> point;
#define F first
#define S second
#define ii pair<int,int>

string s;
ii solve(int pos)
{
	if(pos==s.size())return ii(0,0);
	ii temp=solve(pos+1);
	if(s[pos]=='1' || s[pos]=='3')
		temp.F+=(1<<(s.size()-pos-1));
	if(s[pos]=='2' || s[pos]=='3')temp.S+=(1<<(s.size()-pos-1));
	return temp;
}

int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	cin>>s;
	ii ans=solve(0);

	cout<<s.size()<<" "<<ans.F<<" "<<ans.S;

	return 0;
}