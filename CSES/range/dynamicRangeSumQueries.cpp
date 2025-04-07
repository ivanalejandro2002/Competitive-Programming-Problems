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
    vector<ll> tree;
    ll n;
    SegmentTree(ll n){
        tree.assign(3*n+2,0);
        this->n = n;
    }
    void build(vector<ll> &a,ll nodo, ll ini, ll fin){
        if(ini==fin){
            tree[nodo]=a[ini];
            return;
        }
        ll med = (ini+fin)/2;
        build(a,nodo*2,ini,med);
        build(a,nodo*2+1,med+1,fin);
        tree[nodo]=tree[nodo*2]+tree[nodo*2+1];
    }
    void build(vector<ll> &a){
        build(a,1,1,n);
    }
    ll query(ll nodo, ll ini, ll fin, ll mini, ll mfin){
        if(ini>mfin || fin<mini)return 0;
        if(ini>=mini && fin<=mfin)return tree[nodo];
        ll med = (ini+fin)/2;
        ll izq = query(nodo*2,ini,med,mini,mfin);
        ll der = query(nodo*2+1,med+1,fin,mini,mfin);
        return izq+der;
    }
    ll query(ll ini,ll fin){
        return query(1,1,n,ini,fin);
    }

    void update(ll nodo, ll ini, ll fin , ll mini,ll v){
        if(ini>mini || fin < mini)return;
        if(ini==fin){tree[nodo] = v;return;}
        
        ll med = (ini+fin)/2;
        update(nodo*2,1,med,mini,v);
        update(nodo*2+1,med+1,fin,mini,v);

        tree[nodo] = tree[nodo*2] + tree[nodo*2+1];
    }

    void update(ll pos, ll v){
        update(1,1,n,pos,v);
    }
};
void solve(){
    ll n,m,k,op,l,r;
    cin>>n>>k;
    vll datos(n+1);
    fore(i,1,n)cin>>datos[i];
    SegmentTree ST(n);
    ST.build(datos);

    while(k--){
        cin>>op>>l>>r;
        if(op==1){
            ST.update(l,r);
        }else{
            cout<<ST.query(l,r)<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}