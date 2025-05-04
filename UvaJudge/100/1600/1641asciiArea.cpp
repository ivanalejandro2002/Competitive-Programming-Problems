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

int solve(int h, int w){
    vector<string> mapa(h);
    fore(i,0,h-1)cin>>mapa[i];

    bool abierto =0;
    int sol = 0;
    fore(i,0,h-1){
        fore(j,0,w-1){
            if(mapa[i][j]=='.'){
                sol+=abierto;
            }else{
                abierto = !abierto;
                if(abierto == 0)sol++;
            }
        }
    }
    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h,w;
    while(cin>>h>>w){
        cout<<solve(h,w)<<"\n";
    }
}