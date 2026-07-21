#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e12 + 100;
long long x, y;

bool cond(long long a){
    if (a <= y && a >= x)
        return true;
    else return false;
}

int main(){
    // freopen("D:\\CODE\\CP\\in.txt", "r", stdin);
    // freopen("D:\\CODE\\CP\\out.txt", "w", stdout);

    int n; cin >> n; 
    cin >> x >> y;
    vector <long long> a(n+1);
    vector <long long> summ(n+1);
    summ [0] = 0;
    tuple <long long, int, int> res = {-INF, 0, 0};
    tuple <long long, int, int> best = {-INF, 0, 0};
    for (int i = 1; i <=n; i++)
    {
        cin >> a[i]; 
        summ[i] = summ[i-1] + a[i];
    }

    long long min = INF;
    int j = 1;
    for (int i = 1; i <=n; i++)
    {
        if (min > a[i]) min = a[i];
        if (min < x ){
            j = i + 1;
            min = INF;
            continue;
        }
        if (a[i] > get<0>(best) + a[i])
        {
            get<0>(best) = a[i];
            j = i;
        }
        else 
        {
            get<0>(best) =summ[i] - summ[j-1];
  
        }
        get<1>(best) = j;
        get<2>(best) = i;  

        if (get<0>(res) < get<0>(best) && cond(min) == true)
        {
            get<0>(res) = get<0>(best);
            get<1>(res) = get<1>(best);
            get<2>(res) = get<2>(best);
        }               
    }
    std::cout << get<0>(res) << "\n" << get<1>(res) << " " << get<2>(res);
}
