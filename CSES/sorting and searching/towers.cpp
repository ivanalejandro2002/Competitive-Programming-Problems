#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define LSOne(S) ((S)&(-S))
#define all(S) S.begin(),S.end()
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
void solve(){
    int n,m,k;
    set<int> derecho;
    set<int> izquierdo;
    cin>>n>>m;
    derecho.insert(n);
    izquierdo.insert(0);
    int dizquierda,dderecha;
    multiset<int> distancias;
    distancias.insert(n);
    multiset<int> ::iterator it;
    for(int i=0;i<m;i++){
        cin>>k;
        dizquierda = (k)+*izquierdo.lower_bound(-k);
        dderecha = *derecho.lower_bound(k)-k;
        //cout<<i<<","<<dderecha<<"__"<<dizquierda<<"\n";
        assert(distancias.count(dderecha+dizquierda)>0);
        distancias.erase(distancias.find(dderecha+dizquierda));
        derecho.insert(k);
        izquierdo.insert(-k);
        distancias.insert(dderecha);
        distancias.insert(dizquierda);
        it = distancias.end();
        //cout<<distancias.size()<<"\n";
        it--;
        cout<<*it<<" ";
    }
    cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}