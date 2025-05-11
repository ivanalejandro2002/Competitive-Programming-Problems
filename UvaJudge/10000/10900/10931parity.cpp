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

void solve(ll n){
    vi datos;
    ll x = n;
    while(x>0){
        datos.pb(x%2);
        x/=2;
    }
    reverse(all(datos));
    cout<<"The parity of ";
    for(int z:datos)cout<<z;
    cout<<" is "<<__builtin_popcountl(n)<<" (mod 2).\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    do{
        cin>>n;
        if(n==0)break;
        solve(n);
    }while(n>=0);
}