#include <bits/stdc++.h>
using namespace std;
#define sz(a) size(a)
#define vi vector<int>
#define invi(a)      \
    for (int &i : a) \
        cin >> i;
#define outvi(a)                    \
    for (int i = 0; i < sz(a); i++) \
        cout << a[i] << " \n"[i == sz(a) - 1];
#define int long long

void solve()
{
    int N, M;
    cin >> N >> M;
    vi a(N), m(M);
    invi(a);
    invi(m);
    vi p(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        p[i + 1] = p[i] + a[i];
    }
    sort(m.begin(), m.end());

    int res = p[N];
    for (int i = 0; i < M; i++)
    {
        int best = -p[m[i]] * 2 + p[N];
        if (i != 0)
        {
            best = max(best, res + -(p[m[i]] - p[m[i - 1]]) * 2);
            // printf("opt1=%d | opt2=%d | best=%d\n", -p[m[i]] * 2 + p[N], res + -(p[m[i]] - p[m[i - 1]]) * 2, res);
        }
        res = max(res, best);
    }
    cout << res << "\n";
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}

/**
5 3
-1 2 -3 4 -5
1 3 5

-1 1 -2 2 -3

1 3 5

1: best = -3 --> best = -2
3:
     *  best = -2 --> best = -1
     *  best = -1 --> best = -1

5
    *  best = -1 --> best = 3
    *  best = 3 --> best = -1


 */
