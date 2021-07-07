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
typedef complex<double> point;
#define F first
#define S second
#define ii pair<int,int>
#define iii pair<int,ii>

struct rmq
{
    vector<vector<ii>> dp;

    rmq(vector<ii> &a)
    {
        int n = (int)a.size(), lg = __lg(n);
        dp.resize(n, vector<ii>(lg + 1));

        for (auto &i : a)
			dp[&i - &a[0]][0] = i;

		for (int j = 1; j <= lg; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }

    ii query(int a, int b) // [a, b)
    {
        int l = __lg(b - a);
        return min(dp[a][l], dp[b - (1 << l)][l]);
    }
};

struct info
{
	vector<int> val;
	vector<int> ind;
	info(ii x, ii y, ii z)
	{
		vector<ii> temp={x,y,z};
		sort(temp.begin(),temp.end());
		val = {temp[0].F, temp[1].F, temp[2].F};
		ind = {temp[0].S, temp[1].S, temp[2].S};
	}
	bool operator <(info other)
	{
		if(val[0]==other.val[0] && val[1]==other.val[1])
			return val[2]<other.val[2];
		if(val[0]==other.val[0])
			return val[1]<other.val[1];
		return val[0]<other.val[0];
	}
};

int main()
{
	#ifdef Adrian
		freopen("a.txt", "r", stdin);
		//freopen("b.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin>>n;
	vector<int> v(n);
	vector<ii> w(2*n),y(n);
	for(int i=0; i<n; i++)
	{
		cin>>v[i];
		y[i] = w[i] = w[i + n] = ii(v[i], i);
	}

	rmq RMQ(w);

	sort(y.begin(), y.end());
	vector<info> ans;
	ans.push_back(info(y[0],y[1],y[2]));

	vector<int> t = {y[0].S, y[1].S, y[2].S};
	sort(t.begin(), t.end());
	queue<ii> q;
	q.push(ii(t[0],t[1]));
	q.push(ii(t[1],t[2]));
	q.push(ii(t[2],t[0]));

	while(!q.empty())
	{
		int l=q.front().F, r=q.front().S;
		q.pop();
		if((l+1)%n == r)continue;

		int a = (l+1)%n;
		int b = (r<a)?(r+n):r;
		ii mn = RMQ.query(a, b);

		ans.push_back(info(ii(v[l],l),ii(v[r],r),mn));

		int x=mn.S;
		if(x>=n)x-=n;

		q.push(ii(l,x));
		q.push(ii(x,r));
	}

	sort(ans.begin(), ans.end());

	for(auto &i:ans)
		cout<<i.ind[0]+1<<" "<<i.ind[1]+1<<" "<<i.ind[2]+1<<'\n';

	return 0;
}