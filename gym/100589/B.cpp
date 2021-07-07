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

int h1, m1, s1, h2, m2, s2;

void move_next(){
	s1++;
	if(s1 == 60){
		s1 = 0;
		m1++;
		if(m1 == 60){
			m1 = 0;
			h1++;
			if(h1 == 24){
				h1 = 0;
			}
		}
	}
}

pii get(int x){
	if(x == 0)
		return {0, 0};
	if(x >= 1 && x < 10)
		return {0, x};
	vector<int> d;
	while(x){
		int y = x % 10;
		x /= 10;
		d.push_back(y);
	}
	return {d[1], d[0]};
}

bool pal(int a, int b, int c){
	vector<int> v;
	v.push_back(get(a).first);
	v.push_back(get(a).second);
	v.push_back(get(b).first);
	v.push_back(get(b).second);
	v.push_back(get(c).first);
	v.push_back(get(c).second);
	int lo = 0, hi = 5;
	while(lo <= hi){
		if(v[lo++] != v[hi--])
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	//mt19937 rng(5);
	//srand(time(0));
	
	const int maxn = 100000;
	h1 = 0, m1 = 0, s1 = 0;
	int idx = 1;
	map<pair<int, pii>, int> mp;
	vector<int> dp(maxn);
	
	while(true){
		pair<int, pii> M = {h1, {m1, s1}};
		mp[M] = idx;
		dp[idx] = dp[idx - 1];
		
		//printf("%d %d %d %d\n", h1, m1, s1, idx);
		
		if(pal(h1, m1, s1))
			dp[idx]++;
		move_next();
		idx++;
		if(h1 == 0 && m1 == 0 && s1 == 0)
			break;
	}
	
//	for(int i = 1; i <= 1000; i++)
	//	printf("%d %d\n", i, dp[i]);
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		
		
		scanf("%d:%d:%d", &h1, &m1, &s1);
		scanf("%d:%d:%d", &h2, &m2, &s2);
		
		pair<int, pii> M1 = {h1, {m1, s1}};
		pair<int, pii> M2 = {h2, {m2, s2}};
		int lo = mp[M1], hi = mp[M2];
		
		printf("%d\n", dp[hi] - dp[lo - 1]);
	}

	

	return 0;
}