    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define endl '\n'
    #define MAX
     
    typedef long long ll;
    typedef pair<int,int> pii;
     
     
    int main(){
      ios_base::sync_with_stdio(0);
      cin.tie(0);
     
      int n;
      cin >> n;
     
      vector<int> v(n), a(n);
     
      for(int i = 0; i < n; i++){
        cin >> v[i];
        a[i] = v[i];
      }
     
      sort(a.begin(), a.end());
      a.resize(unique(a.begin(), a.end()) - a.begin());
     
      int ans = 0;
     
      vector<int> cur;
      vector<vector<int>> groups;
      set<pii> adj;
      
      for (auto &i : v)
        i = lower_bound(a.begin(), a.end(), i) - a.begin();
     
      cur.push_back(v[0]);
      for(int i = 1; i < n; i++){
     
        if(v[i] == cur.back())
          continue;
     
        if(v[i] < cur.back()){
          groups.push_back(cur);
          cur.clear();
          cur.push_back(v[i]);
          ans++;
        }
        else{
          int p1 = v[i];
          int p2 = cur.back();
     
          if(p1 == p2 + 1)
            cur.push_back(v[i]);
          else{
            groups.push_back(cur);
            cur.clear();
            cur.push_back(v[i]);
            ans++;
          }
        }
      }
     
      if(!cur.empty())
        groups.push_back(cur);
        
      vector<int> mp(n);
      sort(groups.begin(), groups.end(), [](const vector<int> &x, vector<int> &y){ return x[0] < y[0]; });
      for (auto g : groups)
        for (auto i : g)
            mp[i]++;
     
      for(auto &g : groups){
        ans += (int)g.size() - 1;
        reverse(g.begin(), g.end());
        bool ok = true;
        while (g.size() > 1)
        {
            int x = g.back();
            g.pop_back();
            int y = g.back();
            
            //cout << x << " " << y << endl;
            if (mp[x] == 1 || mp[y] == 1)
            {
                ok = true;
              adj.insert({x, y});
            }
            if (ok && adj.find({ x, y }) == adj.end())
            {
                ok = false;
                adj.insert({x, y});
            }
            else
                ok = true;
        }
      }
     
     //cout << ans << endl;
     //cout << adj.size() << endl;
      ans -= (int)adj.size();
     
      cout << ans << endl;
     
      return 0;
    }