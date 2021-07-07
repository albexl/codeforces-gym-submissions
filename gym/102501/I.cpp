#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define double ld
typedef complex<ll> point;
#define F first
#define S second
#define ii pair<int,int>
#define iii pair<int,ii>


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    int n1, n2, n12;
    cin>>n1>>n2>>n12;

    cout<<((n1 + 1) * (n2 + 1) - n12 - 1) / (n12 + 1);
    return 0;
}