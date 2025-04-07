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
    cin>>n>>m;
    vvll datitos(m+1);
    fore(i,1,n){
        fore(j,1,m){
            cin>>k;
            datitos[j].pb(k);
        }
    }
    ll suma =0;
    ll total = 0;
    ll derecha,izquierda;
    fore(i,1,m){
        sort(all(datitos[i]));
        for(int z:datitos[i])suma+=z;
        izquierda = 1;
        derecha = n-1;
        for(int z:datitos[i]){
            suma-=z;
            total+= suma-z*derecha;
            derecha--;
            izquierda++;
        }
    }
    cout<<total<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
}