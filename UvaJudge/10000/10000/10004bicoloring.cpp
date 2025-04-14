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

void checar(int nodo,vvi &mapa, vb &visto, vi &color, bool &posible,int cactual){
    visto[nodo] = 1;
    color[nodo] = cactual;

    for(int z:mapa[nodo]){
        if(visto[z]){
            if(color[z]==color[nodo])posible=0;
            continue;
        }
        checar(z,mapa,visto,color,posible,(cactual%2)+1);
    }
}

void solve(int n,int m){
    int u,v;
    vvi mapa(n+1);
    vi color(n+1);
    vb visto(n+1);

    fore(i,1,m){
        cin>>u>>v;
        mapa[u].pb(v);
        mapa[v].pb(u);
    }
    
    bool posible = 1;
    checar(1,mapa,visto,color,posible,1);
    (posible)?cout<<"BICOLORABLE.\n":cout<<"NOT BICOLORABLE.\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    do{
        cin>>n;
        if(n==0)break;
        cin>>m;
        solve(n,m);
    }while(n!=0);
}