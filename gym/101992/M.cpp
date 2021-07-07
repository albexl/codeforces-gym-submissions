#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...)
#endif
typedef long long ll;
typedef long double ld;
typedef complex<double> point;
#define F first
#define S second
#define ii pair<int,int>
#define iii pair<int,ii>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
	//#ifdef Adrian
		freopen("business.in", "r", stdin);
		//freopen("business.out", "w", stdout);
	//#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;

		vector<iii> shops(n);
		vector<ii> cust(m);

		for(auto &i:shops)
			cin>>i.F>>i.S.F>>i.S.S;
		for(auto &i:cust)
			cin>>i.F>>i.S;

		ordered_set <ii> s;
		priority_queue <ii> pq;
		int pos = 0;
		int ind = 0;

		for(int i = 0; i<m; i++)
		{
			while(pos < n && shops[pos].F <= cust[i].F)
			{
				s.insert(ii(shops[pos].S.F - shops[pos].F, ind++));
				pq.push(ii(-shops[pos].F - shops[pos].S.S, pos));
				++pos;
			}

			while(!pq.empty() && -pq.top().F < cust[i].F)
			{
				int temp = shops[pq.top().S].S.F - shops[pq.top().S].F;
				s.erase(s.lower_bound(ii(temp,-1)));
				pq.pop();
			}

			int lim = cust[i].S - cust[i].F;
			cout<<s.size() - s.order_of_key(ii(lim-1,1<<30))<<" \n"[i==m-1];
		}
	}



	return 0;
}