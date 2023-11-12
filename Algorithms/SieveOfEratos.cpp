#include <bits/stdc++.h>
using namespace std;

#define se second
#define fi first

const long long MOD = 1e9 + 9;
const long long INF = 1e12 + 100;

vector <int> find_Prime(int n)
{
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
    return res; 
}
void Integer_Factorization()
{
    int n; n = 19456;
    vector <int> primes = find_Prime(sqrt(n) + 1);
    vector <int> ans;
    for (auto i : primes){
        while(n % i == 0)
        {
            ans.push_back(i);
            n /= i;
        }
    }
    for (auto i : ans)
        cout << i << " ";
}



int main(){
   cin.tie(0); cin.sync_with_stdio(false);
   Integer_Factorization();

}
