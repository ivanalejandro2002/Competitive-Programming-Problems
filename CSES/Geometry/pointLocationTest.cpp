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

struct coord{
    ll x;
    ll y;

    ll operator &(const coord &otro){
        return x*otro.y - y*otro.x;
    }

    coord operator -(coord &otro){
        return {x-otro.x , y-otro.y};
    }

    coord(ll _x,ll _y){
        x = _x;
        y = _y;
    }
};

void solve(){
    ll x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    coord p1(x1,y1);
    coord p2(x2,y2);
    coord p3(x3,y3);
    ll aux = ((p2-p1)&(p3-p1));
    cout<<aux<<"::";
    if(aux<0){
        cout<<"RIGHT\n";
    }else if(aux>0){
        cout<<"LEFT\n";
    }else{
        cout<<"TOUCH\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
}