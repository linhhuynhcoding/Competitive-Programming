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
    int N, C;
    cin >> N >> C;
    vi a(N), b;
    int sum = 0;
    for (auto &i : a)
    {
        cin >> i;
        sum += i;
    }
    sort(a.begin(), a.end());
    int res = 0;
    int index = N / 2;
    auto it = lower_bound(a.begin(), a.end(), C);
    if (it != a.end())
    {
        index = min(index, (int)distance(a.begin(), it));
    }
    // cout << index << " ";
    for (int i = index; i < N; i++)
    {
        res += (a[i] - C);
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

/*
*/