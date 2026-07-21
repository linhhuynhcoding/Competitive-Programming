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
    int N, K;
    string S;
    cin >> N >> K >> S;
    int res = 0;
    int cntR, cntL = cntR = 0;
    for (char c : S)
        cntR += (c == 'R'), cntL += (c == 'L');
    for (int i = N - 1; i >= 0; i--)
    {
        if (S[i] == 'R')
        {
            if (N - (i + 1) < K)
            {
                // cout << i << " ";
                res++;
                S[i] = 'L';
                cntR--;
                cntL++;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'L')
        {
            if (i < K)
            {
                // cout << i << " ";
                res++;
                S[i] = 'R';
            }
            else
            {
                break;
            }
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (S[i] == 'R')
        {
            if (N - (i + 1) < K)
            {
                cout << "-1\n";
                return;
            }
        }
    }
    if (res > N)
    {
        cout << "-1\n";
        return;
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
