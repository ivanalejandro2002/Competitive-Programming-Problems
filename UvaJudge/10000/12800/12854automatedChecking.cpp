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

char solve(vb &primero, vb &segundo){
    bool posible = 1;
    fore(i,0,4){
        posible&=(primero[i] ^segundo[i]);
    }
    return (posible)? 'Y':'N';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int p;
    vb primero(5),segundo(5);
    while(cin>>p){
        primero[0] = (p>0);
        fore(i,1,4){cin>>p;primero[i] = (p>0);}

        fore(i,0,4){cin>>p;segundo[i] = (p>0);}
        
        cout<<solve(primero,segundo)<<"\n";
    }
}