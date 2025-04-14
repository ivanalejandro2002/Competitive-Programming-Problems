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
typedef double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
 
ld funcion(ld p, ld a, ld b, ld c, ld d,ld k){
    return p*(sin(a*k+b) + cos(c*k+d)+2);
}

void solve(ld p){
    ld mayor = -1e6;
    ld caida = -3e6;

    ld a,b,c,d;
    int n;
    cin>>a>>b>>c>>d>>n;
    fore(i,1,n){
        ld w = funcion(p,a,b,c,d,(ld)i);
        //cout<<w<<",";
        mayor = max(mayor,w);
        caida = max(caida,mayor-w);
    }
    //cout<<"\n";

    cout<<fixed<<setprecision(10)<<caida<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ld p;
    while(cin>>p)
        solve(p);
}