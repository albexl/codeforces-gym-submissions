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

int days[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int d, m, y;
int da, ma, db, mb;

bool leap(int x){
	if(x % 400 == 0)
		return true;
	if( (x % 100 != 0) && (x % 4 == 0))
		return true;
	return false;
}

void move_next(){
	int top = days[m];
	if(leap(y) && m == 2)
		top++;
	d++;
	if(d > top){
		d = 1;
		m++;
	}
	if(m > 12){
		m = 1;
		y++;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scanf("%d/%d/%d", &d, &m, &y);
	scanf("%d/%d", &da, &ma);
	scanf("%d/%d", &db, &mb);
	
	int x0 = d, x1 = m, x2 = y, ans = 0;
	
	
	for(int i = 1; i <= 2048; i++){
		move_next();
		
		//printf("%d\n", i);
		//printf("%d %d %d\n", d, m, y);
		
		if(d == x0 && m == x1){
			++ans; continue;
		}
		if(d == da && m == ma){
			++ans; continue;
		}
			
		if(d == db && m == mb){
			++ans; continue;
		}
			
		if(i % 100 == 0){
			++ans; continue;
		}
			
	}
	
	printf("%d\n", ans);
	
	return 0;
}