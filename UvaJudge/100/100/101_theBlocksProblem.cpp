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
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

bool verify(int u, int v, vpii &cima){
    while(u!=-1 && v!=u)u=cima[u].fi;
    return u!=v;
}

void query(bool move, bool onto, vpii &cima, int u, int v){
    if(!verify(u,v,cima))return;
    if(!verify(v,u,cima))return;
    if(!onto){
        while(cima[v].fi!=-1)v = cima[v].fi;
    }

    int x = v;

    int d;
    while(x!=-1){
        d = cima[x].fi;
        cima[x].fi = -1;
        x = d;
        if(x!=-1)cima[x].se=-1;
    }

    if(move){
        x = u;
        while(x!=-1){
            d = cima[x].fi;
            cima[x].fi=-1;
            x = d;
            if(x!=-1)cima[x].se=-1;
        }
    }

    cima[v].fi = u;
    if(cima[u].se!=-1)cima[cima[u].se].fi=-1;
    cima[u].se = v;

}

void solve(){
    int n;
    cin>>n;
    
    vpii cima(n,{-1,-1});

    string cad;

    int u,v;
    bool move;
    bool onto;

    do{
        cin>>cad;
        if(cad[0]=='q')break;

        move = cad[0] == 'm';
        cin>>u;

        cin>>cad;
        onto = cad.back()=='o';
        cin>>v;

        query(move,onto,cima,u,v);
    }while(cad[0]!='q');

    int x;
    for(int i=0;i<n;i++){
        cout<<i<<":";
        if(cima[i].se==-1){
            x = i;
            while(x!=-1){
                cout<<" "<<x;
                x = cima[x].fi;
            }
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}