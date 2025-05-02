#include <bits/stdc++.h>
#include <fstream>
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

int area(vi &histograma){
    int n = histograma.size();

    stack<int> pila;

    int sol = 0;
    fore(i,0,n-1){
        while(!pila.empty() && histograma[pila.top()]>=histograma[i]){
            int maximo = pila.top();
            pila.pop();

            int ancho = (pila.empty())? i: i-pila.top()-1;
            sol = max(sol, histograma[maximo] * ancho);
        }
        pila.push(i);
    }

    while(!pila.empty()){
        int maximo = pila.top();
        pila.pop();

        int ancho = (pila.empty())? n: n-pila.top()-1;
        sol = max(sol, histograma[maximo] * ancho);
    }
    return sol;
}

ll solve(int n, int m){
    vi histograma(m);
    int k;
    int mejor = 0;
    fore(i,1,n){
        fore(j,0,m-1){
            cin>>k;
            (!k)?histograma[j]++:histograma[j]=0;
        }
        //for(auto z:histograma)cout<<z<<",";
        //cout<<"\n";
        mejor = max(mejor,area(histograma));
    }
    return mejor;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    do{
        cin>>n>>m;
        if(n==0 && m==0)break;
        cout<<solve(n,m)<<"\n";
    }while(n!=0 || m!=0);
}