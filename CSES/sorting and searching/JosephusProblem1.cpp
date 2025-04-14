#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
void solve(){
    int n,m,k;
    cin>>n;
    vpii lista(n+1);
    for(int i=1;i<=n;i++){
        int izq = i-1;
        if(izq<1)izq=n;
        int der = i+1;
        if(der>n)der=1;
        lista[i]={izq,der};
    }
    int act = n;
    for(int i=1;i<=n;i++){
        act = lista[lista[act].second].second;
        cout<<act<<" ";
        lista[lista[act].first].second = lista[act].second;
        lista[lista[act].second].first = lista[act].first;
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}