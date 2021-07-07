#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(short I = A;I < B;++I)
#define WAIT cout << flush,system("PAUSE");
#define sz(s) ((int)((s).size()))
#define endl '\n'
#define MAX 100005

typedef long long ll;
typedef pair<short, short> pii;
typedef vector<int> vi;


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int n, s; cin >> n >> s;

    int k, mx = 0;

    REP(i, 0, n){
    	cin >> k;
    	mx = max(mx, k * s);
    }

    double aux = (double)mx / 1000.0;

    cout << (ll)ceil((aux)) << endl;
}