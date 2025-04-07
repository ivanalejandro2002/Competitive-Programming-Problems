#include <bits/stdc++.h>
using namespace std;
struct nodo{
    int first;
    int second;
};
bool operator < (nodo a, nodo b){
    return a.second<b.second;
}
void solve(){
    int n;
    cin>>n;
    vector<nodo> datos(n);
    for(int i=0;i<n;i++){
        cin>>datos[i].first>>datos[i].second;
    }
    sort(datos.begin(),datos.end());
    int actual = 0;
    int cont = 0;
    for(int i=0;i<n;i++){
        if(datos[i].first>=actual){
            cont++;
            actual = datos[i].second;
        }
    }
    cout<<cont<<"\n";
}
int main(){
    solve();
}