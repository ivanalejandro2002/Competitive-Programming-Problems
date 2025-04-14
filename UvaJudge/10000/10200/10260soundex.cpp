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

void solve(){
    string cad;
    map<char,char> cambio;
    cambio['B'] = 1;
    cambio['F'] = 1;
    cambio['P'] = 1;
    cambio['V'] = 1;
    cambio['C'] = 2;
    cambio['G'] = 2;
    cambio['J'] = 2;
    cambio['K'] = 2;
    cambio['Q'] = 2;
    cambio['S'] = 2;
    cambio['X'] = 2;
    cambio['Z'] = 2;
    cambio['D'] = 3;
    cambio['T'] = 3;
    cambio['L'] = 4;
    cambio['M'] = 5;
    cambio['N'] = 5;
    cambio['R'] = 6;
    while(cin>>cad){
        int anterior = -1;
        for(char co:cad){
            if(anterior == cambio[co])continue;
            anterior = cambio[co];
            if(cambio[co]==0)continue;
            cout<<anterior;
        }
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}