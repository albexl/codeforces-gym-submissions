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
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	int n;
	cin >> n;

	set<string> good, bad;
	while(n--){
		string s;
		cin >> s;
		good.insert(s);
	}
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		bad.insert(s);
	}
	cin >> n;

	int s1 = 0, s2 = 0;
	while(n--){
		string s;
		cin >> s;
		if(good.count(s))
			s1++;
		if(bad.count(s))
			s2++;
	}

	if(s1 > s2)
		cout << "Positive" << endl;
	else if(s1 < s2)
		cout << "Negative" << endl;
	else
		cout << "Neutral" << endl;

	return 0;
}