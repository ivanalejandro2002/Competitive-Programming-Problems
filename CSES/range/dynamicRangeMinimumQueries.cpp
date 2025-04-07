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
void build(vll &st, vll &nums,int nodo, int ini, int fin){
    if(ini==fin){
        st[nodo] = nums[ini];
        return;
    }
    int med = (ini+fin)/2;

    build(st,nums,nodo*2,ini,med);
    build(st,nums,nodo*2+1,med+1,fin);
    st[nodo] = min(st[nodo*2],st[nodo*2+1]);
}

ll query(vll &st,int nodo, int ini, int fin, int mini, int mfin){
    if(ini>mfin || fin<mini)return INT_MAX;
    if(ini>=mini && fin <=mfin)return st[nodo];
    int med = (ini+fin)/2;

    ll izq = query(st, nodo*2, ini,med,mini,mfin);
    ll der = query(st, nodo*2+1,med+1,fin,mini,mfin);

    return min(izq,der);
}

void update(vll &st, int nodo, int ini, int fin, int meta,int v){
    if(ini>meta || fin<meta)return;
    if(ini==fin){
        st[nodo] = v;
        return;
    }
    int med = (ini+fin)/2;
    update(st,nodo*2,ini,med,meta,v);
    update(st,nodo*2+1,med+1,fin,meta,v);

    st[nodo] = min(st[nodo*2],st[nodo*2+1]);
}
void solve(){
    int n,k,op,l,r;
    cin>>n>>k;
    vll ST(3*n+2,INT_MAX);
    vll nums(n+1);
    fore(i,1,n)cin>>nums[i];

    build(ST,nums,1,1,n);

    while(k--){
        cin>>op>>l>>r;
        if(op==1){
            update(ST,1,1,n,l,r);
        }else{
            cout<<query(ST,1,1,n,l,r)<<"\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}