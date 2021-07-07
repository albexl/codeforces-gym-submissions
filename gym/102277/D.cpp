#include <bits/stdc++.h>
 
using namespace std;
 
#define all(x) begin(x), end(x)
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
 
ll x, y, r;
 
void check_side(int& res, ll x1, ll y1, ll x2, ll y2) {
    assert(x1 <= x2);
    assert(y1 <= y2);
 
    ll xx, yy;
    if (x1 == x2) {
        xx = x1;
        yy = min(max(y1, y), y2);
    } else if (y1 == y2) {
        xx = min(max(x1, x), x2);
        yy = y1;
    } else {
        assert(false);
    }
 
    ll dx = xx - x;
    ll dy = yy - y;
    ll d = dx * dx + dy * dy;
    if (d == r * r) {
        res = max(res, 1);
    } else if (d < r * r) {
        res = 2;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
 
    cin >> x >> y >> r;
 
    ll tx, ty, s;
    cin >> tx >> ty >> s;
 
    if (tx <= x && x <= tx + s && ty <= y && y <= ty + s) {
        cout << "2\n";
        return 0;
    }
 
    int state = 0;
    check_side(state, tx, ty, tx + s, ty);
    check_side(state, tx, ty, tx, ty + s);
    check_side(state, tx + s, ty, tx + s, ty + s);
    check_side(state, tx, ty + s, tx + s, ty + s);
 
    cout << state << '\n';
 
    return 0;
}