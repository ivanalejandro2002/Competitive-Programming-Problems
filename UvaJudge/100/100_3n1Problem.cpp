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
int query(vi &ST,int nodo, int ini, int fin, int mini, int mfin){
    if(ini>mfin || fin<mini)return 0;
    if(ini>=mini && fin<=mfin)return ST[nodo];
    int med = (ini+fin)/2;
    int izq,der;
    izq = query(ST,nodo*2,ini,med,mini,mfin);
    der = query(ST,nodo*2+1,med+1,fin,mini,mfin);
    return max(izq,der);
}
void solve(vi &ST){
    int ini,fin;
    while(cin>>ini){
        cin>>fin;
        cout<<ini<<" "<<fin<<" "<<query(ST,1,1,10000,ini,fin)<<"\n";
    }
}
void mejor(ll nactual,vi &vistos){
    ll pasos = 0;
    ll orig = nactual;
    while(nactual!=1){
        pasos++;
        if(!(nactual & 1)){
            nactual/=2;
        }else{
            nactual*=3;
            nactual++;
        }
    }
    vistos[orig]=pasos+vistos[nactual];
}
void initialize(vi &ST,int nodo, int ini,int fin,vi &vistos){
    if(ini==fin){
        ST[nodo]=vistos[ini];
        return;
    }
    int med = (ini+fin)/2;
    initialize(ST,nodo*2,ini,med,vistos);
    initialize(ST,nodo*2+1,med+1,fin,vistos);
    ST[nodo]=max(ST[nodo*2],ST[nodo*2+1]);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vi vistos(10002);
    vistos[1]=1;
    vi ST(40002);
    for(int i=2;i<=10000;i++){
        mejor(i,vistos);
    }
    initialize(ST,1,1,10000,vistos);
    solve(ST);
}