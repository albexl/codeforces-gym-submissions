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

#define ii pair<int,int>

int mat[1005][1005];

void solve(vector<ii> &ans, int h, int w, int aum)
{
	if(h<=1)return;
	for(int i=0; i<h-1; i++)
		ans.push_back(ii(i+aum,aum));
	for(int j=1; j<w-1; j++)
		ans.push_back(ii(h-2+aum,j+aum));
	if(h>2 && w > 3)
	{
		for(int i=h-3; i>=0; i--)
			ans.push_back(ii(i+aum,w-2+aum));
		if(h>3)
			for(int j=w-3; j>=2; j--)
				ans.push_back(ii(aum,j+aum));
		if(h>5)
			ans.push_back(ii(aum+1,aum+2));
	}
	solve(ans,h-4,w-4,aum+2);
}

void solve_even(vector<ii> &ans, int h, int w)
{
	for(int i=1; i<h; i+=2)
	{
		if(i%4==1)
		{
			for(int j=1; j<w; j++)
				ans.push_back(ii(i,j));
			if(i+1<h)
				ans.push_back(ii(i+1,w-1));
		}
		else
		{
			for(int j=w-1; j>0; j--)
				ans.push_back(ii(i,j));
			if(i+1<h)
				ans.push_back(ii(i+1,1));
		}
	}
}

int main()
{
	#ifdef Adrian
		//freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int h,w;
	cin>>h>>w;
	vector<ii>ans;

	if (h < 2 || w < 2)
	{
		cout << "0\n";
		return 0;
	}

	if (h%2==0 || w%2 == 0)
	{
		bool b = h%2 == 1;
		if (b) swap(h, w);
		solve_even(ans, h, w);
		if (b)
		{
			swap(h, w);
			for (auto &i : ans)
				swap(i.F, i.S);
		}
	}
	else
	{
		bool b=(h>w);
		if(b)swap(h,w);

		bool ok = true;
		for (int i = 0; i < w-h; i += 2)
		{
			if (i/2 % 2 == 0)
			{
				for (int j = 0; j < h-1; ++j)
					ans.push_back(ii(j+1, i+1));
				ans.push_back(ii(h-2 + 1, i+1 + 1));
				ok = false;
			}
			else
			{
				for (int j = h-2; j >= 0; --j)
					ans.push_back(ii(j + 1, i + 1));
				ans.push_back(ii(1, i + 2));
				ok = true;
			}
		}

		if (!ok)
		{
			for (auto &i : ans)
				i.F = h - i.F;
		}

		vector<ii> ans2;
		solve(ans2,h,h,1);
		for (auto i : ans2)
			ans.push_back(ii(i.F, i.S + w-h));

		if(b)
		{
			swap(h, w);
			for(ii &v:ans)
				swap(v.first,v.second);
		}

	}

	cout<<ans.size()<<'\n';
	for(ii &v:ans)
		cout<<v.F<<" "<<v.S<<'\n';

	return 0;
}