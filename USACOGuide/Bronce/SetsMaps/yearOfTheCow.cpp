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
struct relacion{
    int u;
    int v;
    bool dir;
    int nuevo;
};
bool encontrado = 0;
int solucion = -1;
vb visto;
void busca(vector<vector<relacion> > &mapa,int nodo,int meta, int tiempo, int anoActual){
    if(nodo==meta){
        encontrado = 1;
        solucion = tiempo;
        return;
    }
    visto[nodo] = 1;
    for(auto z:mapa[nodo]){
        if(visto[z.u])continue;
        int t = tiempo;
        int aux;
        if(z.dir){
            if(anoActual!=z.nuevo){
                aux = (12+z.nuevo-anoActual)%12;
                t+=aux;
            }else{
                t+=12;
            }
        }else{
            if(anoActual !=z.nuevo){
                aux = (anoActual-z.nuevo+12)%12;
                t-=aux;
            }else{
                t-=12;
            }
        }
        busca(mapa,z.u,meta,t,z.nuevo);
    }
}
void solve(){
    int n,m,k;
    cin>>n;
    map<string,int> datos = {
        {"Ox", 0},
        {"Tiger",1},
        {"Rabbit",2},
        {"Dragon",3},
        {"Snake",4},
        {"Horse",5},
        {"Goat",6},
        {"Monkey",7},
        {"Rooster",8},
        {"Dog",9},
        {"Pig",10},
        {"Rat",11}
    };
    string mens;
    map<string,int> nombres;
    vector<relacion> arista;

    for(int i=0;i<n;i++){
        cin>>mens;
        if(!nombres.count(mens))
            nombres[mens] = nombres.size()+1;
        arista.pb({nombres[mens],0,0,0});
        cin>>mens>>mens>>mens;
        if(mens[0]=='n')arista.back().dir = 1;
        cin>>mens;
        arista.back().nuevo = datos[mens];
        cin>>mens>>mens>>mens;
        if(!nombres.count(mens))
            nombres[mens] = nombres.size()+1;
        arista.back().v = nombres[mens];
    }

    /*for(auto z:arista){
        cout<<z.u<<"->"<<z.v<<"("<<z.dir*2-1<<","<<z.nuevo<<")\n";
    }*/

    int inicio = nombres["Bessie"];
    int fin = nombres["Elsie"];

    vector<vector<relacion> > mapa(nombres.size()+1);
    for(auto z:arista)
        mapa[z.v].pb(z);
    

    visto.resize(mapa.size());
    busca(mapa,inicio,fin,0,0);

    cout<<abs(solucion)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}