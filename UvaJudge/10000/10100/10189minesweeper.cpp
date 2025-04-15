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
const ll mod = 1e9+7;

vpii mov={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

void solve(int n,int m){
    string ori ="";
    fore(i,0,m)ori+='*';
    vector<string> mapa(n+2);
    mapa[0] = mapa[n+1] = ori;
    fore(i,1,n){
        cin>>mapa[i];
        mapa[i] = '*' + mapa[i] + '*';
    }

    fore(i,1,n){
        fore(j,1,m){
            if(mapa[i][j]=='.')mapa[i][j]='0';
        }
    }
    fore(i,1,n){
        fore(j,1,m){
            if(mapa[i][j]!='*')continue;
            for(auto z:mov){
                if(mapa[i+z.fi][j+z.se]=='*')continue;
                mapa[i+z.fi][j+z.se]++;
            }
        }
    }

    fore(i,1,n){
        fore(j,1,m){
            cout<<mapa[i][j];
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,i=1;
    bool hecho = 0;
    do{
        cin>>n>>m;
        if(n==0 && m==0)break;
        if(hecho)cout<<"\n";
        hecho = 1;
        cout<<"Field #"<<i<<":\n";
        solve(n,m);
        i++;
    }while(n!=0 || m!=0);
}