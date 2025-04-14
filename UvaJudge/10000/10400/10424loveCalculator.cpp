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

void solve(string p){
    string q;
    getline(cin,q);

    int uno,dos;
    uno = dos = 0;

    for(char co:p){
        if(co>='a' && co<='z'){
            uno+=co-'a'+1;
        }
        if(co>='A' && co<='Z'){
            uno+=co-'A'+1;
        }
    }

    for(char co:q){
        if(co>='a' && co<='z'){
            dos+=co-'a'+1;
        }
        if(co>='A' && co<='Z'){
            dos+=co-'A'+1;
        }
    }

    int aux;
    int z;
    while(uno>9){
        aux = 0;
        z = uno;
        while(z>0){
            aux+=z%10;
            z/=10;
        }
        uno = aux;
    }
    while(dos>9){
        aux = 0;
        z = dos;
        while(z>0){
            aux+=z%10;
            z/=10;
        }
        dos = aux;
    }

    if(uno>dos)swap(uno,dos);
    double s = (double)uno/(double)dos;
    s*=100;
    cout<<fixed<<setprecision(2)<<s<<" %\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string p;
    while(getline(cin,p))
        solve(p);
}