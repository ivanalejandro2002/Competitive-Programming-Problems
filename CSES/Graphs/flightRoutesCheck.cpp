#include <bits/stdc++.h>
using namespace std;
int act= 0;
void tarjan(int nodo,vector<vector<int> > &mapa,vector<int> &vis,vector<pair<int,int> > &visitas,vector<int> &dag,stack<int> &pila,int &cont){
    if(vis[nodo] > 0)return;
    vis[nodo] = 1;
    visitas[nodo].first = visitas[nodo].second=++act;
    pila.push(nodo);

    for(int z:mapa[nodo]){
        if(!vis[z]){
            tarjan(z,mapa,vis,visitas,dag,pila,cont);
            visitas[nodo].second = min(visitas[nodo].second,visitas[z].second);
        }else{
            if(vis[z]==1)
                visitas[nodo].second = min(visitas[nodo].second,visitas[z].first);
        }
    }

    int k = 0;
    if(visitas[nodo].first == visitas[nodo].second){
        cont++;
        int zi =0;
        do{
            k = pila.top();
            pila.pop();
            dag[k] = cont;
            vis[k] = 2;
        }while(k!=nodo);
    }
}

void solve(){
    int n,m,uno,dos;
    cin>>n>>m;
    
    vector<vector<int> > mapa(n+2);
    vector<int> vis(n+2);
    vector<pair<int,int> > visitas(n+2);
    stack<int> pila;
    vector<int> dag(n+2);
    
    for(int i =0;i<m;i++){
        cin>>uno>>dos;
        mapa[uno].push_back(dos);
    }
    
    int componentes = 0;
    for(int i=1;i<=n;i++)
        tarjan(i,mapa,vis,visitas,dag,pila,componentes);
    
    if(componentes == 1){
        cout<<"YES\n";
        return;
    }else{
        int uno = 0;
        int dos = 0;
        while(dag[uno]!=1)uno++;
        while(dag[dos]!=2)dos++;
        cout<<"NO\n"<<uno<<" "<<dos<<"\n";
    }
}
int main(){
    solve();
}