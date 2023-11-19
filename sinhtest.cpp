#include <bits/stdc++.h>

using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r)
{
    return l + rd() * rd() * 1LL % (r - l + 1);
}

const long long INF = 1e9 + 10;
long long x, y;

int main()
{
    freopen("D:\\CODE\\CP\\in.txt", "w", stdout);
    int m = 1e5;
    int n = 40;
    x = Rand(-1e9,1e9); y = Rand(-1e9,1e9);
    cout << n << " " << m << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << Rand(1,1e5) << " " << Rand(1,1e8) << "\n";
    }

    // string NAME = "_cp";

    // system((NAME + ".exe").c_str());

    // NAME = "_trau";
    // system((NAME + ".exe").c_str());
    // NAME = "out";

    // if (system(("fc " + NAME + ".txt" + "ans.txt").c_str()) != 0) cout << "Wrong\n";
    // else cout << "Correct\n";
}