#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
struct node{
    ll nodo;
    ll tiempo;
    bool usado;
};
bool operator < (node a, node b){
    if(a.tiempo<b.tiempo)return false;
    return true;
}

void dijkstra(vector<vector<pair<ll,ll> > > &mapa,ll meta){
    priority_queue<node> pq;
    pq.push({1,0,0});

    vector<vector<bool> > visitados (2,vector<bool>(mapa.size()));
    node actual, nuevo;
    
    
    while(!pq.empty()){
        do{
            actual = pq.top();
            pq.pop();
        }while(!pq.empty() && visitados[actual.usado][actual.nodo]==1);
        if(visitados[actual.usado][actual.nodo]==1){
            cout<<"Es imposible llegar de u -> v";
            return;
        }

        if(actual.nodo==meta){
            cout<<actual.tiempo<<"\n";
            return;
        }
        visitados[actual.usado][actual.nodo]=1;
        for(auto z: mapa[actual.nodo]){
            if(actual.usado == 0 && !visitados[0][z.first]){
                nuevo.nodo = z.first;
                nuevo.tiempo = z.second+ actual.tiempo;
                nuevo.usado = 0;
                pq.push(nuevo);
            }
            if(actual.usado==0 && !visitados[1][z.first]){
                nuevo.nodo = z.first;
                nuevo.tiempo = z.second/2+ actual.tiempo;
                nuevo.usado = 1;
                pq.push(nuevo);
            }
            if(actual.usado == 1 && !visitados[1][z.first]){
                nuevo.nodo = z.first;
                nuevo.tiempo = z.second+ actual.tiempo;
                nuevo.usado = 1;
                pq.push(nuevo);
            }
        }
    }
}
void solve(){
    ll n,m,u,v,costo;
    cin>>n>>m;
    vector<vector<pair<ll,ll> > > mapa(n+2);
    for(ll i =0; i< m ;i++){
        cin>>u>>v>>costo;
        mapa[u].push_back({v,costo});
    }
    ll meta = n;
    dijkstra(mapa,meta);
}
int main()
{
    solve();
    return 0;
}