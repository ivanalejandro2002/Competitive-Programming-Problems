#include <bits/stdc++.h>
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

int solve(int pos, int a, int b, int c){
    int s = 360*3;

    s+= ((-a+pos+40)%40)*9;
    s+= ((b-a+40)%40)*9;
    s+= ((-c+b+40)%40)*9;

    return s;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int p,a,b,c;
    do{
        cin>>p>>a>>b>>c;
        if(p==0 && a==0 && b == 0 && c == 0)break;
        cout<<solve(p,a,b,c)<<"\n";
    }while(p!=0 || a !=0 || b!=0 || c!=0);
}