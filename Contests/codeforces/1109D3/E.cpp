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
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vi p(N + 1, 0);
    for (int i = 1; i < N; i++)
        p[i + 1] = p[i] + (S[i] == S[i - 1] ? 1 : 0);
    // outvi(p);
    while (Q--)
    {
        int L, R, K;
        cin >> L >> R >> K;
        if (L == R)
        {
            cout << "YES\n";
            continue;
        }
        int cnt = p[R] - p[L];
        int need = (cnt + 1) / 2;
        // printf("L=%d | R=%d | Need=%d | Cnt=%d\n", L, R, need, cnt);
        if (K >= need)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
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
case 1: *1|01..10|1*
case 2: *0|01..10|0*
*/