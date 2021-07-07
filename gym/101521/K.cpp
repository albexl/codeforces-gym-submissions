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

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll r, d;
	cin >> r >> d;
	
	ll s1 = 0, s2 = 0;
	
	ll R = r + d;
	
	for(ll x = -R; x <= R; x++){
			
		ll lo = 0, hi = R, p1 = -1;
		
		while(lo <= hi){
			ll mid = (lo + hi) >> 1ll;
			
			if(mid * mid <= R * R - x * x){
				p1 = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		
		ll p2 = -p1;
		
		//if(p1 != -1 && p2 != -1)
		s1 += p1 - p2 + 1;
		
		
		//cout << x << " " << p1 << " " << p2 << endl;
		
	}
	
	R = r - d;
	
	if(R > 0){
		for(ll x = -R; x <= R; x++){

			ll lo = 0, hi = R, p1 = -R - 10;
			while(lo <= hi){
				ll mid = (lo + hi) >> 1ll;
				if(mid * mid < R * R - x * x){
					p1 = mid;
					lo = mid + 1;
				}
				else hi = mid - 1;
			}
			
			ll p2 = -p1;
			
			//if(p1 != -1 && p2 != -1)
			if(p1 != -R - 10)
				s2 += p1 - p2 + 1;
			
			//cout << x << " " << p2 << " " << p1 << endl;
			
		}
	}
	
	//cout << s1 << " " << s2 << endl;
	
	cout << s1 - s2 << endl;

	return 0;
}