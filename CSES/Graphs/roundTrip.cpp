#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
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
stack<int> pila;
vector<int> sol;
bool hecho = 0;
pii act,nue;
void busca(int nodo, int padre, vvi &mapa, vb &visto){
    //cout<<nodo<<"__\n";
    if(hecho)return;
    for(int z:mapa[nodo]){
        if(z==padre)continue;
        if(visto[z]){
            hecho = 1;
            do{
                sol.pb(pila.top());
                pila.pop();
            }while(!pila.empty() && sol.back()!=z);
        }
        visto[z] = 1;
        if(hecho)return;
        pila.push(z);
        busca(z,nodo,mapa,visto);
        if(hecho)return;
    }
    if(hecho)return;
    pila.pop();
}
void solve(){
    int n,m,k,u,v;
    cin>>n>>m;
    vvi mapa(n+1);
    for(int i=0;i<m;i++){
        cin>>u>>v;
        mapa[u].pb(v);
        mapa[v].pb(u);
    }
    vb visto(n+1);
    for(int i=1;i<=n && !hecho;i++){
        if(visto[i])continue;
        pila.push(i);
        visto[i] = 1;
        busca(i,-1,mapa,visto);
        while(!pila.empty()){
            pila.pop();
        }
    }
    if(!hecho){
        cout<<"IMPOSSIBLE\n";
        return;
    }

    cout<<sol.size()+1<<"\n";
    cout<<sol.back()<<" ";
    for(int z:sol){
        cout<<z<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}