#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;
 
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const ll mod = 1e9 + 7;

    int t;
    cin >> t;
    while(t--){

    	ll n, a, b;
    	cin >> n >> a >> b;

    	if(a >= n){
    		cout << 1 << endl;
    		continue;
    	}

    	if(a <= b){
    		cout << -1 << endl;
    		continue;
    	}

    	ll x = a - b;
    	ll lo = 0, hi = n + 10, pos = -1;
    	while(lo <= hi){
    		ll mid = (lo + hi) >> 1;
    		if(mid * x >= n - a){
    			pos = mid;
    			hi = mid - 1;
    		}
    		else lo = mid + 1;
    	}

    	ll cnt = pos * x;
    	if(cnt < n)
    		pos++;

    	cout << pos << endl;
    }
 

    return 0;
}