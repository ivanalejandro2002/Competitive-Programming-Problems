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

pii dp(int s, vvi &mapa){
    int n = mapa.size()-1;
    vpii DP(n+1);

    fore(i,1,n){
        DP[i] = {0,i};
    }

    vi indegree(n+1);
    fore(i,1,n){
        for(int z: mapa[i])indegree[z]++;
    }

    queue<int> chequeo;

    fore(i,1,n){
        if(!indegree[i])chequeo.push(i);
    }

    int act;
    int mayor = 0;
    while(!chequeo.empty()){
        act = chequeo.front();
        chequeo.pop();

        for(int z: mapa[act]){
            if(DP[z].fi<DP[act].fi+1){
                DP[z] = {DP[act].fi+1,DP[act].se};
            }else if(DP[z].fi==DP[act].fi+1){
                DP[z].se = min(DP[z].se,DP[act].se);
            }
        }

        for(int z:mapa[act]){
            indegree[z]--;
            if(indegree[z]==0)chequeo.push(z);
        }
    }

    int pos = INT_MAX;

    return DP[s];
}

void solve(int n){
    int s;
    cin>>s;

    vvi mapa(n+1);
    int u,v;
    do{
        cin>>u>>v;
        if(u==0 && v==0)break;
        mapa[v].pb(u);
    }while(u!=0 || v!=0);
    pii sol = dp(s,mapa);

    cout<<"The longest path from "<<s<<" has length "<<sol.fi<<", finishing at "<<sol.se<<".\n\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int i =1;
    do{
        cin>>n;
        if(n==0)break;
        cout<<"Case "<<i<<": ";
        solve(n);
        i++;
    }while(n!=0);
}