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

int papa(int nodo, vi &padres){
    if(padres[nodo] == nodo)return nodo;
    return padres[nodo] = papa(padres[nodo],padres);
}

int uf(int a, int b, vi &padres){
    int pa = papa(a,padres);
    int pb = papa(b,padres);

    if(pa==pb)return 0;
    padres[pa] = pb;
    return -1;
}

void solve(){
    int n,m,k;
    ifstream fin;
    ofstream fout;
    fin.open("closing.in");
    fout.open("closing.out");

    int u,v;
    fin>>n>>m;
    vvi mapa(n+1);
    fore(i,1,m){
        fin>>u>>v;
        mapa[u].pb(v);
        mapa[v].pb(u);
    }
    int componentes = 0;
    vb existentes(n+1);
    vi datos(n);
    fore(i,0,n-1)fin>>datos[i];
    reverse(all(datos));
    vi padres(n+1);
    fore(i,1,n)padres[i] = i;
    vb sol;
    for(int z: datos){
        componentes++;
        existentes[z]=1;
        for(int w: mapa[z]){
            if(!existentes[w])continue;
            componentes+=uf(z,w,padres);
        }
        //cout<<z<<"_"<<componentes<<"\n";
        if(componentes<=1){
            sol.pb(1);
        }else sol.pb(0);
    }
    reverse(all(sol));
    for(bool z:sol){
        (z)?fout<<"YES\n":fout<<"NO\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}