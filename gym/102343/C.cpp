#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second
#define ii pair<ld, ld>
const ld eps=1e-9;

ii Rotate(ii x, ld angle)
{
	angle=angle*acos(-1)/180.0;
	return ii(x.F*cos(angle) - x.S*sin(angle), x.F*sin(angle) + x.S*cos(angle));
}


int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int l,w;
	cin>>l>>w;
	int h,x,y,a;
	cin>>h>>x>>y>>a;
	ii temp=ii((ld)h,0);
	temp=Rotate(temp,(ld)a);
	if((ld)x+temp.F>(ld)w+eps || (ld)x+temp.F<eps ||
		(ld)y+temp.S>(ld)l+eps || (ld)y+temp.S<eps)
		cout<<"NO";
	else
		cout<<"YES";

	return 0;
}