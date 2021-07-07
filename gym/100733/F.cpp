#include <bits/stdc++.h>
     
    using namespace std;
     
    #define endl '\n'
     
    typedef long long ll;
    typedef pair<ll, ll> pii;
     
    struct segment_tree{
     
      vector<ll> st;
     
      segment_tree(int n) : st(4 * n) { }
     
      void update(int node, int b, int e, int pos, ll val){
        if(b == e)
          st[node] = max(st[node], val);
        else{
          int m = (b + e) >> 1;
          int l = node << 1;
          int r = l | 1;
     
          if(pos <= m)
            update(l, b, m, pos, val);
          else
            update(r, m + 1, e, pos, val);
     
          st[node] = max(st[l], st[r]);
        }
      }
     
      ll query(int node, int b, int e, int i, int j){
        if(b >= i && e <= j)
          return st[node];
        if(b > j || e < i)
          return -1;
     
        int m = (b + e) >> 1;
        int l = node << 1;
        int r = l | 1;
     
        ll L = query(l, b, m, i, j);
        ll R = query(r, m + 1, e, i, j);
     
        return max(L, R);
      }
     
    };
     
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
     
        int n;
        cin >> n;
     
        vector<pair<ll, pii>> v(n);
        vector<ll> vals;
     
        for(int i = 0; i < n; i++){
          cin >> v[i].first >> v[i].second.first >> v[i].second.second;
          vals.push_back(v[i].first);
          vals.push_back(v[i].first - v[i].second.second);
        }
     
        sort(vals.begin(), vals.end());
        vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
     
        int N = vals.size();
        segment_tree st(N);
     
        ll ans = 0;
     
        for(int i = 0; i < n; i++){
          int lo = lower_bound(vals.begin(), vals.end(), v[i].first - v[i].second.second) - vals.begin();
          int hi = lower_bound(vals.begin(), vals.end(), v[i].first) - vals.begin();
     
          ll x = st.query(1, 0, N - 1, lo, hi);
          ans = max(ans, x + v[i].second.first);
     
          st.update(1, 0, N - 1, hi, x + v[i].second.first);
        }
     
        cout << ans << endl;
     
        return 0;
    }