#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

ll sum(ll x){
	return x * (x + 1) / 2;
}

ll sum_range(ll lo, ll hi){
	return sum(hi) - sum(lo - 1);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("army.in", "r", stdin);

    int t;
    cin >> t;
    for(int cases = 1; cases <= t; cases++){

    	ll n;
    	cin >> n;

    	if(n == 1){
    		cout << "Case " << cases << ": " << 1 << endl;
    		continue;
    	}

    	ll lo = 1, hi = 3e6 /2, pos = -1;
    	while(lo <= hi){
    		ll mid = (lo + hi) >> 1;
    		ll real_val = mid * (mid + 1) * (2 * mid + 1) / 6;
    		if(real_val < n){
    			pos = mid;
    			lo = mid + 1;
    		}
    		else hi = mid - 1;
    	}

    	ll ans = pos * pos;

    	n -= pos * (pos + 1) * (2 * pos + 1) / 6;

    	ll row = pos + 1;

    	lo = 1, hi = 2 * row - 1;

    	ll mid = hi / 2 + 1;

    	if(mid * (mid + 1) / 2 < n){
    		n -= mid * (mid + 1) / 2;
    		ans += mid;
    		lo = mid + 1;
    		ll x = mid;

    		lo -= mid;
    		hi -= mid;

     		while(lo <= hi){
    			mid = (lo + hi) >> 1;
    			ll s = sum_range(x - mid, x - 1);
    			if(s >= n){
    				pos = mid;
    				hi = mid - 1;
    			}
    			else lo = mid + 1;
    		}
    		ans += pos;
    	}
    	else{
    		hi = mid;
    		while(lo <= hi){
    			mid = (lo + hi) >> 1;
    			ll s = sum(mid);
    			if(s >= n){
    				pos = mid;
    				hi = mid - 1;
    			}
    			else lo = mid + 1;
    		}

    		ans += pos;
    	}

    	cout << "Case " << cases << ": " << ans << endl;
    }

    return 0;
    
}