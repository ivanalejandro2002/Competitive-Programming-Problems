#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define all(S) S.begin(),S.end()
#define LSOne(S) ((S)&(-S))
#define fore(V,L,R) for(int V = L; V<=R;V++)
using namespace std;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
void solve(){
    int n,k;
    char co;
    cin>>n>>k;
    vvll mapa(n+1,vll(n+1));

    fore(i,1,n){
        fore(j,1,n){
            cin>>co;
            if(co=='*')mapa[i][j] = 1;
        }
    }
    fore(i,1,n){
        fore(j,1,n){
            mapa[i][j] += mapa[i-1][j]+mapa[i][j-1]-mapa[i-1][j-1];
        }
    }
    int x1,y1,x2,y2;
    while(k--){
        cin>>y1>>x1>>y2>>x2;

        cout<<mapa[y2][x2]-mapa[y2][x1-1]-mapa[y1-1][x2]+mapa[y1-1][x1-1]<<"\n";

    }

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}