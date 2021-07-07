    #include <bits/stdc++.h>
     
     
     
    using namespace std;
     
     
     
    #define endl '\n'
     
     
     
    using point = complex<double>;
     
    struct circle { double r; point p; };
     
     
     
    // for comparison
     
    const double eps = 1e-9;
     
    inline int sign(double x) { return x < -eps ? -1 : x > eps; }
     
    inline int dcmp(double x, double y) { return sign(x - y); }
     
     
     
    point circumcenter(point a, point b, point c)
     
    {
     
     point x = 1.0 / conj(b - a), y = 1.0 / conj(c - a);
     
     return (y - x) / (conj(x) * y - x * conj(y)) + a;
     
    }
     
     
     
    circle min_enclosing_circle(vector<point> P)
     
    {
     
     int n = P.size();
     
     shuffle(P.begin(), P.end(), random_device{});
     
     double r = 0.0;
     
     point p = P[0];
     
     for (int i = 1; i < n; ++i)
     
      if (dcmp(abs(P[i] - p), r) > 0)
     
      {
     
       r = abs(P[0] - P[i]) * 0.5;
     
       p = (P[0] + P[i]) * 0.5;
     
       for (int j = 1; j < i; ++j)
     
        if (dcmp(abs(P[j] - p), r) > 0)
     
        {
     
         r = abs(P[i] - P[j]) * 0.5;
     
         p = (P[i] + P[j]) * 0.5;
     
         for (int k = 0; k < j; ++k)
     
          if (dcmp(abs(P[k] - p), r) > 0)
     
          {
     
           p = circumcenter(P[i], P[j], P[k]);
     
           r = abs(p - P[i]);
     
          }
     
        }
     
      }
     
     return {r, p};
     
    }
     
     
     
     
     
    int main()
     
    {
     
    #ifdef sdasd
     
     assert(freopen("input.in", "r", stdin));
     
     // assert(freopen("output.out", "w", stdout));
     
    #else
     
    #endif
     
     
     
     ios_base::sync_with_stdio(0);
     
     cin.tie(0);
     
     
     
     int n;
     
     cin >> n;
     
     
     
     vector<point> ps;

     
     for (int i = 0; i < n; ++i)
     
     {
     
      double x, y;
     
      cin >> x >> y;
     
      ps.emplace_back(x, y);

     }
     
     
     
     auto c = min_enclosing_circle(ps);
     
     cout << fixed << setprecision(20) << real(c.p) << " " << imag(c.p) << " " << c.r * c.r / 2.0 << endl;
     
     
     
     return 0;
     
    }