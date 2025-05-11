#include <bits/stdc++.h>
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

void solve(){
    vector<string> mens;
    string s;
    int maxL = 0;
    while(getline(cin,s)){
        mens.pb(s);
        maxL = max(maxL,(int)s.size());
    }

    fore(i,0,maxL-1){
        for(int j=mens.size()-1;j>=0;j--){
            if(i<mens[j].size())cout<<mens[j][i];
            else cout<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
}