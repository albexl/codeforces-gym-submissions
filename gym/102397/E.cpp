#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n;
    ll x;
    cin >> n >> x;

    vector<ll> a(n + 1), s(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	s[i] = s[i - 1] + a[i];
    }

    int ans = -1;

    for(int i = 1; i <= n; i++){
    	int lo = i, hi = n, pos = -1;
    	while(lo <= hi){
    		int mid = (lo + hi) >> 1;
    		if(s[mid] - s[i - 1] >= x){
    			pos = mid;
    			hi = mid - 1;
    		}
    		else lo = mid + 1;
    	}

    	if(pos != -1){
    		if(ans == -1 || pos - i + 1 < ans)
    			ans = pos - i + 1;
    	}
    }

    cout << ans << endl;


    return 0;
}