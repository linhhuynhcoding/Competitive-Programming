#include <bits/stdc++.h>
#include <bit>

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
    if (n == 1)
    {
        if (k == 1)
        {
            cout << "YES\n0\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    k ^= n;
    if (k == 0)
    {
        cout << "YES\n";
        for (int i = n - 1; i >= 0; i--)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if (k > (1 << (64 - __builtin_clzll(n) + 1) - 1))
    {
        // cout << (1 << (64 - __builtin_clzll(n) + 1) - 1) << " ";
        cout << "NO\n";
        return;
    }
    if (k < n)
    {
        cout << "YES\n";
        for (int i = 1; i < n; i++)
        {
            if (i != k)
            {
                cout << i << " ";
            }
        }
        cout << "0 " << k << "\n";
        return;
    }
    k ^= (n - 1);
    if (k >= n - 1)
    {
        cout << "NO\n";
        return;
    }
    else
    {
        cout << "YES\n";
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (i != k)
        {
            cout << i << " ";
        }
    }
    cout << "0 " << k << " " << n - 1 << "\n";
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
0000
1111

1001 = 9

1010 = 10

0011 = 3

1110

110 = 6
001 = 1
111 = 7


1110 = 8 ^ 6 = 1000 ^ 0110 = 1110

0 1 2 3 4 5 6 7 8 9 10

case 1: K <= N + 1
1 2 3 4 6 7 8 9 10 0 5

0 1 2 3 4 5 6 7 8
case 2:
1 2 3 4 5 7 0 6

1001
*/
