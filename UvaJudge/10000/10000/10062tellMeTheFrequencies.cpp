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

void solve(string &cad){
    map<int,int> rep;

    for(char co:cad){
        rep[(int)co]++;
    }

    vpii movs;
    for(auto z:rep){
        movs.pb({z.se,-z.fi});
    }

    sort(all(movs));

    for(auto z:movs){
        cout<<-z.se<<" "<<z.fi<<"\n";
    }
    
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    bool hecho = 0;
    while(getline(cin,s)){
        if(hecho)cout<<"\n";
        hecho = 1;
        solve(s);
    }
}