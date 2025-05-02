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

void solve(int acum){
    vi nuevos(12);
    fore(i,0,11)cin>>nuevos[i];

    int k = 0;
    fore(i,0,11){
        cin>>k;
        
        cout<<"No problem";
        if(k<=acum){
            acum-=k;
            cout<<"! :D\n";
        }else{
            cout<<". :(\n";
        }

        acum+=nuevos[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    int i=1;
    do{
        cin>>n;
        if(n<0)break;
        cout<<"Case "<<i<<":\n";
        solve(n);
        i++;
    }while(n>=0);
}