#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

const int maxn = 15;
const int oo = 2e9;

int dp[1 << maxn][maxn][6];
//
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < (1 << n); i++)
    	for(int j = 0; j < n; j++)
    		for(int k = 0; k < 6; k++)
    			dp[i][j][k] = -oo;

    vector<vector<int>> v(n);
    vector<vector<vector<int>>> p(n);

    int ans = -oo;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 3; j++){
    		int x;
    		cin >> x;
    		v[i].push_back(x);
    	}
    	sort(v[i].begin(), v[i].end());
    	do{
    		p[i].push_back(v[i]);
    	}while(next_permutation(v[i].begin(), v[i].end()));
    }

    for(int i = 0; i < (1 << n); i++){
    	int b = __builtin_popcount(i);

    	if(b == 1){
    		for(int j = 0; j < n; j++)
    			if(i & (1 << j))
    				for(int k = 0; k < p[j].size(); k++){
    					dp[i][j][k] = p[j][k][2];
    					ans = max(ans, dp[i][j][k]);
    				}
    	}
    	else{
    		for(int j = 0; j < n; j++){
    			if(i & (1 << j)){

    				int prv = i ^ (1 << j);

    				for(int l = 0; l < n; l++){
    					if(prv & (1 << l)){

    						for(int k = 0; k < p[j].size(); k++){

    							for(int c = 0; c < p[l].size(); c++){


    								if(dp[prv][l][c] != -oo && p[j][k][0] <= p[l][c][0] && p[j][k][1] <= p[l][c][1]){
    									dp[i][j][k] = max(dp[i][j][k], dp[prv][l][c] + p[j][k][2]);
    									ans = max(ans, dp[i][j][k]);
    								}
    							}
    						}
    					}
    				}
    			}
    		}
    	}
    }

    cout << ans << endl;

    return 0;
}