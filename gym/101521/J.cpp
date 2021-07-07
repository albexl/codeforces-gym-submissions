#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool inside(ll x, ll y, ll a, ll b){
	return a <= x && b <= y;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ll h, w, ha, hb, wa, wb;
	cin >> h >> w >> ha >> wa >> hb >> wb;
	
	h *= 4, w *= 4;
	ha *= 4, wa *= 4;
	hb *= 4, wb *= 4;
	
	if(!inside(h, w, ha, wa)){
		cout << "No" << endl;
		cout << "No" << endl;
		return 0;
	}
	
	if(inside(h - ha, w, hb, wb) || inside(h, w - wa, hb, wb))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
		
	
	if(inside( (h - ha) / 2, w, hb, wb) || inside(h, (w - wa) / 2, hb, wb))
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	

	return 0;
}