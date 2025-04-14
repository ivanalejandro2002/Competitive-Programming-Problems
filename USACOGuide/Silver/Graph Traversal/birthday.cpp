#include <bits/stdc++.h>
#include <fstream>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

void busca(int nodo, const pii &borrada, vvi &mapa, vb &visto, int &restantes){
    visto[nodo] = 1;
    restantes--;
    for(int z:mapa[nodo]){
        if(visto[z])continue;
        if(min(z,nodo)==borrada.fi && max(z,nodo)==borrada.se)continue;
        busca(z,borrada,mapa,visto,restantes);
    }
}

bool solve(int n,int m){
    vvi mapa(n+1);
    int u,v;
    vpii aristas;
    fore(i,1,m){
        cin>>u>>v;
        aristas.pb({u,v});
        mapa[u].pb(v);
        mapa[v].pb(u);
    }
    vb visto;
    int restantes;
    //cout<<"CASO\n\n";
    for(pii z:aristas){
        restantes = n;
        visto.resize(n+1);
        busca(1,{min(z.fi,z.se),max(z.fi,z.se)},mapa,visto,restantes);
        //cout<<"{"<<z.fi<<","<<z.se<<"}"<<"=="<<restantes<<"\n";
        if(restantes!=0)return true;
        visto.clear();
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    do{
        cin>>n>>m;
        if(n==0 && m==0)break;
        bool r = solve(n,m);
        (r)?cout<<"YES\n":cout<<"NO\n";
    }while(n!=0 || m!=0);
}