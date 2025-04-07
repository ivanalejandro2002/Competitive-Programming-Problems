#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    int n;
    cin>>n;
    vector<ll> datos(n);
    for(int i=1;i<=n;i++)cin>>datos[i];
    ll minimo = 0;
    ll maximo = INT_MIN;
    for(int i=1;i<=n;i++){
        datos[i]+=datos[i-1];
        maximo = max(maximo,datos[i]-minimo);
        minimo = min(minimo,datos[i]);
    }
    cout<<maximo<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}