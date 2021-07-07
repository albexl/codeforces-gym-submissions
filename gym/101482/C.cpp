#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> tri;

const int maxn = 2e3 + 5;
const int maxk = 30;
const ll oo = 1e15;

ll dp[maxn][maxk];
ll a[maxn], b[maxn];

int n, d;

ll get(ll x){
	ll y = x / 10;
	ll ans = y * 10;
	if(x % 10 >= 5)
		ans += 10;
	return ans;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;
    d++;

    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	b[i] = b[i - 1] + a[i];
    }

    for(int i = 1; i <= n; i++)
    	for(int j = 0; j <= d; j++)
    		dp[i][j] = oo;

    for(int i = 1; i <= n; i++)
    	dp[i][1] = get(b[i]);

    for(int k = 2; k <= d; k++){

    	for(int i = 1; i <= n; i++){

    		for(int j = i - 1; j >= 1; j--){

    			ll sum = b[i] - b[j];
    			sum = get(sum);
    			dp[i][k] = min(dp[i][k], dp[j][k - 1] + sum);
    		}
    	}
    }

    ll ans = oo;
    for(int i = 1; i <= d; i++)
    	ans = min(ans, dp[n][i]);

    cout << ans << endl;

    return 0;
}