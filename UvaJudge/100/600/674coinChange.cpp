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

void dpsea(ll n, vll &soluciones){
    vll tipos = {50,25,10,5,1};
    soluciones[0] = 1;
    for(int z: tipos){
        fore(i,0,n){
            soluciones[i+z]+=soluciones[i];
        }
    }
}

void solve(ll n,vll &soluciones){
    cout<<soluciones[n]<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    vll soluciones(8000);
    dpsea(7489,soluciones);
    while(cin>>n){
        solve(n,soluciones);
    }
}