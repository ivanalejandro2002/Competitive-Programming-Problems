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
bool exclusividad;
void busca(int nodo, int padre, vvi &mapa, vb &visto){
    for(int z:mapa[nodo]){
        if(z == padre)continue;
        if(visto[z]){
            exclusividad = 1;
            continue;
        }
        visto[z] = 1;
        busca(z,nodo,mapa,visto);
    }
}
void solve(){
    int n,m,k;

    cin>>n;
    vvi mapa(n+1);
    set<pii> hechos;
    int extras = 0;
    int exclusivas = 0;
    fore(i,1,n){
        cin>>k;
        if(!hechos.count({min(i,k),max(i,k)})){
            mapa[i].pb(k);
            mapa[k].pb(i);
            hechos.insert({min(i,k),max(i,k)});
        }else extras++;
    }

    int obligadas = 0;
    vb visto(n+1);
    int cont = 0;
    fore(i,1,n){
        if(visto[i])continue;
        if(mapa[i].size()==1){
            obligadas++;
            visto[i] = 1;
            busca(i,-1,mapa,visto);
        }
    }

    fore(i,1,n){
        if(visto[i])continue;
        exclusividad = 0;
        busca(i,-1,mapa,visto);
        if(!exclusividad){
            obligadas++;
        }else{
            exclusivas++;
        }
    }
    if(extras>0){
        cout<<exclusivas+max(obligadas-extras,1)<<" "<<obligadas+exclusivas<<"\n";
    }else{
        cout<<exclusivas+obligadas<<" "<<obligadas+exclusivas<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}