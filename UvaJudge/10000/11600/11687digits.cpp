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

int solve(string s){
    if(s == "0")return 2;
    if(s == "1")return 1;
    int cont =2;
    int x = s.size();
    while(x>1){
        int w = 0;
        int aux = x;
        while(aux>0){
            aux/=10;
            w++;
        }
        x = w;
        cont++;
    }
    return cont;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    do{
        cin>>s;
        if(s=="END")break;
        cout<<solve(s)<<"\n";
    }while(s!="END");
}