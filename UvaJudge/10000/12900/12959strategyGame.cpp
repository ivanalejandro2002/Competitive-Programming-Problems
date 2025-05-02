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

int solve(int j, int r){
    vi puntos(j);
    int k;
    fore(i,0,j*r-1){
        cin>>k;
        puntos[i%j]+=k;
    }

    int mejor = puntos[0];
    int pos = 1;

    fore(i,1,j-1){
        if(mejor <= puntos[i]){
            mejor = puntos[i];
            pos = i+1;
        }
    }

    return pos;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int j,r;
    while(cin>>j){
        cin>>r;
        cout<<solve(j,r)<<"\n";
    }
}