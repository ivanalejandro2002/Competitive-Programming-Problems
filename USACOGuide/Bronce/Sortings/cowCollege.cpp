#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(S) S.begin(),S.end()
#define LSOne(S) ((S)&(-S))
#define fore(V,L,R) for(int V = L; V<=R;V++)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
void solve(){
    int n,m,k;
    cin>>n;
    vll dinero(n);
    fore(i,0,n-1)cin>>dinero[i];
    sort(all(dinero));
    ll maximo = 0;
    ll costo = 0;
    ll der = n;
    fore(i,0,n-1){
        if(maximo < der*dinero[i]){
            maximo = der*dinero[i];
            costo = dinero[i];
        }
        der--;
    }
    cout<<maximo<<" "<<costo<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}