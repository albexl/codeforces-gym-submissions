#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int maxn = 1e5 + 5;

ll sum[4 * maxn], pref[4 * maxn], suff[4 * maxn], st[4 * maxn], a[maxn];


void build(int node, int b, int e){
	if(b == e){
		sum[node] = a[b];
		st[node] = a[b];
		pref[node] = a[b];
		suff[node] = a[b];
	}
	else{
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		build(l, b, m);
		build(r, m + 1, e);
		
		st[node] = suff[l] + pref[r];
		st[node] = max(st[node], st[l]);
		st[node] = max(st[node], st[r]);
		
		sum[node] = sum[l] + sum[r];
		
		pref[node] = max(pref[l], sum[l] + pref[r]);
		suff[node] = max(suff[r], sum[r] + suff[l]);
		
	}
}

void update(int node, int b, int e, int p, ll x){
	if(b == e){
		sum[node] = x;
		st[node] = x;
		pref[node] = x;
		suff[node] = x;
	}
	else{
		int m = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		if(p <= m)
			update(l, b, m, p, x);
		else
			update(r, m + 1, e, p, x);
		
		st[node] = suff[l] + pref[r];
		st[node] = max(st[node], st[l]);
		st[node] = max(st[node], st[r]);
		
		sum[node] = sum[l] + sum[r];
		
		pref[node] = max(pref[l], sum[l] + pref[r]);
		suff[node] = max(suff[r], sum[r] + suff[l]);
		
	}
}

ll query(){
	return st[1];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	ll x;
	cin >> x;
	
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	build(1, 1, n);
	
	for(int i = 1; i <= n; i++){
		update(1, 1, n, i, x);
		cout << query() << " \n"[i == n];
		update(1, 1, n, i, a[i]);
	}

	return 0;
}