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
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b


struct point{
    ld x;
    ld y;

    point operator -(const point &otro)const {return {x-otro.x , y-otro.y};}
    point operator +(const point &otro)const {return {x+otro.x , y+otro.y};}
    point operator *(const ld &k)const {return {x*k , y*k};}
    point operator /(const ld &k)const {return {x/k , y/k};}

    ld dot(const point & p) const{return x * p.x + y * p.y;}
	ld cross(const point & p) const{return x * p.y - y * p.x;}

    point(ld _x,ld _y){
        x = _x;
        y = _y;
    }
};

int sgn(ld x){
	if(ge(x, 0)) return 1;
	if(le(x, 0)) return -1;
	return 0;
}


bool pointInLine(const point & a, const point & v, const point & p){
	//line a+tv, point p
	return eq((p - a).cross(v), 0);
}

bool pointInSegment(const point & a, const point & b, const point & p){
	//segment ab, point p
	return pointInLine(a, b - a, p) && leq((a - p).dot(b - p), 0);
}

bool crossesRay(const point & a, const point & b, const point & p){
	return (geq(b.y, p.y) - geq(a.y, p.y)) * sgn((a - p).cross(b - p)) > 0;
}

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

    void printCoords(){
        for(auto z:coords){
            cout<<"["<<z.x<<","<<z.y<<"]\n";
        }
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

    bool pointInPerimeter(const point &p){
        for(int i = 0; i < n; i++){
            if(pointInSegment(coords[i],coords[(i+1)%n],p)){
                return true;
            }
        }
        return false;
    }
    
    int hasPoint(const point &p){
        if(pointInPerimeter(p))return -1;

        int rays = 0;
        for(int i = 0; i < n; i++){
            rays += crossesRay(coords[i],coords[(i+1) %n],p);
        }

        return (rays & 1);
    }


};

void solve(){
    int n,x,y,m;
    cin>>n>>m;
    polygon poli;
    fore(i,1,n){
        cin>>x>>y;
        poli.add(point(x,y));
    }
    fore(i,1,m){
        cin>>x>>y;
        int s = poli.hasPoint(point(x,y));
        if(s==-1)cout<<"BOUNDARY\n";
        else if(s==0)cout<<"OUTSIDE\n";
        else cout<<"INSIDE\n";
    }

}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}