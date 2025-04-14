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
    ll n,m,k;
    cin>>n;
    map<char,ll> cambios;
    char z;
    fore(i,1,n){
        cin>>z>>k;
        cambios[z] = k;
    }
    cin>>m;
    string cad;
    getline(cin,cad);
    ll total = 0;
    while(m--){
        getline(cin,cad);
        for(char co:cad)total+=cambios[co];
    }
    cout<<total/100<<".";
    if(total%100<10)cout<<"0";
    cout<<total%100<<"$\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}