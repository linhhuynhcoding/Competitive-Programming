// Problem: https://www.spoj.com/problems/CPCRC1C/
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
const int MAXSUM = 180;

int memo[MAXN][2][MAXSUM]; // pos, tight, sum
string s;

int dp(int pos, bool tight, int sum)
{
    if (pos == s.length())
    {
        return sum;
    }
    if (memo[pos][tight][sum] != -1)
    {
        return memo[pos][tight][sum];
    }
    int limit = tight ? (s[pos] - '0') : 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        ans += dp(pos + 1, tight && i == limit, sum + i);
    }
    // printf("pos=%d | tight=%d | pre=%d | limit=%d | ans=%d\            n", pos, tight, pre, limit, ans);
    return memo[pos][tight][sum] = ans;
}

int find(int x)
{
    if (x <= 0)
        return 0;
    s = to_string(x);
    memset(memo, -1, sizeof(memo));
    return dp(0, 1, 0);
}

void solve()
{
    while (true)
    {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) {
            return;
        }
        if (a < b)
            swap(a, b);
        int resa = find(a);
        int resb = find(b - 1);
        cout << resa - resb << "\n";
    }
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
