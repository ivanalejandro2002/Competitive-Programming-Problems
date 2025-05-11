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

void solve(int n, int m){
    vvi mapa(n+1);
    int u,v;
    vi indegree(n+1);
    fore(i,1,m){
        cin>>u>>v;
        mapa[u].pb(v);
        indegree[v]++;
    }

    queue<int> cola;
    fore(i,1,n){
        if(indegree[i]==0)cola.push(i);
    }

    int act;
    bool hecho = 0;
    while(!cola.empty()){
        act = cola.front();
        cola.pop();
        if(hecho)cout<<" ";
        hecho = 1;
        cout<<act;

        for(int z:mapa[act]){
            indegree[z]--;
            if(indegree[z]==0)cola.push(z);
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    do{
        cin>>n>>m;
        if(n==0 && m==0)break;
        solve(n,m);
    }while(n!=0 || m!=0);
}