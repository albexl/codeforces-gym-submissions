#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<int, int> pii;

 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const int oo = 2e9;

    cout << setprecision(10) << fixed;

    int tc;
    cin >> tc;

    while(tc--){

        int n, m, k;
        cin >> n >> m >> k;

        vector<vector<pii>> g(n);

        for(int i = 0, a, b, c; i < m; i++){
            cin >> a >> b >> c;
            a--, b--;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }

        vector<int> f(n, oo);
        f[n - 1] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, n - 1});
        while(!pq.empty()){
            int u = pq.top().second;
            int w = pq.top().first;
            pq.pop();

            if(w != f[u])
                continue;

            for(auto &e : g[u]){
                int v = e.first;
                int cost = e.second;
                if(f[v] > f[u] + cost){
                    f[v] = f[u] + cost;
                    pq.push({f[v], v});
                }
            }
        }

        long long s = 0;
        vector<pair<int, int>> fs(n);
        for (int i = 0; i < n; ++i)
            fs[i] = { f[i], i };

        sort(fs.begin(), fs.end());

        int pos = -1;
        for (int i = 0; i < n; ++i)
            if (fs[i].second == 0)
                pos = i;

        long double ans = fs[pos].first;
        for (int i = 1; i < n; ++i)
        {
            s += fs[i-1].first;
            int t = n-i;
            long double v = ((long double)(s + ((ll)n)*k)) / (n - t);
            if (v <= f[i] && pos >= i)
                ans = min(ans, v);
        }
        
        cout << ans << '\n';
    }
 
    return 0;
}