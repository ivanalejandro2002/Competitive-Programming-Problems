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

void solve(ll n,ll m){
    bool carry = 0;
    ll cont = 0;
    while(n>0 || m>0){
        ll a,b;
        a = n%10;
        b = m%10;
        a+=b;
        a+=(int)carry;
        if(a>=10)carry = 1;
        else carry = 0;
        cont+=(int)carry;

        n/=10;
        m/=10;
    }
    if(cont == 0){
        cout<<"No carry operation.\n";
    }else{
        cout<<cont<<" "<<"carry operation";
        if(cont>1)cout<<"s";
        cout<<".\n";
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,m;
    do{
        cin>>n>>m;
        if(n==0 && m==0)break;
        solve(n,m);
    }while(n!=0 || m!=0);
}