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

void solve(int n,int m){
    int l,r;
    set<int> derechos;
    set<int> izquierdos;

    fore(i,1,n)derechos.insert(i);
    fore(i,1,n)izquierdos.insert(-i);
    izquierdos.insert(0);
    derechos.insert(INT_MAX);

    while(m--){
        cin>>l>>r;
        fore(i,l,r)derechos.erase(i);
        fore(i,l,r)izquierdos.erase(-i);

        int ni,nd;
        ni = -*izquierdos.upper_bound(-l);
        nd = *derechos.upper_bound(r);

        if(ni == 0)cout<<"* ";
        else cout<<ni<<" ";
        if(nd == INT_MAX)cout<<"*\n";
        else cout<<nd<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    do{
        cin>>n>>m;
        if(n==0 && m==0)break;
        solve(n,m);
        cout<<"-\n";
    }while(n!=0 || m!=0);
}