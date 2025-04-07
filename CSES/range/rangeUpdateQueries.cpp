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
struct SegmentTree{
    vector<pair<ll,ll> > tree;
    ll n;
    SegmentTree(ll n){
        tree.assign(3*n+2,{0,0});
        this->n = n;
    }
    void propagate(ll nodo, ll ini, ll fin){
        tree[nodo].fi +=tree[nodo].se;
        if(ini!=fin){
            tree[nodo*2].se+=tree[nodo].se;
            tree[nodo*2+1].se+=tree[nodo].se;
        }
        tree[nodo].se=0;
    }
    void build(vector<ll> &a,ll nodo, ll ini, ll fin){
        if(ini==fin){
            tree[nodo].fi=a[ini];
            return;
        }
        ll med = (ini+fin)/2;
        build(a,nodo*2,ini,med);
        build(a,nodo*2+1,med+1,fin);
    }
    void build(vector<ll> &a){
        build(a,1,1,n);
    }
    ll query(ll nodo, ll ini, ll fin, ll mini, ll mfin){
        if(ini>mfin || fin<mini)return 0;
        propagate(nodo,ini,fin);
        if(ini>=mini && fin<=mfin)return tree[nodo].fi;
        ll med = (ini+fin)/2;
        ll izq = query(nodo*2,ini,med,mini,mfin);
        ll der = query(nodo*2+1,med+1,fin,mini,mfin);
        return izq+der;
    }
    ll query(ll ini,ll fin){
        return query(1,1,n,ini,fin);
    }

    void update(ll nodo, ll ini, ll fin , ll mini, ll mfin, ll v){
        if(ini>mfin || fin < mini)return;
        propagate(nodo,ini,fin);
        if(ini>=mini && fin<=mfin){
            tree[nodo].se+=v;
            propagate(nodo,ini,fin);
            return;
        }
        
        ll med = (ini+fin)/2;
        update(nodo*2,ini,med,mini,mfin,v);
        update(nodo*2+1,med+1,fin,mini,mfin,v);
    }

    void updater(ll l, ll r, ll v){
        update(1,1,n,l,r,v);
    }
};
void solve(){
    ll n,m,k,op,l,r,v;
    cin>>n>>k;
    vll datos(n+1);
    fore(i,1,n)cin>>datos[i];
    SegmentTree ST(n);
    ST.build(datos);

    while(k--){
        cin>>op>>l;
        if(op==1){
            cin>>r>>v;
            ST.updater(l,r,v);
        }else{
            cout<<ST.query(l,l)<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}