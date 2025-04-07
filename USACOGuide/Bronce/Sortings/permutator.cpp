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
    vll a(n);
    fore(i,0,n-1)cin>>a[i];
    ll izq = 1,der = n;
    fore(i,0,n-1){
        a[i]*=izq*der;
        izq++;
        der--;
    }

    sort(all(a));

    vll b(n);
    fore(i,0,n-1)cin>>b[i];
    sort(all(b));
    reverse(all(b));

    ll sol = 0;
    fore(i,0,n-1){
        sol+=a[i]*b[i];
    }
    cout<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}