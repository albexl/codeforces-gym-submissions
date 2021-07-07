#include <bits/stdc++.h>

using namespace std;

#define REP(I,A,B) for(int I = A;I < B;++I)
#define sz(x) (int)((x).size())
#define MAX 10000005
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;

bool dp[25005][105];

void Esquina(int n, int a, int b, int s){
    if(n == 1){
        if(s == a && s == b){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    else if(n == 2){
        if(s == a + b)
            cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios_base :: sync_with_stdio(0); cin.tie(0);

    int n, a, b, s;

    cin >> n >> a >> b >> s;

    if(n <= 2){
        Esquina(n, a, b, s);
        return 0;
    }

    if(s <= a + b){
        cout << "NO\n";
        return 0;
    }


    s -= (a + b);

    for(int i = a;i <= b;++i)
        dp[i][1] = 1;

    for(int k = 2;k <= n;++k){
        for(int i = 1;i <= s;++i){
            for(int j = a; j <= b;++j){
                if(i - j >= 1){
                    dp[i][k] |= dp[i - j][k - 1];
                }
            }
        }
    }


    if(dp[s][n - 2]){
        cout << "YES\n";
    }
    else cout << "NO\n";
}