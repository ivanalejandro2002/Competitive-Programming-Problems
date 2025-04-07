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
    int n,k,l,r;
    cin>>n>>k;
    vll datos(n+1);
    fore(i,1,n)cin>>datos[i];
    fore(i,1,n)datos[i]^=datos[i-1];

    while(k--){
        cin>>l>>r;
        cout<<(datos[r]^datos[l-1])<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}