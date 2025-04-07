#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int> > elementos(n);
    for(int i=0;i<n;i++){
        cin>>elementos[i].first>>elementos[i].second;
    }
    sort(elementos.begin(),elementos.end());
    priority_queue<int> finales;
    int cont = 0;
    int maximo = 0;
    for(int i=0;i<n;i++){
        while(!finales.empty() && elementos[i].first>finales.top()*-1){
            finales.pop();
            cont--;
        }
        cont++;
        finales.push(elementos[i].second*-1);
        maximo = max(maximo,cont);
    }
    cout<<maximo<<"\n";
}
int main(){
    solve();
}