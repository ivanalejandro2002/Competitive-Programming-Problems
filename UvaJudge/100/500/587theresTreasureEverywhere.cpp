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

void numeral(int &i, string &cad, ld &dx, ld &dy, int &mov){
    if(cad[i]<'0' || cad[i]>'9')return;
    mov*=10;
    mov+=cad[i]-'0';
    i++;
    numeral(i,cad,dx,dy,mov);
}
void norte(int &i, string &cad, ld &dx, ld &dy, int mov){
    if(cad[i]=='E'){
        dy+=((double)1/sqrt((ld)2))*(double)mov;
        dx+=((double)1/sqrt((ld)2))*(double)mov;
        i++;
    }else if(cad[i] == 'W'){
        dy+=((double)1/sqrt((ld)2))*(double)mov;
        dx-=((double)1/sqrt((ld)2))*(double)mov;
        i++;
    }else{
        dy+=mov;
    }
}

void sur(int &i, string &cad, ld &dx, ld &dy, int mov){
    if(cad[i]=='E'){
        dy-=((double)1/sqrt((ld)2))*(double)mov;
        dx+=((double)1/sqrt((ld)2))*(double)mov;
    }else if(cad[i] == 'W'){
        dy-=((double)1/sqrt((ld)2))*(double)mov;
        dx-=((double)1/sqrt((ld)2))*(double)mov;
    }else{
        dy-=mov;
    }
}

void parse(int &, string &, ld &, ld &);
void cambio(int &i, string &cad, ld &dx, ld &dy){
    int mov = 0;
    numeral(i,cad,dx,dy,mov);

    switch(cad[i]){
        case 'N':
            i++;
            norte(i,cad,dx,dy,mov);
            break;
        case 'S':
            i++;
            sur(i,cad,dx,dy,mov);
            break;
        case 'E':
            dx+=mov;
            i++;
            break;
        case 'W':
            dx-=mov;
            i++;
            break;
    }
    
    i++;
    parse(i,cad,dx,dy);
}

void parse(int &i, string &cad, ld &dx, ld &dy){
    if(i>=cad.size() || cad[i] == '.')return;
    cambio(i,cad,dx,dy);
}

void solve(string &cad){
    ld dx,dy;
    dx = dy = 0;
    int i= 0;

    parse(i,cad,dx,dy);
    cout<<fixed<<setprecision(3);
    cout<<"The treasure is located at ("<<dx<<","<<dy<<").\n";
    cout<<"The distance to the treasure is "<<sqrt(dx*dx+dy*dy)<<".\n";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string cad;
    int i=1;
    bool hecho = 0;
    while(getline(cin,cad)){
        if(cad[0] == 'E')break;
        hecho=1;
        cout<<"Map #"<<i<<"\n";
        solve(cad);
        cout<<"\n";
        i++;
    }
}