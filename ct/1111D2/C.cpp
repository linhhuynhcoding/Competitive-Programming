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

    int N;
    cin >> N;
    int cnta = 0, cntb = 0;
    int diff = 0, sum = 0;
    vi a(N), b(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            cnta++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        cin >> b[i];
        if (b[i] == 1)
            cntb++;
        if (b[i] != a[i])
            diff++, sum += a[i];
    }
    if (diff == 0)
    {
        cout << "0\n";
        return;
    }
    if ((cntb == N && cnta < N) || cnta == 0)
    {
        cout << "-1\n";
        return;
    }
    if (sum % 2 == 1)
    {
        cout << "1\n";
    }
    else
    {
        cout << "2\n";
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

/**
 + Trường hợp nếu dãy B full 1:
    + mà dãy A có tồn tại số 0 --> false
 + Trường hợp nếu dãy B full 0 --> thì luôn có cách để biến A -> B --> true

 + Nếu A full 0 --> false

 */
