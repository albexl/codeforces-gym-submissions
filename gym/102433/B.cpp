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


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	int n, k;
	cin >> n >> k;
	
	vector<bool> f(k + 5);
	vector<int> a(n + 5), val(n + 5);
	vector<vector<int>> pos(k + 5);
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
	
	for(int i = n - 1; i >= 0; i--){
		val[i] = val[i + 1];
		
		if(!f[a[i]])
			val[i]++;
		
		f[a[i]] = true;
		pos[a[i]].push_back(i);
	}

	set<pii> S;
	
	vector<int> ans;
	vector<bool> on(k + 5);
	int lo = 0, hi = 0;
	
	//for(int i = 0; i < n; i++)
	//	cerr << val[i] << " ";
	//cerr << endl;
	
	int rem = 0;
	for(int x = k; x >= 1; x--){
		
		//cerr << x << " :" << endl;
		//cerr << rem << endl;
		
		while(hi < n && val[hi] - rem >= x){
			if(!on[a[hi]])
				S.insert({a[hi], hi});
			else
				if(hi == pos[a[hi]][0])
					rem--;
			hi++;
		}
		
		auto mn = *(S.begin());
		
		//cerr << mn.first << " " << mn.second << endl;
		if(S.find(pii(mn.first, pos[mn.first][0])) == S.end())
			rem++;
		
		ans.push_back(mn.first);
		on[mn.first] = true;
		
		while(lo <= mn.second && lo < n){
			S.erase(pii(a[lo], lo));
			lo++;	
		}
		
		for(auto &p : pos[mn.first])
			S.erase(pii(mn.first, p));
	}
	
	
	for(int i = 0; i < k; i++)
		cout << ans[i] << " \n"[i + 1 == k];
	
	return 0;
}