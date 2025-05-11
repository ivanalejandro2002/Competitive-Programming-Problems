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

int checa(int b, int d, int s){
    if(d+s<=b)return d;
    return 0;
}

int solve(int n,int m){
    int sol = 0;
    int dineroN,dineroC;
    int b,suma,daedalus,v;
    while(m--){
        suma = 0;
        cin>>b;
        fore(i,1,n){
            cin>>v;
            if(i==1)daedalus = v;
            else suma+=v;
        }
        dineroN = checa(b,daedalus,suma);

        dineroC = max(checa(b,10000,suma),
                max(checa(b,1000,suma),
                max(checa(b,100,suma),
                max(checa(b,10,suma),
                checa(b,1,suma)))));
        sol+=dineroC-dineroN;
    }

    return sol;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    while(cin>>n>>m){
        cout<<solve(n,m)<<"\n";
    }
}