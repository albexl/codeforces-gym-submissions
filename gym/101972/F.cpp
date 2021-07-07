#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(x) (int)((x).size())
#define MAX 30
#define endl '\n'
#define int long long

typedef long long ll;
typedef pair<double,double> pii;

signed main()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);


    int tc; cin >> tc;

    while(tc--){

    	vector<int> v(26);

    	int len = 0;

    	for(auto &it : v)
    		cin >> it;

    	int cant = (1LL << 60);

    	for(auto &it : v)
    		if(it >= 2){
    			len += 2;
    			cant = min(cant, it / 2);
    			it = 0;
    		}

    	int cont = 0;

    	for(auto it : v){
    		if(it)
    			++cont;
    	}

    	if(cont){
    		cant = min(cant, cont);
    		++len;
    	}

    	if(cant == (1LL << 60)) cant = 0;
    	cout << len << " " << cant << endl;

    }
}