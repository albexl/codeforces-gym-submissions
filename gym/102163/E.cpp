#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<int, pair<int, int>> tri;

const int maxn = 1e5 + 5;
const ll b = 331;

ll pows[maxn];
char s[maxn];

struct segment_tree{
	
	vector<unsigned long long> H, HR;
	
	segment_tree(int n) : H(4 * n), HR(4 * n){
		build(1, 1, n);
	}
	
	void build(int node, int b, int e){
		if(b == e){
			H[node] = HR[node] = s[b - 1] - 'a' + 1;
		}
		else{
			int mid = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			
			build(l, b, mid);
			build(r, mid + 1, e);
			
			H[node] = H[l] * pows[e - mid] + H[r];
			HR[node] = HR[r] * pows[mid - b + 1] + HR[l];
		}
	}
	
	void update(int node, int b, int e, int p, char c){
		if(b == e){
			H[node] = HR[node] = c - 'a' + 1;
		}
		else{
			int mid = (b + e) >> 1;
			int l = node << 1;
			int r = l | 1;
			
			if(p <= mid)
				update(l, b, mid, p, c);
			else
				update(r, mid + 1, e, p, c);
			
			H[node] = H[l] * pows[e - mid] + H[r];
			HR[node] = HR[r] * pows[mid - b + 1] + HR[l];
			
		}
	}

	vector<tri> get_segs(int node, int b, int e, int i, int j){
		if(b >= i && e <= j)
			return {{node, {b, e}}};

		if(b > j || e < i)
			return {};

		int mid = (b + e) >> 1;
		int l = node << 1;
		int r = l | 1;
		
		auto L = get_segs(l, b, mid, i, j);
		auto R = get_segs(r, mid + 1, e, i, j);
		
		for(auto &s : R)
			L.push_back(s);
		
		return L;
	}
	
	pii query(int node, int b, int e, int i, int j){

		auto segs = get_segs(node, b, e, i, j);
		
		ll l = 0, r = 0;
		for(int i = 0; i < (int)segs.size(); i++){
			ll lo = segs[i].second.first;
			ll hi = segs[i].second.second;
			ll root = segs[i].first;
			l = l * pows[hi - lo + 1] + H[root];
		}
		
		for(int i = (int)segs.size() - 1; i >= 0; i--){
			ll lo = segs[i].second.first;
			ll hi = segs[i].second.second;
			ll root = segs[i].first;
			r = r * pows[hi - lo + 1] + HR[root];
		}
		
		return {l, r};
	}
	
};

int main(){
	
	pows[0] = 1;
	for(int i = 1; i < maxn; i++)
		pows[i] = pows[i - 1] * b;

	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, q;
		
		scanf("%d %d %s", &n, &q, s);
		
		segment_tree st(n);
		
		for(int i = 0; i < q; i++){
			int p;
			scanf("%d", &p);
			if(p == 2){
				int l, r;
				scanf("%d %d", &l, &r);
				auto ans = st.query(1, 1, n, l, r);
				printf("%s\n", (ans.first == ans.second ? "Adnan Wins" : "ARCNCD!"));
			}
			else{
				int x;
				char c;
				scanf("%d %c", &x, &c);
				st.update(1, 1, n, x, c);
			}
		}
		
	}

	return 0;
}