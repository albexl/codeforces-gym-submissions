#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>
#include <chrono>
 
using namespace std;
using namespace __gnu_pbds;
 
#define endl '\n'
 
typedef long long ll;
typedef pair<ll, ll> pii;
typedef tree<int, null_type,less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template<typename T>
static T randint(T lo, T hi){
	return uniform_int_distribution<T>(lo, hi)(rng);
}

pair<string, string> get(string s){
	string num = "", x = "";

	for(auto &c : s){
		if(c >= 'a' && c <= 'z')
			x += c;
		else
			num += c;
	}

	return {x, num};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	// freopen("settling.in", "r", stdin);
	// freopen("settling.out", "w", stdout);

	string a, b;
	cin >> a >> b;

	pair<string, string> A = get(a);
	pair<string, string> B = get(b);

	if(A.first < B.first){
		cout << "<" << endl;
	}
	else if(A.first > B.first){
		cout << ">" << endl;
	}
	else{
		if(A.second.size() < B.second.size())
			cout << "<" << endl;
		else if(A.second.size() > B.second.size())
			cout << ">" << endl;
		else{
			if(A.second < B.second)
				cout << "<" << endl;
			else if(A.second > B.second)
				cout << ">" << endl;
			else
				cout << "=" << endl;
		}
	}

	return 0;
}