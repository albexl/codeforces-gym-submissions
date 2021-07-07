#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

#define endl '\n'
#define MAX

typedef long long ll;
typedef pair<int,int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

const int oo = 1e9 + 5;

struct event{
	
	int x, y1, y2, idx;
	
	event(int x, int y1, int y2, int idx) : x(x), y1(y1), y2(y2), idx(idx){
		
	}
	
	bool operator<(event e) const{
		if(x == e.x)
			return idx < e.idx;
		return x < e.x;
	}
	
};

struct node{
	node *l, *r;
	int value;
	bool lazy;
};

void push(node* root, int b, int e){
	if(!root->l)root->l = new node();
	if(!root->r)root->r = new node();
	
	if(root->lazy){
		root->lazy = false;
		
		int m = (b + e) >> 1;
		
		root->l->value = (m - b + 1) - root->l->value;
		root->l->lazy = !root->l->lazy;
		
		root->r->value = (e - m) - root->r->value;
		root->r->lazy = !root->r->lazy; 
	}
}

ll query(node* root){
	return root->value;
}

void update(node* root, int b, int e, int i, int j){
	if(b >= i && e <= j){
		root->value = (e - b + 1) - root->value;
		root->lazy = !root->lazy;
	}
	else if(b > j || e < i)
		return;
	else{
		int m = (b + e) >> 1;
		push(root, b, e);
		
		update(root->l, b, m, i, j);
		update(root->r, m + 1, e, i, j);
		
		root->value = root->l->value + root->r->value;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	set<event> E;
	
	for(int i = 0; i < n; i++){
		int xo, yo, xi, yi;
		cin >> xo >> yo >> xi >> yi;
		if(xo > xi)
			swap(xi, xo);
		if(yo > yi)
			swap(yo, yi);
		E.insert(event(xo, yo, yi, i));
		E.insert(event(xi, yo, yi, i + n));
	}
	
	node* root = new node();
	
	E.insert(event(oo, 0, 0, n + n));
	
	ll ans = 0, prv = (*E.begin()).x;
	
	for(auto &e : E){
		
		//cout << e.x << " " << query(root) << " " << (e.x - prv) << endl;
		
		if(e.x != prv)
			ans += 1LL * query(root) * (e.x - prv);
		
		if(e.y1 < e.y2)
			update(root, 0, oo, e.y1, e.y2 - 1);
		
		prv = e.x;
	}
	
	cout << ans << endl;

	return 0;
}