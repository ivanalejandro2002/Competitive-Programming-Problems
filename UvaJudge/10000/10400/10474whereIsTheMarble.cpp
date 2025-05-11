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

int binaria(vi &datos, int k){
    int l = 1;
    int r = datos.size();

    int med;
    while(l<r){
        med = (l+r)/2;
        if(datos[med]>=k)r = med;
        else l = med+1;
    }
    return l;
}

void solve(int n,int q){
    vi datos(n+1);
    fore(i,1,n)cin>>datos[i];

    sort(all(datos));
    int k;
    while(q--){
        cin>>k;
        int v = binaria(datos,k);
        if(datos[v]==k){
            cout<<k<<" found at "<<v<<"\n";
        }else{
            cout<<k<<" not found"<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q;
    int i=1;
    do{
        cin>>n>>q;
        if(n==0 && q==0)break;
        cout<<"CASE# "<<i<<":\n";
        solve(n,q);
        i++;
    }while(n!=0 || q!=0);
}