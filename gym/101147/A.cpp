#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> tri;

const int maxn = 500;

int dp[maxn][maxn];

int grundy(int n, int k){

	if(n == 0)
		return 0;

	if(dp[n][k] != -1)
		return dp[n][k];

	set<int> s;
	if(k == 1)
		s.insert(grundy(n - 1, k));
	else{
		for(int i = 1; i <= n; i *= k)
			s.insert(grundy(n - i, k));
	}
	
	
	int mx = 0;
	while(s.find(mx) != s.end())
		mx++;
	return dp[n][k] = mx;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("powers.in", "r", stdin);

    int tc;
    cin >> tc;

    while(tc--){
    	int m;
    	cin >> m;

    	int ans = 0;

    	for(int i = 0; i < m; i++){
    		int n, k;
    		cin >> n >> k;

    		swap(n, k);

    		if(k % 2)
    			ans ^= (n % 2);
    		else{
    			int rem = n % (k + 1);
    			if(rem == k)
    				ans ^= 2;
    			else
    				ans ^= (rem % 2);
    		}
    	}

    	cout << (ans ? 1 : 2) << endl;

    }

    return 0;
}