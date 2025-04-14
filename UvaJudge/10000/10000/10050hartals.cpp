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
    int n,p;
    cin>>n>>p;
    int dact = 6;
    vpii partidos(p);
    fore(i,0,p-1){cin>>partidos[i].fi;partidos[i].se=partidos[i].fi;}
    
    bool hay = 0;
    int sol = 0;
    fore(i,1,n){
        fore(j,0,p-1){
            if(partidos[j].fi==i){
                hay = 1;
                partidos[j].fi+=partidos[j].se;
            }
        }
        if(hay && dact!=4 && dact!=5)sol++;

        dact++;
        if(dact>=7)dact-=7;
        hay = 0;
    }
    cout<<sol<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}