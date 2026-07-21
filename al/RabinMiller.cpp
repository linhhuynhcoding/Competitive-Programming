#include <bits/stdc++.h>
using namespace std;

#define se second
#define fi first

const long long MOD = 1e9 + 9;
const long long INF = 1e12 + 100;

// 12 số nguyên tố đầu tiên
const int primebases[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

// Tính a^k % n
long long power(long long a, long long k, long long n)
{
    long long res = 1;
    a %= n;

    while (k)
    {
        if (k & 1)
            res = (res * a) % n;
        a = a * a % n;
        k >>= 1;
    }

    return res;
}

bool test(long long a, long long n, long long k, long long m)
{
    long long x = power(a, m, n);

    if (x == 1 || x == n - 1)
    {
        return true;
    }

    for (int l = 1; l < k; l++)
    {
        x = x * x % n;

        if (x == n - 1)
        {
            return true;
        }
    }

    return false;
}

bool RabinMiller(long long n)
{
    for (int i = 0; i < 12; i++)
    {
        if (n == primebases[i])
            return true;
    }

    if (n < 38)
    {
        return false;
    }

    long long k = 0;
    long long m = n - 1;

    while ((m & 1) == 0)
    {
        m = m >> 1;
        k++;
    }

    for (int i = 0; i < 12; i++)
    {
        if (!test(primebases[i], n, k, m))
        {
            return false;
        }
    }

    return true;
}

int main()
{
    // cin.tie(0);
    // cin.sync_with_stdio(false);

    cout << RabinMiller(82589933);
}
