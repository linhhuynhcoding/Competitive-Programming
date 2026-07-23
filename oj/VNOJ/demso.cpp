// Problem: https://oj.vnoi.info/problem/demso
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

int memo[MAXN][2][10][MAXN][2]; // pos, tight, K, lead zero
string s;
int D;
int K;

int dp(int pos, bool tight, int pre, int k, int lead)
{
    if (pos == s.length())
    {
        return 1;
    }
    if (memo[pos][tight][pre][k][lead] != -1)
    {
        return memo[pos][tight][pre][k][lead];
    }
    int limit = tight ? (s[pos] - '0') : 9;
    int ans = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (!lead && abs(i - pre) <= D)
        {
            if (k > 0)
            {
                ans += dp(pos + 1, tight && i == limit, i, k - 1, lead);
            }
        }
        else
        {
            ans += dp(pos + 1, tight && i == limit, i, k, lead && i == 0);
        }
    }
    // printf("pos=%d | tight=%d | pre=%d | limit=%d | ans=%d\n", pos, tight, pre, limit, ans);
    return memo[pos][tight][pre][k][lead] = ans;
}

int find(int x)
{
    if (x <= 0)
        return 1;
    s = to_string(x);
    memset(memo, -1, sizeof(memo));
    return dp(0, 1, 10, K, 1);
}

void solve()
{
    int a, b;
    cin >> a >> b >> D >> K;
    if (a < b)
        swap(a, b);
    int resa = find(a);
    int resb = find(b - 1);
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

// 13
// 0 9                
// 1 3

// 1
// 0
