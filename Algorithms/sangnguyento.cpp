#include <bits/stdc++.h>
using namespace std;

#define se second
#define fi first

const long long MOD = 1e9 + 9;
const long long INF = 1e12 + 100;

int main(){
    int n; n = 1000;
    vector <bool> isPrime(n+1, true);
    vector <int> res;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++){
        if (isPrime[i] == true)
        {
            res.push_back(i);
            for (int j = i*i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (auto i : res) cout << i << " ";    
}
