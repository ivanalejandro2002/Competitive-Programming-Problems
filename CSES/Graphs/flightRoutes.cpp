#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
struct node{
    ll nodo;
    ll tiempo;
};
bool operator < (node a, node b){
    if(a.tiempo<b.tiempo)return false;
    return true;
}
ll k;
vector<vector<ll> > dijkstra(vector<vector<pair<ll,ll> > > &mapa,ll meta){
    priority_queue<node> pq;
    pq.push({1,0});

    vector<bool> visitados (mapa.size());
    node actual, nuevo;
    vector<vector<ll> > tiempos(mapa.size());
    
    
    while(!pq.empty()){
        do{
            actual = pq.top();
            pq.pop();
        }while(!pq.empty() && visitados[actual.nodo]==1);
        if(visitados[actual.nodo]==1){
            return tiempos;
        }

        tiempos[actual.nodo].push_back(actual.tiempo);
        if(tiempos[actual.nodo].size()==k)
            visitados[actual.nodo]=1;
        for(auto z: mapa[actual.nodo]){
            if(visitados[z.first])continue;
            
            nuevo.nodo = z.first;
            nuevo.tiempo = z.second+ actual.tiempo;
            pq.push(nuevo);
        }
    }
    return tiempos;
}
void solve(){
    ll n,m,u,v,costo;
    cin>>n>>m>>k;
    vector<vector<pair<ll,ll> > > mapa(n+2);
    for(ll i =0; i< m ;i++){
        cin>>u>>v>>costo;
        mapa[u].push_back({v,costo});
    }
    ll meta = n;
    vector<vector<ll> > sol = dijkstra(mapa,meta);
    for(ll z:sol[n]){
        cout<<z<<" ";
    }
    cout<<"\n";
}
int main()
{
    solve();
    return 0;
}