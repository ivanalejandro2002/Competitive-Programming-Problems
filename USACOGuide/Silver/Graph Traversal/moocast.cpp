#include <bits/stdc++.h>
#include <fstream>
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
struct vaca{
    ll x;
    ll y;
    ll r;
};

ll distancia(ll x, ll y){
    return x*x + y*y;
}

void busca(int nodo, vvi &mapa, vb &visto, int &cont){
    //cout<<nodo<<"_";
    cont++;
    visto[nodo] = 1;
    for(int z:mapa[nodo]){
        if(visto[z])continue;
        busca(z,mapa,visto,cont);
    }
}
void solve(){
    int n,m,k;

    ifstream fin;
    ofstream fout;
    fin.open("moocast.in");
    fout.open("moocast.out");
    fin>>n;

    vector<vaca> coord(n);
    fore(i,0,n-1){
        fin>>coord[i].x>>coord[i].y>>coord[i].r;
    }
    vvi mapa(n+1);
    fore(i,0,n-1){
        fore(j,0,n-1){
            if(i==j)continue;
            if(distancia(coord[i].x-coord[j].x,coord[i].y-coord[j].y)<=coord[i].r*coord[i].r){
                mapa[i+1].pb(j+1);
            }
        }
    }

    int mejor = 0;
    vb visto;
    fore(i,1,n){
        //cout<<i<<"::\n";
        visto.resize(n+1);
        int cont = 0;
        busca(i,mapa,visto,cont);
        mejor = max(mejor, cont);
        visto.clear();
        //cout<<"\n";
    }

    fout<<mejor;

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}