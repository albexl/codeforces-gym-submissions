#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(x) (int)((x).size())
#define MAX 10000005
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;


int main()
{
    ios_base :: sync_with_stdio(0); cin.tie(0);

    int n, m, a, b;

    cin >> n >> m;

    while(m--){
        cin >> a >> b;
        if(a > b)
            cout << "1";
        else cout << "0";
    }

    cout << endl;

}