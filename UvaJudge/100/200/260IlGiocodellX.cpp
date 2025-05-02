#include <bits/stdc++.h>
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

vpii mov= {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1}};

bool si(int sy, int sx, vector<string> &mapa,char target,vvb &visto){
    if(sy<0 || sx <0 || sy>=mapa.size() || sx>=mapa.size())return false;
    if(mapa[sy][sx] != target || visto[sy][sx])return false;
    return true;
}

void dfs(int y, int x, pii &vert, pii &hor, vector<string> &mapa, vvb &visto,char target){
    vert.se = max(vert.se,y);
    vert.fi = min(vert.fi,y);

    hor.fi = min(hor.fi,x);
    hor.se = max(hor.se,x);

    visto[y][x] = 1;

    for(auto z: mov){
        if(si(y+z.fi,x+z.se,mapa,target,visto)){
            dfs(y+z.fi, x +z.se, vert,hor,mapa,visto,target);
        }
    }
}

pair<int,int> busca(int y, int x, vector<string> &mapa, vvb &visto, char target){
    pii vert,hor;
    vert = {y,y};
    hor = {x,x};

    dfs(y,x,vert,hor,mapa,visto,target);

    
    return {vert.se-vert.fi, hor.se-hor.fi};
}

string solve(int n){
    vector<string> mapa(n);

    fore(i,0,n-1)cin>>mapa[i];

    vvb visto(n,vb(n));
    fore(i,0,n-1){
        if(mapa[i][0]=='w' && !visto[i][0]){
            auto [a,b] = busca(i,0,mapa,visto,'w');

            if(b + 1 ==n) return "W\n";
        }
    }
    return "B\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int i=1;
    do{
        cin>>n;
        if(n==0)break;
        cout<<i<<" "<<solve(n);
        i++;
    }while(n!=0);
}