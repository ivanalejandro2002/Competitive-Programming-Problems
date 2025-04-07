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
struct nodo{
    int valor;
    bool iniciado;
    nodo *arriba;
    nodo *abajo;
    nodo(int v):valor(v),iniciado(1),arriba(nullptr),abajo(nullptr){};
};
int numeral(string &cad, int &i,int acum){
    if(i>=cad.size() || cad[i]<'0' || cad[i]>'9'){
        i++;
        return acum;
    }
    acum*=10;
    acum+=cad[i]-'0';
    i++;
    return numeral(cad,i,acum);
}
pair<bool,int> posicion(string &cad, int &i){
    if(cad[i+1]=='n'){
        i+=5;
        int lugar = numeral(cad,i,0);
        return {0,lugar};
    }else if(cad[i+1]=='v'){
        i+=5;
        int lugar = numeral(cad,i,0);
        return {1,lugar};
    }
    return {0,0};
}
void resetea(nodo * bloque, vi &quePila){
    if(bloque==nullptr)return;
    bloque->iniciado = 1;
    quePila[bloque->valor]=bloque->valor;
    bloque->abajo = nullptr;
    resetea(bloque->arriba,quePila);
    bloque->arriba = nullptr;
}
void interpreta(string &cad, int &i,vector<nodo *> &posiciones, vi &quePila){
    if(cad[i]=='m'){
        i+=5;
        int origen = numeral(cad,i,0);
        nodo *bInicio = posiciones[origen];
        pair<bool,int> coso = posicion(cad,i);
        nodo *bDestino = posiciones[coso.second];
        if(quePila[origen]==quePila[coso.second])return;
        resetea(bInicio->arriba,quePila);
        bInicio->arriba = nullptr;

        if(coso.first)
            while(bDestino->arriba!=nullptr)bDestino = bDestino->arriba;
        resetea(bDestino->arriba,quePila);
        bDestino->arriba = nullptr;

        if(bInicio->abajo!=nullptr)bInicio->abajo->arriba = nullptr;
        bDestino->arriba = bInicio;
        bInicio->abajo = bDestino;
        bInicio->iniciado = 0;
        quePila[origen] = quePila[coso.second];
    }else if(cad[i]=='p'){
        i+=5;
        int origen = numeral(cad,i,0);
        nodo *bInicio = posiciones[origen];
        pair<bool,int> coso = posicion(cad,i);
        nodo *bDestino = posiciones[coso.second];
        if(quePila[origen]==quePila[coso.second])return;

        if(coso.first)
            while(bDestino->arriba!=nullptr)bDestino = bDestino->arriba;
        resetea(bDestino->arriba,quePila);
        bDestino->arriba = nullptr;

        if(bInicio->abajo!=nullptr)bInicio->abajo->arriba = nullptr;
        bDestino->arriba = bInicio;
        bInicio->abajo = bDestino;
        bInicio->iniciado = 0;
        quePila[origen] = quePila[coso.second];
    }
}
void imprime(nodo *bloque){
    if(bloque==nullptr)return;
    cout<<" "<<bloque->valor;
    imprime(bloque->arriba);
}
void solve(){
    int n;
    cin>>n;
    vector<nodo *> posiciones(n);
    vector<int> quePila(n);
    for(int i=0;i<n;i++)quePila[i]=i;
    for(int i=0;i<n;i++)posiciones[i]=new nodo(i);
    string cad;
    getline(cin,cad);
    do{
        getline(cin,cad);
        if(cad=="quit")break;
        int i = 0;
        interpreta(cad,i,posiciones,quePila);
    }while(cad!="quit");
    for(int i=0;i<n;i++){
        cout<<i<<":";
        if(posiciones[i]->iniciado){
            imprime(posiciones[i]);
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}