#include <bits/stdc++.h>

using namespace std;

vector <int> parent(2e5 + 10);

struct DSU{
    int n;
    void make_set(){
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    void union_set(int a, int b){
        parent[b] = find_par(parent[b]);
        parent[a] = find_par(parent[a]);
        if (parent[b] < parent[a]) swap(a,b);
        parent[find_par(parent[b])] = parent[a];
    }

    int find_par(int x){
        if (parent[x] == x) return x;
        return parent[x] = find_par(parent[x]);
    }

    void print(){
        for (int i = 0; i < n; i++){
            cout << parent[i] << " ";
        }
    }
};

struct Query{
    char c;
    int s = -1;
    int u, v;
    int index = -1;

    void print(){
    cout << c << " " << s << " " << u << " " << v << " " << index;
    }
};

int main(){
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int t;
    DSU dta;
    cin >> dta.n >> t;
    vector < vector <Query> > q(2e5 + 2);
    int snapshot = 1;
    int counter = 0;
    while(t--){
        char c; int s=-1; int u,v;
        cin >> c;
        if (c == 'C') snapshot++;
        switch (c) {
        case 'A':
            cin >> u >> v;
            u--;v--;
            q[snapshot].push_back({c, -1, u, v, -1});
            break;
        case '?':
            cin >> u >> v;
            u--;v--;
            q[snapshot].push_back({c, -1, u, v, counter});
            counter++;
            break;
        case 'Q':
            cin >> s >> u >> v;
            u--;v--;
            q[s].push_back({c, s, u, v, counter});
            counter++;
            break;
        }
    }
    vector <char> res(counter);
    dta.make_set();
    for(int i = 0; i <= snapshot; i++){
//        cout << "snap :\t" << i << "\n";
        for (auto j : q[i]){
//            j.print(); cout << "\n";
            switch (j.c){
            case 'A':
                dta.union_set(j.u, j.v);
                break;
            case '?':
                if (dta.find_par(j.u) == dta.find_par(j.v)){
                    res[j.index] = 'Y';
                }
                else res[j.index] = 'N';
                break;
            case 'Q':
                if (dta.find_par(j.u) == dta.find_par(j.v)){
                    res[j.index] = 'Y';
                }
                else res[j.index] = 'N';
                break;
            }
        }
//        cout << "\n";
    }
//    dta.print();
//    cout << "\n";
    for (auto r : res) cout << r;
}
