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

bool flag = false;

void dfs(int m, int n, vi v)
{
    if (flag)
    {
        return;
    }
    if (sz(v) > n)
        return;
    if (sz(v) >= m + 1)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
        flag = true;
        return;
    }

    int sum = 0;
    for (int i = sz(v) - 1; i >= 0 && i >= sz(v) - m - 1; i--)
    {
        sum += v[i];
        if (sum % m == 0)
        {
            return;
        }
    }
    for (int i = 1; i < m; i++)
    {
        vi temp = v;
        temp.push_back(i);
        dfs(m, n, temp);
    }
}

void solve()
{
    
    int N, K, M;
    cin >> N >> K >> M;
    if (M == 1)
    {
        if (K == 1)
        {
            cout << "YES\n1\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }
    if (K <= M)
    {
        cout << "YES\n";
        for (int i = 0; i < N - 1; i++)
        {
            cout << 1 << " ";
        }
        cout << (M - K + 1) << "\n";
    }
    else
    {
        cout << "NO\n";
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
Một dãy mà chia hết cho 5 tương đương với việc là tổng đồng dư chia 5 của mọi phần tử trong đoạn đều chia được cho 5:
Ví dụ:
    - 9 17 14
    - 4 2 4 (đồng dư 5) ==> tổng lại đều chia hết cho 5
Xét:

+ Trường hợp: K < M:
    - Chỉ cần tất cả các số đều đồng dư 1, phần tử cuối dùng đồng dư (M - K + 1) là được:
        Ví dụ:
            - 6 6 6 6 6 9
            - 1 1 1 1 1 3
+ Trường hợp: K = M:
- Tất cả đều đồng dư 1, tương đương case trên.

+ Trường hợp: K > M:
- Bài toán trở về không được để dãy nào có tổng đồng dư chia hết cho M mà có độ dài bé hơn K.
    - 0 1 2 3 4
    - 2 3
    - 1 4
    - 1 2 2
    - 1 3 1
    - 3 3 4
    - 1 2 3 4

    - 1 3 4

    p[1] p[2] p[3] .. p[n - 1] - không có giá trị nào được % 5 == 0

    - 2
    - 6

    5 6 5 6 5 6 5 6 5 6 5 6 5 6
     1   1   1   1   1   1   1

     1 2 3 4 5 6 7 8 9
     1 3 5 9 14
 */
