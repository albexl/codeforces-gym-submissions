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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	cout << setprecision(10) << fixed;
	
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i], b[i] = a[i];
	
	sort(b.begin(), b.end());
	
	for(int i = 0; i < n; i++){
		int lo = 0, hi = n - 1, pos = -1;
		while(lo <= hi){
			int mid = (lo + hi) >> 1;
			if(b[mid] > a[i]){
				pos = mid;
				hi = mid - 1;
			}
			else lo = mid + 1;
		}
		
		double s1 = 0.0;
		if(pos != -1)
			s1 = 1.0 * (n - pos) / n;
		
		lo = 0, hi = n - 1, pos = -1;
		
		while(lo <= hi){
			int mid = (lo + hi) >> 1;
			if(b[mid] < a[i]){
				pos = mid;
				lo = mid + 1;
			}
			else hi = mid - 1;
		}
		
		double s2 = 0.0;
		if(pos != -1)
			s2 = 1.0 * (pos + 1) / n;
			
		double s3 = 1.0 - s1 - s2;
		
		cout << s1 << " " << s3 << " " << s2 << endl;
		
	}

	return 0;
}