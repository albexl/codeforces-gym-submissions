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

struct point{
	ll x1, x2, x3, x4;
	
	bool operator< (point p) const{
		return x1 < p.x1;
	}
};

ll dist(point a, point b){
	ll ans = abs(a.x1 - b.x1) + abs(a.x2 - b.x2) + abs(a.x3 - b.x3) + abs(a.x4 - b.x4);
	return ans;
}

set<pair<ll, point>> S[16];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while(n--){
		int t;
		cin >> t;
		if(t == 1){
			point A;
			cin >> A.x1 >> A.x2 >> A.x3 >> A.x4;
			for(int i = 0; i < 16; i++){
				ll val = 0;
				for(int j = 0; j < 4; j++){
					ll x = 0;
					if(j == 0)
						x = A.x1;
					else if(j == 1)
						x = A.x2;
					else if(j == 2)
						x = A.x3;
					else
						x = A.x4;
					if(i & (1 << j))
						x = -x;
					val += x;
				}
				S[i].insert({val, A});
			}
		}
		else if(t == 2){
			point A;
			cin >> A.x1 >> A.x2 >> A.x3 >> A.x4;
			for(int i = 0; i < 16; i++){
				ll val = 0;
				for(int j = 0; j < 4; j++){
					ll x = 0;
					if(j == 0)
						x = A.x1;
					else if(j == 1)
						x = A.x2;
					else if(j == 2)
						x = A.x3;
					else
						x = A.x4;
					if(i & (1 << j))
						x = -x;
					val += x;
				}
				S[i].erase(S[i].find({val, A}));
			}
		}
		else{
			point A;
			cin >> A.x1 >> A.x2 >> A.x3 >> A.x4;
			
			ll ans = 0;
			for(int i = 0; i < 16; i++){
				auto cand = *(S[i].rbegin());
				ans = max(ans, dist(A, cand.second));
			}
			
			cout << ans << endl;
		}
	}
	

	return 0;
}