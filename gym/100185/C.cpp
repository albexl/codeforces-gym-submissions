#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;


const int oo = 2e9;
const int maxn = 2e3 + 5;

int l1, l2, n;
int a[maxn];

int solve(int x, int i, int j, int k){
	
	int lo = 0, hi = n - 1, opt = -1;
	while(lo <= hi){
		int mid = (lo + hi) >> 1;
		if(a[mid] <= x){
			opt = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	
	while(opt == i || opt == j || opt == k)
		opt--;
	
	return opt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	
	cin >> l1 >> l2 >> n;
	
	int ans = -oo;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a, a + n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j)
				continue;
		
			int p1 = solve(l1 - a[i], i, j, -5);
			if(p1 < 0)
				continue;
			int p2 = solve(l2 - a[j], i, j, p1);
			if(p2 < 0)
				continue;
			ans = max(ans, a[i] + a[j] + a[p1] + a[p2]);
		}
	}
	
	if(ans <= 0)
		cout << "Impossible" << endl;
	else
		cout << ans << endl;

	return 0;
}