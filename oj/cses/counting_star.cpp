// Problem: https://cses.fi/alon/task/2220
// Tag: #dp_digit

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
#define rep(i, t, f) for (int i = t; i <= f; i++)

const int MAXN = 20;

int memo[MAXN][2][12][2]; // pos, tight, pre, lead zero
string s;

int dp(int pos, bool tight, int pre, int lead)
{
    if (pos == sz(s))
    {
        return 1;
    }
    if (memo[pos][tight][pre][lead] != -1)
    {
        return memo[pos][tight][pre][lead];
    }
    int limit = tight ? (s[pos] - '0') : 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (!lead && i == pre)
            continue;
        ans += dp(pos + 1, tight && i == limit, i, lead && i == 0);
    }
    // printf("pos=%d | tight=%d | pre=%d | limit=%d | ans=%d\n", pos, tight, pre, limit, ans);
    return memo[pos][tight][pre][lead] = ans;
}

int find(int x)
{
    if (x < 0)
        return 0;
    if (x == 0)
    {
        return 1;
    }
    s = to_string(x);
    memset(memo, -1, sizeof(memo));
    return dp(0, 1, 10, 1);
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (a < b)
        swap(a, b);
    int resa = find(a);
    // rep(k, 0, 10)
    // {
    //     rep(i, 0, 3)
    //         rep(j, 0, 1) if (i != 0 || (k == 10))
    //             printf("memo[%d][%d][%d]=%d\n", i, j, k, memo[i][j][k]);
    // }
    int resb = find(b - 1);
    // rep(k, 0, 10)
    // {
    //     rep(i, 0, 3)
    //         rep(j, 0, 1)
    //             printf("memo[%d][%d][%d]=%d\n", i, j, k, memo[i][j][k]);
    // }
    cout << resa - resb << "\n";
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
