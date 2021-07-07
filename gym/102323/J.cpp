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
	
	const double eps = 1e-6;
	
	int tc;
	cin >> tc;
	
	for(int cases = 1; cases <= tc; cases++){
		cout << "Case " << "#" << cases << ": ";
		
		int a, b, c;
		cin >> a >> b >> c;
		
		vector<int> A(a), B(b), C(c);
		
		double sa = 0.0, sb = 0.0, sc = 0.0;
		
		vector<int> sumA(2505), sumB(2505), sumC(2505);
		
		for(int i = 0; i < a; i++){
			cin >> A[i];
			if(A[i] == 0)
				A[i] = 1;
			sumA[1]++;
			sumA[A[i] + 1]--;
		}
			
		
		for(int i = 0; i < b; i++){
			cin >> B[i];
			if(B[i] == 0)
				B[i] = 1;
			sumB[1]++;
			sumB[B[i] + 1]--;
		}
			
		for(int i = 0; i < c; i++){
			cin >> C[i];
			if(C[i] == 0)
				C[i] = 1;
			sumC[1]++;
			sumC[C[i] + 1]--;
		}
		
		for(int i = 1; i < 2505; i++){
			sumA[i] += sumA[i - 1];
			sumB[i] += sumB[i - 1];
			sumC[i] += sumC[i - 1];
			
			if(sumA[i])
				sa += 1.0 * sumA[i] * log2(1.0 * i);
			if(sumB[i])
				sb += 1.0 * sumB[i] * log2(1.0 * i);
			if(sumC[i])
				sc += 1.0 * sumC[i] * log2(1.0 * i);
		}
			
		
		vector<pair<double, int>> v(3);
		v[0] = {sa, 0};
		v[1] = {sb, 1};
		v[2] = {sc, 2};
		
		sort(v.begin(), v.end());
	
		if(abs(v[2].first - v[1].first) < eps)
			cout << "TIE" << endl;
		else
			cout << (char)(v[2].second + 'A') << endl;
		
	}
	
	return 0;
}