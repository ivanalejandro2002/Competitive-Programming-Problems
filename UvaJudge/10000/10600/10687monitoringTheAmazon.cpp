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
typedef long long int ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

struct coord{
    ll x;
    ll y;
    coord operator -(coord &otro){return {x-otro.x,y-otro.y};}
    ll dist(){return x*x + y*y;}
};

struct delta{
    coord cv;
    int v;
    ll dist;
    const bool operator<(const delta &otro)const{
        if(dist<otro.dist)return true;
        if(dist>otro.dist)return false;
        if(cv.x<otro.cv.x)return true;
        if(cv.x>otro.cv.x)return false;
        return cv.y<otro.cv.y;
    }
};

void dfs(int nodo, vvi &mapa, vb &vistos){
    if(vistos[nodo])return;
    vistos[nodo] = 1;
    for(int z:mapa[nodo])dfs(z,mapa,vistos);
}

void solve(int n){
    vvi mapa(n+1);
    vector<coord> nodos(n+1);
    fore(i,1,n)cin>>nodos[i].x>>nodos[i].y;
    vector<delta> aristas;
    fore(i,1,n){
        aristas.clear();
        fore(j,1,n){
            if(j==i)continue;
            aristas.pb({nodos[j],j,(nodos[j]-nodos[i]).dist()});
        }
        sort(all(aristas));
        fore(j,0,1){
            if(j>=aristas.size())continue;
            mapa[i].pb(aristas[j].v);
        }
    }
    vb vistos(n+1);
    dfs(1,mapa,vistos);

    bool posible = 1;
    fore(i,1,n)posible&=vistos[i];

    (posible)?cout<<"All stations are reachable.\n":cout<<"There are stations that are unreachable.\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    do{
        cin>>n;
        if(n==0)break;
        solve(n);
    }while(n!=0);
}