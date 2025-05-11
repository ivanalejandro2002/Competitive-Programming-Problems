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

int solve(string s){
    reverse(all(s));
    ll base = 2;

    ll sol = 0;
    for(char co:s){
        sol+=(base-1)*(ll)(co-'0');
        base*=2;
    }
    return sol;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    do{
        cin>>s;
        if(s=="0")break;
        cout<<solve(s)<<"\n";
    }while(s!="0");
}