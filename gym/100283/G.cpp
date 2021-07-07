#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

map<pair<ll, int>, bool> mp;

namespace mask
{
  const int B = 3;
  const int U = (1<<B)-1;
  inline int get(int p, ll m) { return m >> (B*p) & U; }
  inline ll set(int p, ll m, int v) { return ((ll)get(p, m) ^ v) << (B*p) ^ m; }
}

int it = 10;

bool solve(ll v, int sz, int left){

	// if(it){
	// 	it--;
	// 	cerr << v << " " << sz << " " << left << endl;
	// 	for(int i = 0; i < sz; i++)
	// 		cout << mask::get(i, v) << " ";
	// 	cout << endl;
	// }

	if(mp.find(make_pair(v, left)) != mp.end())
		return mp[{v, left}];

	bool win = false;
	for(int i = 0; i + 1 < sz; i++){
		
		if(mask::get(i, v) == 7){
			
			v = mask::set(i, v, mask::get(i, v) ^ 2);
			int nleft = left + 1;
			
			if(nleft == 3){
				v = mask::set(sz, v, 7);
				win |= !solve(v, sz + 1, 0);
			}
			else
				win |= !solve(v, sz, nleft);

			v = mask::set(i, v, mask::get(i, v) ^ 2);
		}

		if(mask::get(i, v) & 2){

			if(mask::get(i, v) & 1){
				v = mask::set(i, v, mask::get(i, v) ^ 1);
				int nleft = left + 1;
				
				if(nleft == 3){
					v = mask::set(sz, v, 7);
					win |= !solve(v, sz + 1, 0);
				}
				else
					win |= !solve(v, sz, nleft);

				v = mask::set(i, v, mask::get(i, v) ^ 1);
			}

			if(mask::get(i, v) & 4){
				v = mask::set(i, v, mask::get(i, v) ^ 4);
				int nleft = left + 1;
				
				if(nleft == 3){
					v = mask::set(sz, v, 7);
					win |= !solve(v, sz + 1, 0);
				}
				else
					win |= !solve(v, sz, nleft);

				v = mask::set(i, v, mask::get(i, v) ^ 4);
			}

		}
	}

	return mp[{v, left}] = win;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("jenga.in", "r", stdin);



    
    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++){

    	cout << "Case " << cases << ": ";

    	ll n;
    	cin >> n;
    	
    	cout << ( (n % 3 == 0) ? "Wahdan" : "Bakkar") << endl;

    }
    
    return 0;
    
}

//paridad del 3^k
//3 * 2^k           k >= 0
//3^j * 2^k         k >= 0, j >= 1