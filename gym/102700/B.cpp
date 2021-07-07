#include <bits/stdc++.h>

using namespace std;

#ifdef Adrian
#include "debug.h"
#else
#define debug(...) 9999
#endif

typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second
#define ii pair<ll,ll>
template<typename G1, typename G2 = G1, typename G3 = G1>
struct triple{ G1 F; G2 S; G3 T;};
typedef triple<ll> iii;


/*
	Compute for a string S the suffix array order, rank and lcp of every suffix starting in (0, 1, ..., |S|)

	Notes: The suffix starting in |S| is always the lowest and have lcp 0 with the next suffix.
			lcp[i] is the longest common prefix between the suffix in sa[i] and sa[i-1]

	Complexity: O(|S| log |S|)
*/

struct suffix_array
{
    int n;
    vector<int> sa, lcp, rank;

    suffix_array(const string &s) : n(s.length() + 1), sa(n), lcp(n), rank(n)
    {
        vector<int> top(max(256, n));
        for (int i = 0; i < n; ++i)
            top[rank[i] = s[i] & 0xff]++;

        partial_sum(top.begin(), top.end(), top.begin());
        for (int i = 0; i < n; ++i)
            sa[--top[rank[i]]] = i;

        vector<int> tmp(n);
        for (int len = 1, j; len < n; len <<= 1)
        {
            for (int i = 0; i < n; ++i)
            {
                j = sa[i] - len;
                if (j < 0) j += n;
                tmp[top[rank[j]]++] = j;
            }

            sa[tmp[top[0] = 0]] = j = 0;
            for (int i = 1, j = 0; i < n; ++i)
            {
                if (rank[tmp[i]] != rank[tmp[i - 1]]
                    || rank[tmp[i] + len] != rank[tmp[i - 1] + len])
                    top[++j] = i;
                sa[tmp[i]] = j;
            }

            copy(sa.begin(), sa.end(), rank.begin());
            copy(tmp.begin(), tmp.end(), sa.begin());
            if (j >= n - 1) break;
        }

        int i, j, k;
        for (j = rank[lcp[i = k = 0] = 0]; i < n - 1; ++i, ++k)
        {
            while (k >= 0 && s[i] != s[sa[j - 1] + k])
                lcp[j] = k--, j = rank[sa[j] + 1];
        }
    }
};


int main()
{
#ifdef Adrian
    //freopen("quarantine_input.txt", "r", stdin);
    //freopen("test.out", "w", stdout);
#else
    ios_base::sync_with_stdio(0); cin.tie(0);
#endif


    string a, b;
    cin>>a>>b;

    char mx = 'a';
    for(auto i:b)
        mx = max(mx, i);

    suffix_array sa(a);
    suffix_array sb(b);

    int la = sa.sa.back(), lb = sb.sa.back();

    string ans = "";
    ans += a[la++];
    for(int i=la; i<a.size() && a[i] >= mx; i++)
        ans += a[i];

    for(int i=lb; i<b.size(); i++)
        ans += b[i];

    cout<<ans<<'\n';


    return 0;
}