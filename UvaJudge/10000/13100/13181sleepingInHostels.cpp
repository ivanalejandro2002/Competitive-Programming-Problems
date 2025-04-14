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

int solve(string cad){
    int conteo = 0;
    int n = cad.size();
    vi dist;
    int mejor = 0;
    bool hubo = 0;
    for(char co:cad){
        if(co=='.'){
            conteo++;
        }else{
            hubo = 1;
            if(conteo>0)dist.pb(conteo);
            conteo = 0;
        }
    }
    if(!hubo)return n;
    if(conteo>0)dist.pb(conteo);

    if(cad[0] == '.')mejor = max(mejor,dist[0]-1);
    if(cad.back()=='.')mejor = max(mejor,dist.back()-1);

    for(int i=0;i<dist.size();i++){
        mejor = max(mejor, (dist[i]-1)/2);
    }
    return mejor;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    while(cin>>s){
        cout<<solve(s)<<"\n";
    }
}