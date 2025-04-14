#include <bits/stdc++.h>
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
    int n,m,k;
    cin>>n;
    vi A(n+1),B(n+1),C(n+1);
    map<int,int> apariciones;
    fore(i,1,n){
        cin>>k;
        apariciones[k]++;
    }
    fore(i,1,n)cin>>B[i];
    ll sol = 0;
    fore(i,1,n){
        cin>>k;
        sol+=apariciones[B[k]];
    }
    cout<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}