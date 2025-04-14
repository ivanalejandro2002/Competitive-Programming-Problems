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

void solve(){
    int n;
    cin>>n;
    vi numeros(n);
    fore(i,0,n-1)cin>>numeros[i];

    int mayor = numeros[0];
    int respuesta = INT_MIN;

    fore(i,1,n-1){
        respuesta = max(respuesta,mayor-numeros[i]);
        mayor = max(mayor,numeros[i]);
    }
    cout<<respuesta<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}