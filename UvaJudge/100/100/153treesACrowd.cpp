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

using ld = long double;
const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
	ld x, y, z;
	point(): x(0), y(0), z(0){}
	point(ld x, ld y, ld z): x(x), y(y), z(z){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y, z + p.z);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y, z - p.z);}
	point operator*(const ld & k) const{return point(x * k, y * k, z * k);}
	point operator/(const ld & k) const{return point(x / k, y / k, z / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const ld & p){*this = *this * p; return *this;}
	point operator/=(const ld & p){*this = *this / p; return *this;}

	
	ld length() const{return sqrtl(x * x + y * y + z * z);}
	point unit() const{return (*this) / length();}
};

void imprime(int v){
    if(v<1000)cout<<" ";
    if(v<100)cout<<" ";
    if(v<10)cout<<" ";
    cout<<v;
}

void solve(){
    ld x,y,z;
    vector<point> puntos;
    do{
        cin>>x>>y>>z;
        if(x==0 && y==0 && z == 0)break;
        puntos.push_back({x,y,z});
    }while(x!=0 || y !=0 || z!=0);
    
    map<int,int> datos;

    fore(i,0,puntos.size()-1){
        ld menor = inf;
        fore(j,0,puntos.size()-1){
            if(i==j)continue;
            menor = min(menor, (puntos[i]-puntos[j]).length());
        }
        datos[(int)menor] ++;
    }

    fore(i,0,9)imprime(datos[i]);
    cout<<"\n";
}

int main(){
    solve();
}