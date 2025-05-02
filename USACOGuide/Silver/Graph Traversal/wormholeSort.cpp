#include <bits/stdc++.h>
#include <fstream>
#define fi first
#define se second
#define pb push_back
#define all(S) S.begin(),S.end()
#define LSOne(S) ((S)&(-S))
#define fore(V,L,R) for(int V = L; V<=R;V++)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
struct portal{
    int u,v,w;
    const bool operator < (const portal &otro)const { return w > otro.w; }
};

struct UF{
    int n;
    vi padres;
    
    UF(int _n){
        n = _n;
        padres.resize(n+1);
        fore(i,1,n)padres[i] = i;
    }

    int papa(int nodo){
        if(padres[nodo] == nodo)return nodo;
        return padres[nodo] = papa(padres[nodo]);
    }

    void query(int a, int b){
        int pa = papa(a);
        int pb = papa(b);

        if(pa !=pb){
            padres[pa] = pb;
        }
    }
    bool connected(int a, int b){
        return papa(a) == papa(b);
    }
};

void solve(){
    ifstream fin;
    ofstream fout;
    fin.open("wormsort.in");
    fout.open("wormsort.out");
    int n,m;
    fin>>n>>m;

    vi vacas(n+1);
    vector<portal> agujeros(m);
    fore(i,1,n)fin>>vacas[i];

    fore(i,0,m-1){
        fin>>agujeros[i].u>>agujeros[i].v>>agujeros[i].w;
    }
    sort(all(agujeros));

    int idx = 0;
    UF dsu(n);
    int mejor = INT_MAX;
    fore(i,1,n){
        while(idx<m && !dsu.connected(i,vacas[i])){
            dsu.query(agujeros[idx].u,agujeros[idx].v);
            mejor = agujeros[idx].w;
            idx++;
        }
        if(!dsu.connected(i,vacas[i])){
            fout<<"-1\n";
            return;
        }
    }
    if(mejor == INT_MAX){
        fout<<"-1";
        return;
    }
    fout<<mejor<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}