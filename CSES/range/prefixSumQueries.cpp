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
struct node{
    ll first;
    ll second;
};
struct SegmentTree{
    vector<node> tree;
    SegmentTree(int n){
        tree.assign(3*n+2,{0,0});
    }
    
    void build(vll &nums, int nodo, int ini, int fin){
        if(ini==fin){
            tree[nodo] = {nums[ini],max(0LL,nums[ini])};
            return;
        }

        int med = (ini+fin)/2;
        build(nums,nodo*2,ini,med);
        build(nums,nodo*2+1,med+1,fin);
        tree[nodo].fi = tree[nodo*2].fi+tree[nodo*2+1].fi;
        tree[nodo].se = max(tree[nodo*2].se, tree[nodo*2+1].se+tree[nodo*2].fi);

        //cout<<nodo<<"::"<<ini<<","<<fin<<" = "<<tree[nodo].fi<<","<<tree[nodo].se<<"\n";
    }

    void build(vll &nums,int n){
        build(nums,1,1,n);
    }

    node query(int nodo, int ini, int fin, int mini, int mfin){
        if(ini>mfin || fin<mini)return {0LL,0LL};
        if(ini>=mini && fin<=mfin)return tree[nodo];

        int med = (ini+fin)/2;

        node izq= query(nodo*2,ini,med,mini,mfin);
        node der = query(nodo*2+1,med+1,fin,mini,mfin);
        ll nizq,nder;
        nizq = izq.fi+der.fi;
        nder = max(izq.se, izq.fi+der.se);
        /*cout<<ini<<"->"<<fin<<":: ";
        cout<<"izq = {"<<izq.fi<<","<<izq.se<<"}  der = {"<<der.fi<<","<<der.se<<"}\n";*/
        return {nizq,nder};
    }
    node query(int ini,int fin, int n){
        return query(1,1,n,ini,fin);
    }

    void update(int nodo, int ini, int fin, int meta,int v){
        if(ini>meta || fin<meta)return;
        if(ini==fin){
            tree[nodo] = {v,max(0,v)};
            return;
        }
        int med = (ini+fin)/2;
        update(nodo*2,ini,med,meta,v);
        update(nodo*2+1,med+1,fin,meta,v);
        tree[nodo].fi = tree[nodo*2].fi+tree[nodo*2+1].fi;
        tree[nodo].se = max(tree[nodo*2].se, tree[nodo*2+1].se+tree[nodo*2].fi);
    }

    void update(int l, int r,int n){
        update(1,1,n,l,r);
    }
};
void solve(){
    int n,m,k;
    cin>>n>>k;
    SegmentTree st(n);
    vll datos(n+1);
    fore(i,1,n)cin>>datos[i];
    st.build(datos, n);
    int op,l,r;
    while(k--){
        cin>>op>>l>>r;
        if(op==1){
            st.update(l,r,n);
        }else{
            cout<<st.query(l,r,n).se<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}