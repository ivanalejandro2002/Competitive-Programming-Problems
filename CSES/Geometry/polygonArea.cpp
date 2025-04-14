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
typedef long long int ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

struct point{
    ll x;
    ll y;

    ll operator &(const point &otro)const {return x*otro.y - y*otro.x;}
    point operator -(const point &otro)const {return {x-otro.x , y-otro.y};}
    point operator +(const point &otro)const {return {x+otro.x , y+otro.y};}
    point operator *(const ld &k)const {return {x*k , y*k};}
    point operator /(const ld &k)const {return {x/k , y/k};}

    point(ll _x,ll _y){
        x = _x;
        y = _y;
    }
};

struct polygon{
    vector<point> coords;
    int n;

    polygon(int _n){
        n = _n;
        coords.assign(n,{0,0});
    }
    polygon(){
        coords.clear();
        n = 0;
    }

    void add(const point &v){coords.pb(v);++n;}

    ll getArea(){
        ll area = 0;
        for(int i=0;i<n;i++){
            area += coords[i].x * coords[(i+1)%n].y;
            area -= coords[i].x * coords[(i-1+n)%n].y;
        }
        return area;
    }
    void printCoords(){
        for(auto z:coords){
            cout<<"["<<z.x<<","<<z.y<<"]\n";
        }
    }
};

void solve(){
    int n,x,y;
    cin>>n;
    polygon poli;
    fore(i,1,n){
        cin>>x>>y;
        poli.add(point(x,y));
    }
    cout<<abs(poli.getArea())<<"\n";

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}