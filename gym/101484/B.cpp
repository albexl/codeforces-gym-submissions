#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long ll;
typedef pair<ll, ll> pii;

struct segment_tree{

    vector<ll> st, lazy;

    segment_tree(int n) : st(4 * n), lazy(4 * n){ }

    void add_lazy(int node, int b, int e, ll x){
        st[node] += x * (e - b + 1);
        lazy[node] += x;
    }

    void push(int node, int b, int e){
        if(!st[node] || e == b)
            return;

        int m = (b + e) >> 1;
        int l = node << 1;
        int r = l | 1;

        add_lazy(l, b, m, lazy[node]);
        add_lazy(r, m + 1, e, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int b, int e, int i, int j, ll x){
        if(b >= i && e <= j){
            add_lazy(node, b, e, x);
            return;
        }

        if(b > j || e < i)
            return;

        int m = (b + e) >> 1;
        int l = node << 1;
        int r = l | 1;

        push(node, b, e);

        update(l, b, m, i, j, x);
        update(r, m + 1, e, i, j, x);

        st[node] = st[l] + st[r];
    }

    ll query(int node, int b, int e, int i, int j){
        if(b >= i && e <= j)
            return st[node];
        
        if(b > j || e < i)
            return 0;

        int m = (b + e) >> 1;
        int l = node << 1;
        int r = l | 1;
        
        push(node, b, e);

        ll L = query(l, b, m, i, j);
        ll R = query(r, m + 1, e, i, j);

        return L + R;
    }
};

struct event{

    ll x, yo, yi, val, id;

    event(ll x, ll yo, ll yi, ll val, ll id) : x(x), yo(yo), yi(yi), val(val), id(id){ }

    bool operator <(event e) const{
    	if(x == e.x)
    		return val < e.val;
    	return x < e.x;
    }

};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<event> e;

    vector<ll> ans(n);
    vector<pii> points(n);
    vector<pair<pii, pii>> rects(m);

    vector<ll> vals;

    for(int i = 0; i < n; i++){
    	cin >> points[i].first >> points[i].second;
    	vals.push_back(points[i].second);
    }

    for(int i = 0; i < m; i++){
    	ll xo, yo, xi, yi;
    	cin >> xo >> yo >> xi >> yi;
    	rects[i] = {{xo, yo}, {xi, yi}};
    	vals.push_back(yo);
    	vals.push_back(yi);
    }

    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());

    int N = 2 * vals.size() + 5;

    segment_tree st(N);

    for(int i = 0; i < n; i++){
    	ll x = points[i].first;
    	ll y = points[i].second;
    	e.push_back(event(x, y, -1, 0, i));
    }

    for(int i = 0; i < m; i++){
    	ll xo = rects[i].first.first;
    	ll yo = rects[i].first.second;
    	ll xi = rects[i].second.first;
    	ll yi = rects[i].second.second;

    	e.push_back(event(xo, yo, yi, +1, -1));
    	e.push_back(event(xi, yo, yi, -1, -1));
    }

    sort(e.begin(), e.end());

    for(auto &p : e){

    	if(p.val == 0){
    		int pos = lower_bound(vals.begin(), vals.end(), p.yo) - vals.begin();
    		pos *= 2;
    		ans[p.id] = st.query(1, 0, N - 1, pos + 1, pos + 1);
    		continue;
    	}

    	int lo = lower_bound(vals.begin(), vals.end(), p.yo) - vals.begin();
		int hi = lower_bound(vals.begin(), vals.end(), p.yi) - vals.begin();

		lo *= 2;
		hi *= 2;

		st.update(1, 0, N - 1, lo + 1, hi, 1ll * p.val);
    }

    for(int i = 0; i < n; i++)
    	cout << ans[i] << endl;

    return 0;
}