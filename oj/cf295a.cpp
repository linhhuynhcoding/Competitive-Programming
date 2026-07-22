// Problem: https://codeforces.com/problemset/problem/295/A
// Tag: #diff

#include <bits/stdc++.h>
using namespace std;
#define sz(a) size(a)
#define int long long
#define vi vector<int>
#define invi(a)      \
    for (int &i : a) \
        cin >> i;
#define outvi(a)                    \
    for (int i = 0; i < sz(a); i++) \
        cout << a[i] << " \n"[i == sz(a) - 1];

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    invi(a);
    int M[3][m];
    for (int i = 0; i < m; i++)
    {
        cin >> M[0][i] >> M[1][i] >> M[2][i];
    }
    vi D(n, 0);
    vi K(m, 0);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        K[x - 1] += 1;
        if (y != m)
        {
            K[y] += -1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += K[i];
        D[M[0][i] - 1] += cnt * M[2][i];
        if (M[1][i] != n)
        {
            D[M[1][i]] -= cnt * M[2][i];
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += D[i];
        a[i] += sum;
    }
    outvi(a);
    // cout << res << "\n";
}

signed main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--)
    {
        solve();
    }
}
