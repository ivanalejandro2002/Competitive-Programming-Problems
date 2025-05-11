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
typedef long long int ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int solve(ll t){
    double pagos,total,devaluacion,d;
    int rangos;
    cin>>pagos>>total>>rangos;
    
    int pos;
    double porPagar = total;
    vector<double> bajones(t+2);
    vb hay(t+2);
    fore(i,1,rangos){
        cin>>pos>>d;
        bajones[pos] = d;
        hay[pos] =1;
    }

    fore(i,1,t+1){
        if(!hay[i])bajones[i] = bajones[i-1];
    }

    int mes = 1;
    double mensual = total/t;
    total+=pagos;
    total*=1-bajones[0];
    pagos = mensual;
    while(total <= porPagar && mes<=t+1){
        total*=1-bajones[mes];
        porPagar-=pagos;
        mes++;
    }

    return mes-1;
    
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    do{
        cin>>n;
        if(n<0)break;
        int sol = solve(n);
        cout<<sol<<" month";
        if(sol!=1)cout<<"s";
        cout<<"\n";
    }while(n>=0);
}