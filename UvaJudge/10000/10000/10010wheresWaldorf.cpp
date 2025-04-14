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

vpii mov = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

bool invalido(int sy, int sx, vector<string> &sopa){
    if(sy<0 || sx<0 || sy>=sopa.size() || sx>=sopa[0].size())return true;
    return false;
}

void busca(vector<string> &sopa, string &cad){
    for(int i=0;i<sopa.size();i++){
        fore(j,0,sopa[0].size()-1){
            for(auto z: mov){
                int sx,sy;
                sy = i;
                sx = j;
                bool hecho = 1;
                fore(k,0,cad.size()-1){
                    //cout<<k<<"_";
                    if(invalido(sy,sx,sopa) || cad[k]!=sopa[sy][sx]){
                        hecho = 0;
                        break;
                    }
                    sy+=z.fi;
                    sx+=z.se;
                }
                //cout<<"\n";
                if(hecho){
                    cout<<i+1<<" "<<j+1<<"\n";
                    return;
                }
            }
        }
    }
    cout<<":(\n";
}

void solve(){
    int n,m,k;
    
    cin>>n>>m;
    vector<string> sopa(n);
    fore(i,0,n-1)cin>>sopa[i];
    fore(i,0,n-1){
        fore(j,0,m-1){
            if(sopa[i][j]>='A' && sopa[i][j]<='Z')sopa[i][j]+='a'-'A';
        }
    }

    //fore(i,0,n-1)cout<<sopa[i]<<"\n";

    cin>>k;
    string obj;
    while(k--){
        cin>>obj;
        for(int i=0;i<obj.size();i++){
            if(obj[i]>='A' && obj[i]<='Z')obj[i]+='a'-'A';
        }
        //cout<<obj<<"\n";
        busca(sopa,obj);
    }
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