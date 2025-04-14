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

struct nodo{
    int u;
    int v;
    double dist;

    const bool operator < (const nodo &otro)const{
        return dist<otro.dist;
    }
};
double dist(double a, double b){
    return sqrt(a*a+b*b);
}

int papa(int nodo, vi &padres){
    if(nodo==padres[nodo])return nodo;
    return padres[nodo] = papa(padres[nodo],padres);
}

double uf(nodo arista,vi &padres){
    int pa = papa(arista.u,padres);
    int pb = papa(arista.v,padres);

    if(pa!=pb){
        padres[pa] = pb;
        return arista.dist;
    }
    return 0;
}

void solve(){
    int n,m,k;

    cin>>n;
    vector<pair<double,double> > coords(n+1);
    fore(i,1,n){
        cin>>coords[i].fi>>coords[i].se;
    }
    vi padres(n+1);
    fore(i,1,n)padres[i] = i;

    vector<nodo> aristas;
    fore(i,1,n){
        fore(j,1,n){
            if(i==j)continue;
            
            aristas.pb({i,j,dist(coords[i].fi-coords[j].fi,coords[i].se-coords[j].se)});
        }
    }
    sort(all(aristas));
    double sol = 0;
    for(auto z:aristas){
        sol+=uf(z,padres);
    }

    cout<<fixed<<setprecision(2)<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        if(t>=1)cout<<"\n";
    }
}