#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > movs = {{-1,0},{0,1},{1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

bool valido(int y, int x, vector<string> &mapa, vector<vector<bool> > &visitados){
    if(y < 0 || x < 0 || y>=mapa.size() || x>=mapa[0].size())return false;
    if(visitados[y][x] || mapa[y][x]!='@')return false;

    visitados[y][x] = 1;
    return true;
}

void dfs(int y, int x, vector<string> &mapa, vector<vector<bool> > &visitados){
    for(auto d: movs){
        if(valido(y + d.first , x + d.second , mapa, visitados))
            dfs(y + d.first, x + d.second, mapa, visitados);
    }
}

void solve(int n, int m){
    vector<string> mapa(n);
    
    for(int i = 0; i < n; i++)cin>>mapa[i];

    vector<vector<bool> > visitados(n, vector<bool> (m));

    int meteoritos = 0;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){

            if(visitados[i][j] || mapa[i][j] == '*')continue;

            meteoritos++;

            dfs(i,j,mapa,visitados);
        }
    }

    cout<<meteoritos<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    do{
        cin>>n>>m;
        if(n==0 && m==0)break;
        solve(n,m);
    }while(n!=0 ||m!=0);
}