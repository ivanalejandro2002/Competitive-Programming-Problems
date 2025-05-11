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

struct bfsNode{
    int y,x,t;
};

vpii movs={{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1},{-1,-2},{-2,-1}};

void query(int sy, int sx, int t, vvi &tiempo, queue<bfsNode> &cola){
    if(sy<0 || sx<0 || sy>=8 || sx>=8)return;
    if(tiempo[sy][sx]>=0)return;

    tiempo[sy][sx] = t+1;
    cola.push({sy,sx,t+1});
}

int bfs(int ey,int ex, int sy, int sx){
    vvi tiempo(8,vi(8,-1));

    queue<bfsNode> cola;
    cola.push({ey,ex,0});
    tiempo[ey][ex] = 0;

    bfsNode act;
    while(!cola.empty()){
        act = cola.front();
        cola.pop();
        for(auto z:movs){
            query(act.y+z.fi,act.x+z.se,act.t,tiempo,cola);
        }
    }

    return tiempo[sy][sx];
}

void solve(string &e, string &s){
    int ex,ey,sx,sy;
    ex = e[0]-'a';
    sx = s[0]-'a';

    ey = e[1]-'1';
    sy = s[1]-'1';

    cout<<"To get from "<<e<<" to "<<s<<" takes "<<bfs(ey,ex,sy,sx)<<" knight moves.\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string e,s;
    while(cin>>e>>s){
        solve(e,s);
    }
}