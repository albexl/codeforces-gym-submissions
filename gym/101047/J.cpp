#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;

#define double long double

const double oo = 1e18;
const int maxn = 3e3 + 15;

double acum[maxn][maxn];
double dp[maxn][maxn];
bool seen[maxn][maxn];
char a[maxn], b[maxn];
int n, m, k, t;

double solve(int i, int j){
    if(i == n + 1 && j == m + 1)
        return (double)0;

    if(seen[i][j])
        return dp[i][j];
    seen[i][j] = true;

    double ans = oo;
    if(i <= n && j <= m && a[i] == b[j]){
        ans = min(ans, solve(i + 1, j + 1));
        if(i <= n)
        	solve(i + 1, j);
        if(j <= m)
        	solve(i, j + 1);
    }
    else{
    	if(i <= n && j <= m)
    		solve(i + 1, j + 1);
    	if(i <= n)
        	ans = min(ans, solve(i + 1, j) + (double)1);
    	if(j <= m)
        	ans = min(ans, solve(i, j + 1) + (double)1);
        double p1 = ((n - i + 1) == 0 ? (double)1 : (double) (n - i + 1));
	    double p2 = ((m - j + 1) == 0 ? (double)1 : (double) (m - j + 1));
	    double x = 0.0;

	    if(i < n + 1 && j < m + 1)
	    	x = acum[i + 1][j + 1];
	    else if(i == n + 1)
	    	x = acum[i][j + 1];
	    else if(j == m + 1)
	    	x = acum[i + 1][j];

	    x /= p1;
	    x /= p2;

	    ans = min(ans, (double)k + x);
    }

    dp[i][j] = ans;
    acum[i][j] = acum[i + 1][j] + acum[i][j + 1] - acum[i + 1][j + 1] + dp[i][j];

    return dp[i][j];
 }
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cout << setprecision(10) << fixed;

    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        for(int i = 1; i <= m; i++)
            cin >> b[i];

        for(int i = 1; i <= n + 10; i++)
            for(int j = 1; j <= m + 10; j++){
            	dp[i][j] = 0;
            	acum[i][j] = 0;
                seen[i][j] = false;
            }

        cout << solve(1, 1) << endl;
    }

    return 0;
}