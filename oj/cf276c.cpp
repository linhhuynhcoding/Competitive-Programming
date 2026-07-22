// Problem: https://codeforces.com/problemset/problem/276/C
// Tag: #diff

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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (auto &i : a)
        cin >> i;
    vi d(n, 0);
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        d[l - 1] += 1;
        if (r != n)
        {
            d[r] += -1;
        }
    }
    vi ans;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += d[i];
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    sort(a.begin(), a.end());
    // outvi(ans);
    // outvi(a);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += (ans[i] * a[i]);
    }
    cout << res << "\n";
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
