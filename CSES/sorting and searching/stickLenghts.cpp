#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void solve(){
    int n;
    cin>>n;
    ll suma = 0;
    vector<ll> datos(n);
    for(int i=0;i<n;i++){
        cin>>datos[i];
        suma+=datos[i];
    }
    ll minimo = LLONG_MAX;
    ll aux;
    for(int i=0;i<n;i++){
        aux = n*datos[i];
        minimo = min(minimo,abs(aux-suma));
    }
    cout<<minimo<<"\n";
}
int main(){
    solve();
}