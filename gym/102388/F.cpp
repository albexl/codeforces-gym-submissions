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

    	int n, m;
    	cin >> n >> m;

    	vector<int> c(n);
    	for(int i = 0; i < n; i++)
    		cin >> c[i];

    	vector<ll> dp(m + 1);
    	dp[0] = 1;
    	for(auto &val : c)
    		for(int i = 1; i <= m; i++)	
    			if(i - val >= 0)
    				dp[i] = (dp[i] + dp[i - val]) % mod;
    			
    	cout << dp[m] << endl;
    }
 

    return 0;
}