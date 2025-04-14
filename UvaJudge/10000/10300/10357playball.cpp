#include <bits/stdc++.h>
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
typedef long double ld;

const ld eps = 1e-9, inf = numeric_limits<ld>::max(), pi = acos(-1);
// For use with integers, just set eps=0 and everything remains the same
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

struct point{
	ld x, y;
	point(): x(0), y(0){}
	point(ld x, ld y): x(x), y(y){}

	point operator+(const point & p) const{return point(x + p.x, y + p.y);}
	point operator-(const point & p) const{return point(x - p.x, y - p.y);}
	point operator*(const ld & k) const{return point(x * k, y * k);}
	point operator/(const ld & k) const{return point(x / k, y / k);}

	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	point operator*=(const ld & p){*this = *this * p; return *this;}
	point operator/=(const ld & p){*this = *this / p; return *this;}

	point rotate(const ld & a) const{return point(x*cos(a) - y*sin(a), x*sin(a) + y*cos(a));}
	point perp() const{return point(-y, x);}
	ld ang() const{
		ld a = atan2l(y, x); a += le(a, 0) ? 2*pi : 0; return a;
	}
	ld dot(const point & p) const{return x * p.x + y * p.y;}
	ld cross(const point & p) const{return x * p.y - y * p.x;}
	ld norm() const{return x * x + y * y;}
	ld length() const{return sqrtl(x * x + y * y);}
	point unit() const{return (*this) / length();}

	bool operator==(const point & p) const{return eq(x, p.x) && eq(y, p.y);}
	bool operator!=(const point & p) const{return !(*this == p);}
	bool operator<(const point & p) const{return le(x, p.x) || (eq(x, p.x) && le(y, p.y));}
	bool operator>(const point & p) const{return ge(x, p.x) || (eq(x, p.x) && ge(y, p.y));}
	bool half(const point & p) const{return le(p.cross(*this), 0) || (eq(p.cross(*this), 0) && le(p.dot(*this), 0));}
};

struct jugadores{
    point coord;
    ld v;
};

bool atrapable(ld x, ld y, ld t, vector<jugadores> &tipos){
    for(jugadores z:tipos){
        ld dist = (z.coord - point(x,y)).length();
        ld movimiento = z.v * t;

        if(geq(movimiento,dist))return true;
    }
    return false;
}

void solve(int n){
    vector<jugadores> tipos(n);
    fore(i,0,n-1){
        cin>>tipos[i].coord.x>>tipos[i].coord.y>>tipos[i].v;
    }

    string s;
    cin>>s;
    int m = 0;
    fore(i,6,s.size()-1){
        m*=10;
        m+=s[i]-'0';
    }

    ld a,b,c,d,e,f,g;
    fore(i,1,m){
        cout<<"Ball "<<i<<" was ";
        cin>>a>>b>>c>>d>>e>>f>>g;
        
        ld x1,x2,aux;

        aux = sqrt(b*b - (ld)4*a*c);
        x1 = (-b - aux)/(2*a);
        x2 = (-b + aux)/(2*a);

        if(ge(x1,x2))swap(x1,x2);

        if(leq(x1,0))x1 = x2;
        x1 = ceil(x1);

        ld nx,ny;
        nx = d*x1 + e;
        ny = f*x1 + g;

        if(le(nx,0) || le(ny,0)){
            cout<<"foul at ("<<nx<<","<<ny<<")\n";
            continue;
        }

        if(atrapable(nx,ny,x1,tipos)){
            cout<<"caught at ("<<nx<<","<<ny<<")\n";
        }else{
            cout<<"safe at ("<<nx<<","<<ny<<")\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n = 0;
    fore(i,8,s.size()-1){
        n*=10;
        n+=s[i]-'0';
    }

    solve(n);
}