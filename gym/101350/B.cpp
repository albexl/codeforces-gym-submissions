#include<bits/stdc++.h>
 
#define PB push_back
#define remove erase
#define endl '\n'
#define FOR(in,n) for(int i = in;i < n;i++)
#define MAX
 
using namespace std;
 
typedef long long ll;
 
typedef pair<int,int> pii;
typedef pair<int,ll> pll;
typedef pair<int,double> pid;
typedef vector<int> vi;
 
int main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    
	int t;
	cin >> t;
	while(t--){
		int a,b;
		cin >> a >> b;
		if(b > a)cout << "WeWillEatYou" << endl;
		else cout << "FunkyMonkeys" << endl;
	}
 
}