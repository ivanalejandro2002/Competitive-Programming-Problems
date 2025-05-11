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
const ll mod = 1e9+7;

void solve(string s){
    int q;
    cin>>q;

    int n = s.size();
    vi acum(n+1);

    fore(i,1,n-1){
        if(s[i]!=s[i-1])acum[i+1]=1;
        acum[i+1] += acum[i];
    }

    int l,r;
    while(q--){
        cin>>l>>r;
        if(l>r)swap(l,r);
        l++;
        r++;
        (acum[r]-acum[l]>0)?cout<<"No\n":cout<<"Yes\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    int i=1;
    while(cin>>s){
        cout<<"Case "<<i<<":\n";
        solve(s);
        i++;
    }
}