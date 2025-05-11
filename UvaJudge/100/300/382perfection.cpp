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
const int MAXN = 60000;

vll cantidad(MAXN+1,1);

void precalculo(){
    int aux;
    ll conteo;
    vb criba(MAXN+1);
    for(int i=2;i<=MAXN;i++){
        if(!criba[i]){
            for(int j = i;j<=MAXN;j+=i){
                aux = j;
                conteo = i;
                while(aux%i==0){
                    aux/=i;
                    conteo*=(ll)i;
                }
                conteo--;
                conteo/=(ll)(i-1);
                cantidad[j]*=(conteo);

                criba[j] = 1;
            }
        }
        cantidad[i]-=i;
    }
    cantidad[1] = 0;
}

void solve(){
    cout<<"PERFECTION OUTPUT\n";
    int n;
    do{
        cin>>n;
        if(n==0)break;
        if(n<10000)cout<<" ";
        if(n<1000)cout<<" ";
        if(n<100)cout<<" ";
        if(n<10)cout<<" ";
        cout<<n<<"  ";

        if(cantidad[n] == n){
            cout<<"PERFECT\n";
        }else if(cantidad[n]<n){
            cout<<"DEFICIENT\n";
        }else{
            cout<<"ABUNDANT\n";
        }
    }while(n!=0);
    cout<<"END OF OUTPUT\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    precalculo();
    solve();
}