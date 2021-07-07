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
#define ii pair<ll,ll>

//ll evaluate (ii a, ll x)
//{
//	return a.F*x*x+a.S;
//}
//struct Li_Chao
//{
//	int L=0,R=0;
//	vector<ii> v;
//	Li_Chao(int sz){v=vector<ii>(sz);}
//
//	void Add(ii f, int l, int r, int cur=1)
//	{
//		int m=(l+r)/2;
//		bool lft=evaluate(f,l)<evaluate(v[cur],l);
//		bool mid=evaluate(f,m)<evaluate(v[cur],m);
//		if(mid)
//			swap(f,v[cur]);
//		if(l==r)return;
//		if(lft!=mid)
//			Add(f,l,m,2*cur);
//		else
//			Add(f,mid+1,2*cur+1);
//	}
//	double query(ll x, int l, int r, int cur)
//	{
//		int mid=(l+r)/2;
//		double temp=sqrt(v[cur].first*x*x+v[cur].second);
//		if(l==r)return temp;
//		if(x>mid)
//			return min(temp,query(x,mid+1,r,2*cur+1));
//		else
//			return min(temp,query(x,l,mid,2*cur));
//	}
//
//
//};

int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);
	ll m,a,b,c;
	cin>>m>>a>>b>>c;
	--b;--c;
	a%=m+1;
	b%=m+1;
	c%=m+1;
	if(a^b^c)
		cout<<"Tomaz";
	else
		cout<<"Danftito";


	return 0;
}