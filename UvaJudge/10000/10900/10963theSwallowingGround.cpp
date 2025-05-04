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

string solve(){
    int n;
    cin>>n;
    int a,b;
    int ancho = 0;
    bool posible = 1;
    fore(i,1,n){
        cin>>a>>b;
        if(i==1)ancho = b-a;
        else if(ancho!= b-a)posible = 0;
    }
    if(!posible)return "no";
    return "yes";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
        if(t>=1)cout<<"\n";
    }
}