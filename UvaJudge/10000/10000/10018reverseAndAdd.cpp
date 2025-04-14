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

bool checar(const string &cad){
    int n = cad.size();
    for(int i=0;i<cad.size();i++)
        if(cad[i]!=cad[n-i-1])return false;
    
    return true;
}

string suma(const string &a, const string &b){
    string sol = "";
    int n=a.size();
    bool carry = 0;
    for(int i=0;i<n;i++){
        int sa = a[i]-'0';
        int sb = b[i]-'0';

        sa+=sb+carry;

        sol+=(char)((sa%10)+'0');
        carry = sa>=10;

    }
    if(carry)sol+='1';
    return sol;
}

void solve(){
    string cad;
    cin>>cad;
    reverse(all(cad));
    int veces = 0;
    bool terminado = 0;
    do{
        if(checar(cad)){
            cout<<veces<<" "<<cad<<"\n";
            terminado = 0;
            break;
        }else{
            string otro = cad;
            reverse(all(otro));
            cad = suma(cad,otro);
        } 
        veces++;

    }while(!terminado);
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}