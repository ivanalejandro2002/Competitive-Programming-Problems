#include <bits/stdc++.h>
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

struct geom{
    int xmin,xmax,ymin,ymax;
};

void busca(int nodo, vvi &mapa, vb &visto,vi &comp,int v){
    visto[nodo] = 1;
    comp[nodo] = v;
    for(int z:mapa[nodo]){
        if(visto[z])continue;
        busca(z,mapa,visto, comp, v);
    }
}

void solve(){
    int n,m,k;
    ifstream fin;
    ofstream fout;
    fin.open("fenceplan.in");
    fout.open("fenceplan.out");

    fin>>n>>m;
    vpii coords(n+1);
    fore(i,1,n){
        fin>>coords[i].fi>>coords[i].se;
    }

    vvi mapa(n+1);
    int u,v;
    fore(i,1,m){
        fin>>u>>v;
        mapa[u].pb(v);
        mapa[v].pb(u);
    }

    vi componente(n+1);
    vb visto(n+1);
    int turno = 1;
    //cout<<"hola\n";
    fore(i,1,n){
        if(!visto[i]){
            busca(i,mapa,visto,componente,turno);
            turno++;
        }
    }
    /*fore(i,1,n)cout<<componente[i]<<",";
    cout<<"\n";*/
    vector<geom> lados(turno,{INT_MAX,INT_MIN,INT_MAX,INT_MIN});
    turno--;
    fore(i,1,n){
        lados[componente[i]].xmin = min(lados[componente[i]].xmin, coords[i].fi);
        lados[componente[i]].xmax = max(lados[componente[i]].xmax, coords[i].fi);
        lados[componente[i]].ymin = min(lados[componente[i]].ymin, coords[i].se);
        lados[componente[i]].ymax = max(lados[componente[i]].ymax, coords[i].se);
    }
    int mejor = INT_MAX;
    /*fore(i,1,turno){
        cout<<i<<"::"<<lados[i].xmin<<","<<lados[i].xmax<<"=="<<lados[i].ymin<<","<<lados[i].ymax<<"\n";
    }*/
    fore(i,1,turno){
        mejor = min(mejor, (lados[i].xmax-lados[i].xmin)*2 +(lados[i].ymax-lados[i].ymin)*2);
    }
    fout<<mejor<<"\n";
}
int main(){
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}