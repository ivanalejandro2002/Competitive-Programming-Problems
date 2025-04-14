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

void busca(int nodo, vvi &mapa, vb &visto){
    visto[nodo] = 1;
    for(int z:mapa[nodo]){
        if(visto[z])continue;
        busca(z,mapa,visto);
    }
}

int solve(){
    int n,m,k,u,v;
    cin>>n>>m>>k;

    vvi mapa(n+1);
    fore(i,1,m){
        cin>>u>>v;
        mapa[u].pb(v);
    }

    vb vistos(n+1);

    while(k--){
        cin>>u;
        if(vistos[u])continue;
        busca(u,mapa,vistos);
    }
    int cont = 0;
    for(bool z:vistos)cont+=z;
    return cont;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    while(n--){
        cout<<solve()<<"\n";
    }
}