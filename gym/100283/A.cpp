#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
bool solve(vector<int> &l, double r, int n){
    double sum = 0.0, pi = acos(-1), aux;
    for(int i = 0; i < n; ++i){
        aux = min(1.0 * l[i] / (2.0 * r), 1.0);
        sum += asin(aux);
        if(sum >= pi)
            return false;
    }
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  
    freopen("zeriba.in", "r", stdin);
    
    cout << setprecision(4) << fixed;
 
    int t, n, l;
   
    double base, top, mid, eps = 1e-9;
 
    cin >> t;
    for(int i = 0; i < t; ++i){
        cout << "Case " << i + 1 << ": ";
        int mx = 0, sum = 0;
        cin >> n;
        vector<int> wall(n);
        for(int j = 0; j < n; j++){
            cin >> wall[j];
            mx = max(wall[j], mx);
            sum += wall[j];
        }
        if(2 * mx >= sum){
            cout << "can't form a convex polygon\n";
            continue;
        }
 
        base = mx * 0.5;
        top = 1e9;
        for(int j = 0; j < 200; ++j){
            mid = (top + base) / 2.0;
            if(solve(wall, mid, n))
                top = mid;
            else
                base = mid;
        }
 
        cout << top << "\n";
 
    }
 
    return 0;
} //cicr