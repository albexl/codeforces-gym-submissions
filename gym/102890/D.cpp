#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <random>

using namespace std;
using namespace __gnu_pbds;

#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
// typedef tree<int, null_mapped_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

template <typename T>
static T randint(T lo, T hi)
{
    return uniform_int_distribution<T>(lo, hi)(rng);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        ll k;
        cin >> s >> k;

        string ans = "";
        ll num = 0, len = 0;

        bool ok = true;

        for (auto &c : s)
        {

            if (c >= '0' && c <= '9')
            {
                num = num * 10 + (c - '0');
                if (num + len > k)
                {
                    ok = false;
                    break;
                }
            }
            else
            {
                if (num == 0)
                    num = 1;
                if (num + len > k)
                {
                    ok = false;
                    break;
                }

                len += num;
                while (num--)
                    ans += c;

                num = 0;
            }
        }

        if (ok)
            cout << ans << endl;
        else
            cout << "unfeasible" << endl;
    }

    return 0;
}