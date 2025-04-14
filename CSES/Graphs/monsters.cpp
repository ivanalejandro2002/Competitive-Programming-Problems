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
struct nodo{
    int y;
    int x;
    int t;
}act,nue;
vpii mov={{0,1},{1,0},{0,-1},{-1,0}};
string paso = "LURD";
int soly,solx;
bool encontrado = 0;
void si(int sy, int sx, int ti, vector<string> &mapa, vvb &vistos, vvi &tiempos, queue<nodo> &cola){
    if(sy<0 || sx < 0 || sy > mapa.size()-1 || sx>mapa[0].size()-1){
        return;
    }
    if(vistos[sy][sx] || mapa[sy][sx]=='#')return;
    vistos[sy][sx]=1;
    tiempos[sy][sx] = ti+1;
    nue = {sy,sx,ti+1};
    cola.push(nue);
}

void busca(int n, int m, vector<string> &mapa, vvi &tiempos, vvb &vistos, queue<nodo> &cola){
    
    while(!cola.empty()){
        act = cola.front();
        cola.pop();

        for(auto z:mov){
            si(act.y+z.fi,act.x+z.se,act.t,mapa,vistos,tiempos,cola);
        }
    }
}

void si(int sy,int sx, int ti,int ciclo,vector<string> &mapa, queue<nodo> &cola, vvb &vistos, vvi &tiempos, vvi &origen){
    if(sy<0 || sx<0 || sy>=mapa.size() || sx>=mapa[0].size())return;
    if(vistos[sy][sx] || mapa[sy][sx] == '#' || tiempos[sy][sx]<=ti+1)return;
    origen[sy][sx] = ((ciclo)+2)%4;
    vistos[sy][sx] = 1;
    nue = {sy,sx,ti+1};
    cola.push(nue);
    if(sy == 0 || sx == 0 || sy==mapa.size()-1 || sx==mapa[0].size()-1){
        encontrado = 1;
        soly = sy;
        solx = sx;
        return;
    }
}

void buscando(vector<string> &mapa,queue<nodo> &cola, vvb &vistos, vvi &tiempos, vvi &origen){
    while(!cola.empty()){
        act = cola.front();
        cola.pop();

        if(act.t >=tiempos[act.y][act.x])continue;
        for(int i=0;i<4;i++){
            auto z = mov[i];
            si(act.y+z.fi,act.x+z.se,act.t,i,mapa,cola,vistos,tiempos,origen);
        }
    }
}

void solve(){
    int n,m,k;
    cin>>n>>m;
    vector<string> mapa(n);
    for(int i=0;i<n;i++)cin>>mapa[i];
    int ey,ex;
    queue<nodo> cola;

    vvb vistos(n,vb(m));
    vvi tiempos(n,vi(m,INT_MAX));


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mapa[i][j]=='A'){
                ey = i;
                ex = j;
            }
            if(mapa[i][j]=='M'){
                vistos[i][j] = 1;
                tiempos[i][j] = 0;
                cola.push({i,j,0});
            }
        }
    }

    if(ey==0 || ex == 0 || ey==n-1 || ex==m-1){
        cout<<"YES\n0\n";
        return;
    }

    

    busca(n,m,mapa,tiempos,vistos,cola);
    /*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<tiempos[i][j]<<",";
        }
        cout<<"\n";
    }
    cout<<"\n";*/


    vistos.clear();
    vistos.resize(n,vb(m));

    while(!cola.empty())cola.pop();
    cola.push({ey,ex,0});
    vistos[ey][ex] = 1;
    vvi origen(n,vi(m));
    origen[ey][ex] = -1;
    buscando(mapa,cola, vistos,tiempos,origen);
    
    if(!encontrado){
        cout<<"NO\n";
        return;
    }

    /*cout<<"\n\n";

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<origen[i][j]<<",";
        }
        cout<<"\n";
    }
    cout<<"\n";*/

    int ay,ax;
    ay = soly;
    ax = solx;
    int auxy,auxx;
    string sol = "";
    while(origen[ay][ax]>=0){
        sol+=paso[origen[ay][ax]];
        auxy=mov[origen[ay][ax]].fi;
        auxx=mov[origen[ay][ax]].se;
        ay+=auxy;
        ax+=auxx;
    }
    cout<<"YES\n";
    cout<<sol.size()<<"\n";
    reverse(all(sol));
    cout<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}