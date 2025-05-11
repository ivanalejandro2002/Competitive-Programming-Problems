#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
#define fore(V,I,F) for(int V=I;V<=F;V++)
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

int solve(int n, int m, int c){
    vi gasto(n+1);
    int mejor = 0;
    fore(i,1,n)cin>>gasto[i];

    vb encendido(n+1);
    int k;
    int suma = 0;
    fore(i,1,m){
        cin>>k;
        encendido[k]=!encendido[k];

        if(encendido[k])suma+=gasto[k];
        else suma-=gasto[k];

        mejor = max(mejor,suma);
        if(suma>c){
            fore(j,i+1,m)cin>>k;
            cout<<"Fuse was blown.\n\n";
            return -1;
        }
    }
    cout<<"Fuse was not blown.\n";
    return mejor;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,c;
    int i=1;
    do{
        cin>>n>>m>>c;
        if(n==0 && m==0 && c==0)break;
        cout<<"Sequence "<<i<<"\n";
        int s = solve(n,m,c);
        i++;
        if(s==-1)continue;
        cout<<"Maximal power consumption was "<<s<<" amperes.\n\n";
    }while(n!=0 || m!=0 || c!=0);
}